#include "callinfoclass.h"

CallInfoClass::CallInfoClass()
{
}

void CallInfoClass::setCallName(QString str)
{
    strCallName = str;
}

QString CallInfoClass::getCallName()
{
    return strCallName;
}

void CallInfoClass::setCallCode(QString str)
{
    strCallCode = str;
}

QString CallInfoClass::getCallCode()
{
    return strCallCode;
}

void CallInfoClass::setCallChannel(QString str)
{
    strCallChannel = str;
}

QString CallInfoClass::getCallChannel()
{
    return strCallChannel;
}

void CallInfoClass::setCallTx(QString str)
{
    strCallTx = str;
}

QString CallInfoClass::getCallTx()
{
    return strCallTx;
}

void CallInfoClass::setCallRx(QString str)
{
    strCallRx = str;
}

QString CallInfoClass::getCallRx()
{
    return strCallRx;
}

void CallInfoClass::setCallType(QString str)
{
    strCallType = str;
}

QString CallInfoClass::getCallType()
{
    return strCallType;
}

void CallInfoClass::setCallOrReceive(QString val)
{
    callOrReceive = val;
}

QString CallInfoClass::getCallOrReceive()
{
    return callOrReceive;
}
