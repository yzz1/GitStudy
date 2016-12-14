#include <QFileInfo>
#include <QDateTime>
#include "UISerial.h"

UISerial::UISerial()
{
     QFileInfo serialFile("/dev/ttyO3");
    if(serialFile.exists()==false)
       {
        m_serial1= new Posix_QextSerialPort("/dev/ttyS0",QextSerialBase::Polling);            //pc端默认使用com1作为数据口
        qDebug("true,is pc duan");

        }
    else
     {
         m_serial1= new Posix_QextSerialPort("/dev/ttyO3",QextSerialBase::Polling);            //embedded默认使用com2作为数据口
         qDebug("this, is embedded d uan");
      }
    if(m_serial1->open(QIODevice::ReadWrite)==true)
         qDebug("COM is Open!");


    m_serial1->setBaudRate(BAUD19200);
    m_serial1->setDataBits(DATA_8);
    m_serial1->setParity(PAR_NONE);
    m_serial1->setStopBits(STOP_1);
    m_serial1->setFlowControl(FLOW_OFF);
    m_serial1->setTimeout(5);

    m_Buffer=new QByteArray;
    init_buffer();

}
void UISerial::init_buffer()
{
    m_Buffer->clear();
}
UISerial::~UISerial()
{
    delete m_Buffer;
}
short int UISerial::GetVerifyValue(QByteArray bytes)
{
    //qDebug()<<"需要计算的字节"+bytes.toHex();
    short int sum=0;
    for(int n=0;n<bytes.count();n++)
    {
        unsigned char uchar=(unsigned char)bytes.at(n);
        int nNumber=(int)uchar;
        //qDebug()<<"nNumber="+QString::number(nNumber);
        sum+=nNumber;
    }
    return sum;
}
void UISerial::on_Serial1_ReadDataFinished(QByteArray data)
{

    int nFrameLength=0;
    //m_Buffer=&data;
    // 帧长：除帧头以及自身之外的其他数据总字节数。 2个开始标志+命令长度
    int cmdLen2TotalcmdLen = 4;


    if(data.count()>0)
    {
        m_Buffer->append(data);
    }
    if(data.count()>0) qDebug()<<"m_buffer:"<<m_Buffer->toHex();



    while(m_Buffer->count()>0)
    {
        if(m_Buffer->count()<=6)
        {
            break;
        }
        int nHeader1= (int)(m_Buffer->at(0));
        if(nHeader1!=FRAME_HEADER_1)
        {
            //丢弃开始处错误指令头
            m_Buffer->remove(0,1);
            break;
        }
        int nHeader2=(int)(m_Buffer->at(1));
        if(nHeader2!=FRAME_HEADER_1)
        {
            //丢弃开始处错误指令头
            m_Buffer->remove(0,2);
            break;
        }
        QByteArray byte1=m_Buffer->mid(2,2);
        //提取指令长度
        nFrameLength= (int)(byte1.at(0) << 8 | byte1.at(1));
        if(m_Buffer->count()-cmdLen2TotalcmdLen>=nFrameLength)
        {
            int nLength=nFrameLength+cmdLen2TotalcmdLen;
            //提取到一条完整的指令
            QByteArray bytes=m_Buffer->mid(0,nLength);
            //校验
            short int* pVerifyValue =(short int*)bytes.mid(bytes.count()-2,2).data();
            short int nVerifyValue=htobe16(*pVerifyValue);
            short int nRealValue=GetVerifyValue(bytes.mid(2,nLength-4));
            if(nVerifyValue==nRealValue)
            {
                m_Filter1.FilterInstruction(bytes);
            }
            else
            {
                qDebug()<<"nVerifyValue!=nRealValue!!!!"<<bytes.toHex();
            }
            m_Buffer->remove(0,nLength);
        }
        else
        {       
            if( m_Buffer->size() > 60 )    m_Buffer->clear();
            break;
        }
    }
}
void UISerial::Send_NBDP_CalledReceiveIns(type_NBDP_CalledReceiveInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_CalledReceiveInstruction));

    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    qDebug()<<"Send_CalledReceiveIns="+bytes.toHex();

}
void UISerial::Send_NBDP_ConnRadioAskIns(type_connectRadioInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_connectRadioInstruction));

    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    qDebug()<<"Send_ConnectRadioInsACK="+bytes.toHex();

}
void UISerial::Send_NBDP_ConnectIns(type_NBDP_ConnectInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_ConnectInstruction));

    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());
    qDebug()<<"Send_NBDP_turnIns="+bytes.toHex();
}

