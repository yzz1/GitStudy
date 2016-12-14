/****************************************************************************
**
** 文件名称： inputcheck.h
** 功能概述:  输入校验类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef INTPUTCHECK_H
#define INTPUTCHECK_H
#include <QString>

class IntputCheck
{
    public:
        IntputCheck();
        bool checkStr(QString& str);
        
    private:
        QString m_check;
        int m_len;
};

#endif // INTPUTCHECK_H
