/****************************************************************************
**
** 文件名称： callinfoclass.h
** 功能概述: 呼叫信息类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SCANDATACLASS_H
#define SCANDATACLASS_H

#include <QString>

class CallInfoClass
{
    public:
        CallInfoClass();
        void setCallName(QString str);
        QString getCallName();
        void setCallCode(QString str);
        QString getCallCode();
        void setCallChannel(QString str);
        QString getCallChannel();
        void setCallTx(QString str);
        QString getCallTx();
        void setCallRx(QString str);
        QString getCallRx();
        void setCallType(QString str);
        QString getCallType();
        void setCallOrReceive(QString val);
        QString getCallOrReceive();
        
    private:
        QString strCallName;                // 呼叫人名
        QString strCallCode;                // 呼叫代码
        QString strCallChannel;             // 呼叫频道
        QString strCallTx;                  // 发送频率
        QString strCallRx;                  // 接收频率
        QString strCallType;                // 通信模式
        QString callOrReceive;              // 呼叫类型 CALL:"1"，RECEIVE:"0"
};

#endif // SCANDATACLASS_H
