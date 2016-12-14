#include "messageclass.h"

MessageClass* MessageClass::m_pInstance = 0;

MessageClass::~MessageClass()
{
    m_pInstance = 0;
}

MessageClass* MessageClass::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new MessageClass();
    }
    
    return m_pInstance;
}

MessageClass::MessageClass()
{
}

void MessageClass::setCallInfo(CallInfoClass* cic)
{
    callInfo = cic;
}

CallInfoClass* MessageClass::getCallInfo()
{
    return callInfo;
}

void MessageClass::setCallContent(QString str)
{
    strCallContent = str;
}

QString MessageClass::getCallContent()
{
    return strCallContent;
}

void MessageClass::setCallSendDateTime(QString str)
{
    strCallSendDateTime = str;
}

QString MessageClass::getCallSendDateTime()
{
    return strCallSendDateTime;
}
