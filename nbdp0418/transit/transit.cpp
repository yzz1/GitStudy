#include "transit.h"


Transit* Transit::m_pInstance = 0;

/****************************************************************************
**
** Transit::~Transit
** 功能概述: 析构函数
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Transit::~Transit()
{
    m_pInstance = 0;
}

/****************************************************************************
**
** Transit::get()
** 功能概述: 取得单例
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Transit* Transit::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new Transit();
    }
    
    return m_pInstance;
}

/****************************************************************************
**
** Transit::get()
** 功能概述: 构造函数
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
Transit::Transit()
{
}


/****************************************************************************
**
** Transit::EmitSignalState(QString str)
** 功能概述: 发送信号状态变更信号
** 参数说明: QString str 信号类型
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalState(QString str)
{
    emit SignalState(str);
}

/****************************************************************************
**
** Transit::EmitSignalCallSetup(CallClass* cc)
** 功能概述: 发送呼叫信号
** 参数说明: CallClass* cc 呼叫信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalCallSetup(CallClass* cc)
{
    emit SignalCallSetup(cc);
}

/****************************************************************************
**
** Transit::EmitSignalTurningResult(bool b)
** 功能概述: 发送调谐结果信号
** 参数说明: bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalTurningResult(bool b)
{
    emit SignalTurningResult(b);
}

/****************************************************************************
**
** Transit::EmitSignalConnectingWait(bool b)
** 功能概述: 发送建链等待结果信号
** 参数说明: bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalConnectingWait(bool b)
{
    emit SignalConnectingWait(b);
}

/****************************************************************************
**
** Transit::EmitSignalConnectingResult(bool b)
** 功能概述: 发送建链结果信号
** 参数说明: bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalConnectingResult(bool b)
{
    emit SignalConnectingResult(b);
}

/****************************************************************************
**
** Transit::EmitSignalConnectingCancel(bool b)
** 功能概述: 发送取消建链信号
** 参数说明: bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalConnectingCancel()
{
    emit SignalConnectingCancel();
}

/****************************************************************************
**
** Transit::EmitSignalTalkSend(QString strNo, QString strMsg)
** 功能概述: 发送通话下发信号
** 参数说明: QString strNo 消息ID
             QString strMsg 消息内容
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalTalkSend(QString strNo, QString strMsg)
{
    emit SignalTalkSend(strNo, strMsg);
}

/****************************************************************************
**
** Transit::EmitSignalTalkSendConfirm(QString strNo, bool b)
** 功能概述: 发送通话下发回执信号
** 参数说明: QString strNo 消息ID
             bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalTalkSendConfirm(QString strNo, bool b)
{
    emit SignalTalkSendConfirm(strNo, b);
}

/****************************************************************************
**
** Transit::EmitSignalTalkReceive(QString str)
** 功能概述: 发送接收消息信号
** 参数说明: QString str 消息内容
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalTalkReceive(QString str)
{
    emit SignalTalkReceive(str);
}

/****************************************************************************
**
** Transit::EmitSignalInterupt(bool b)
** 功能概述: 发送ESC中断信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalInterupt()
{
    emit SignalInterupt();
}

/****************************************************************************
**
** Transit::EmitSignalInteruptConfirm(bool b)
** 功能概述: 发送ESC中断回执信号
** 参数说明: bool b 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalInteruptConfirm(bool b)
{
    emit SignalInteruptConfirm(b);
}

/****************************************************************************
**
** Transit::EmitSignalInteruptDSC()
** 功能概述: 发送DSC中断信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalInteruptDSC()
{
    emit SignalInteruptDSC();
}

/****************************************************************************
**
** Transit::EmitSignalInteruptComu()
** 功能概述: 发送Comu中断信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalInteruptComu()
{
    emit SignalInteruptComu();
}

/****************************************************************************
**
** Transit::EmitSignalScan(ScanClass* sc)
** 功能概述: 发送开始扫描信号
** 参数说明: ScanClass* sc 扫描信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalScan(ScanClass* sc)
{
    emit SignalScan(sc);
}

/****************************************************************************
**
** Transit::EmitSignalScanData(CallInfoClass* cic)
** 功能概述: 发送扫描结果信号
** 参数说明: CallInfoClass* cic 扫描结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalScanData(CallInfoClass* cic)
{
    emit SignalScanData(cic);
}

/****************************************************************************
**
** Transit::EmitSignalCheck()
** 功能概述: 发送系统自检信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalCheck()
{
    emit SignalCheck();
}

/****************************************************************************
**
** Transit::EmitSignalCheckData(CheckDataClass* cdc)
** 功能概述: 发送自检信息信号
** 参数说明: CheckDataClass* cdc 自检信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalCheckData(CheckDataClass* cdc)
{
    emit SignalCheckData(cdc);
}

/****************************************************************************
**
** Transit::EmitSignalMarkTrans()
** 功能概述: 发送Mark传递信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalMarkTrans()
{
    emit SignalMarkTrans();
}

/****************************************************************************
**
** Transit::EmitSignalSpaceTrans()
** 功能概述: 发送Space传递信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalSpaceTrans()
{
    emit SignalSpaceTrans();
}

/****************************************************************************
**
** Transit::EmitSignalDotTrans()
** 功能概述: 发送Dot传递信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalDotTrans()
{
    emit SignalDotTrans();
}

/****************************************************************************
**
** Transit::EmitSignalSlaveDelay(int i)
** 功能概述: 发送SlaveDelay信号
** 参数说明: int i 延时秒数
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalSlaveDelay(int i)
{
    emit SignalSlaveDelay(i);
}

/****************************************************************************
**
** Transit::EmitSignalShutDown()
** 功能概述: 发送关机信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalShutDown()
{
    emit SignalShutDown();
}

/****************************************************************************
**
** Transit::EmitSignalMessageEnd()
** 功能概述: 发送通信结束指令(break)信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalMessageEnd()
{
    emit SignalMessageEnd();
}

/****************************************************************************
**
** Transit::EmitSignalRadioConnectAsk()
** 功能概述: 发送电台连接确认信号
** 参数说明:
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalRadioConnectAsk()
{
    emit SignalRadioConnectAsk();
}

/****************************************************************************
**
** Transit::EmitSignalRadioConnectAnswer(bool ret)
** 功能概述: 发送电台连接确认结果信号
** 参数说明: bool ret 处理结果
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalRadioConnectAnswer(bool ret)
{
    emit SignalRadioConnectAnswer(ret);
}

/****************************************************************************
**
** Transit::EmitSignalDSCfollowComm(CallInfoClass* cic)
** 功能概述: 发送DSC后续通信信号
** 参数说明: CallInfoClass* cic 通话信息
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
void Transit::EmitSignalDSCfollowComm(CallInfoClass* cic)
{
    emit SignalDSCfollowComm(cic);
}
void Transit::EmitSignalKillSendScanFreqTimer()
{
    emit SignalKillSendScanFreqTimer();
}
void Transit::EmitSignalLineEditState(bool b)
{
    emit SignalLineEditState(b);
}
void Transit::EmitSignalCalledReceive(int calledType)
{
    emit SignalCalledReceive(calledType);
}
void Transit::EmitSignalJianLianEnterReady()
{
  emit SignalJianLianEnterReady();
}
//YZZ
void Transit::EmitSignalReflashMMSISignal(QString strMMSI)
{
    emit reflashSignal(strMMSI);
}
void Transit::EmitSignalReflashCallModeSignal(QString strCallMode)
{
    emit reflashCallModeSignal(strCallMode);
}
void Transit::EmitSignalReflashDeviceInfo(QString four, QString nine, QString answerCode)
{
    emit reflashDeviceInfo( four, nine, answerCode);
}
