#include "intputcheck.h"
#include <QDebug>
/****************************************************************************
**
** 函数名称：IntputCheck::IntputCheck
** 功能概述: 初始化
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
IntputCheck::IntputCheck()
{
    m_check += "≡←↑↓△□abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-?:*@().,'=/+ ";
    m_check += '\n';
    m_check += '\r';
    m_check += '\t';
    m_len = m_check.length();
}
/****************************************************************************
**
** 函数名称：IntputCheck::checkStr
** 功能概述: 校验字符串
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
bool IntputCheck::checkStr(QString& str)
{
    for (int n = 0; n < str.length(); n++)
    {
        for (int i = 0; i < m_len; i++)
        {
            if (m_check[i] == str[n])
                break;
                
            if (i + 1 >= m_len)
            {
                return false;
            }
        }
    }
    
    return true;
}