void UISerial::Send_NBDP_DisconnectIns(type_NBDP_DisconnectInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_DisconnectInstruction));


    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));



    //写入串口
    m_serial1->write(bytes.data(),bytes.length());
    qDebug()<<"Send_NBDP_DisconnectInsACK="+bytes.toHex();
}

void UISerial::Send_NBDP_ScanIns(type_NBDP_ScanInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_ScanInstruction));


    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));



    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    //UILog::UIInfo("S="+bytes.toHex());
    qDebug()<<"Send_NBDP_ScanInsACK="+bytes.toHex();
}
void UISerial::Send_NBDP_HuiChe()
{
    QByteArray ba;
    ba.resize(20);

    ba[0] = 0x7e; ba[1] = 0x7e; ba[2] = 0x00;   ba[3] = 0x10; ba[4] = 0x63;
    ba[5] = 0x02; ba[6] = 0xD0; ba[7] = 0x00;   ba[8] = 0x00; ba[9] = 0x00;
    ba[10] = 0x00; ba[11] = 0x01; ba[12] = 0x01;   ba[13] = 0x00; ba[14] = 0x00;
    ba[15] = 0x70; ba[16] = 0x64; ba[17] = 0x52;   ba[18] = 0x02; ba[19] = 0x6D;

    qDebug()<<"hui che huan hang:";
     qDebug()<<"huiche="+ba.toHex();
    //写入串口
    m_serial1->write(ba.data(),ba.length());

}
void UISerial::Send_NBDP_StartFecLinkIns(type_NBDP_FECStartLinkInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_FECStartLinkInstruction));

    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));

    //写入串口
    m_serial1->write(bytes.data(),bytes.length());
    qDebug()<<"Send_NBDP_FecStartLinkIns="+bytes.toHex();

}
void UISerial::Send_NBDP_SelfCheckIns(type_NBDP_SelfCheckInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_SelfCheckInstruction));



    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    //UILog::UIInfo("S="+bytes.toHex());
    qDebug()<<"Send_NBDP_SelfCheckInsACK="+bytes.toHex();
}

void UISerial::Send_NBDP_TransmitTestIns(type_NBDP_TransmitTestInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_TransmitTestInstruction));


    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    //UILog::UIInfo("S="+bytes.toHex());
    qDebug()<<"Send_NBDP_TransmitTestInsACK="+bytes.toHex();
}

void UISerial::Send_NBDP_FollowCommunicateIns(type_NBDP_FollowCommunicateInstruction* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_FollowCommunicateInstruction));


    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());

    qDebug()<<"Send_NBDP_FollowCommunicateInsACK="+bytes.toHex();
}

void UISerial::Send_NBDP_MessageIns(type_NBDP_MessageInstruction* ins)
{
    QByteArray bytes;
    int nullCharNum=0;
    while(true)
    {
        if(ins->s_DataZhen[119-nullCharNum]!=0x00)
            break;
        nullCharNum++;
    }
    bytes.append((char*)ins,sizeof(type_NBDP_MessageInstruction)-nullCharNum);

    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());
    QByteArray tempBytes=bytes.mid(8,bytes.count()-8);  
    qDebug()<<" Send_NBDP_MessageIns="+bytes.toHex();
}
void UISerial::Send_NBDP_DeviceInfoIns(type_NBDP_ReflashDeviceInfo* ins)
{
    QByteArray bytes;
    bytes.append((char*)ins,sizeof(type_NBDP_ReflashDeviceInfo));


    //计算校验值
    short int nVerifyValue= GetVerifyValue(bytes.mid(2,bytes.count()-2));
    short int nVerifyValue1=be16toh(nVerifyValue);
    bytes.remove(bytes.count()-2,2);
    bytes.append((char*)&nVerifyValue1,sizeof(nVerifyValue1));


    //写入串口
    m_serial1->write(bytes.data(),bytes.length());
    qDebug()<<"Send_NBDP_DeviceInfo="+bytes.toHex();

}

