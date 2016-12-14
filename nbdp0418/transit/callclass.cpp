#include "callclass.h"

CallClass* CallClass::m_pInstance = 0;

CallClass::~CallClass()
{
    m_pInstance = 0;
}

CallClass* CallClass::get()
{
    if (0 == m_pInstance)
    {
        m_pInstance = new CallClass();
    }
    
    return m_pInstance;
}

CallClass::CallClass()
{
    setIsScan(false); //默认非扫描状态
}
void CallClass::setIsScan(bool b)
{
    isScan=b;
}
bool CallClass::getIsScan()
{
    return isScan;
}
void CallClass::setCallInfo(CallInfoClass* cic)
{
    callInfo = cic;
}

CallInfoClass* CallClass::getCallInfo()
{
    return callInfo;
}

void CallClass::setIsCall(bool b)
{
    isCall = b;
}

bool CallClass::getIsCall()
{
    return isCall;
}
