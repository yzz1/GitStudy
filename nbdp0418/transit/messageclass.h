/****************************************************************************
**
** 文件名称： meessageclass.h
** 功能概述: 消息类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MESSAGECLASS_H
#define MESSAGECLASS_H

#include <QString>
#include "callinfoclass.h"

class MessageClass
{
    public:
        static MessageClass*  get();
        ~MessageClass();
        void setCallInfo(CallInfoClass* cic);
        CallInfoClass* getCallInfo();
        void setCallContent(QString str);
        QString getCallContent();
        void setCallSendDateTime(QString str);
        QString getCallSendDateTime();
    private:
        MessageClass();
        static MessageClass* m_pInstance;
        CallInfoClass* callInfo;            // 呼叫信息
        QString strCallContent;             // 消息内容
        QString strCallSendDateTime;        // 发送时刻
};

#endif // MESSAGECLASS_H
