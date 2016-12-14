/****************************************************************************
**
** 文件名称： callinfo.h
** 功能概述: 通话信息类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CALLCLASS_H
#define CALLCLASS_H

#include <QString>
#include "callinfoclass.h"

class CallClass
{
    public:
        static CallClass*  get();
        ~CallClass();
        void setCallInfo(CallInfoClass* cic);
        CallInfoClass* getCallInfo();
        void setIsCall(bool b);
        bool getIsCall();
        void setIsScan(bool b);
        bool getIsScan();
    private:
        CallClass();
        static CallClass* m_pInstance;
        CallInfoClass* callInfo; // 呼叫信息
        bool isCall; // 是否呼叫
        bool isScan; //是否为扫描被呼叫
};

#endif // CALLCLASS_H
