#include "commonutils.h"
/****************************************************************************
**
** 函数名称：CommonUtils::wordwrap
** 功能概述: 限制字符串长度
** 参数说明：
** 作成日期：20151113
** 作成者：  HSCN
** 修改日期：20151113
** 修改者：  HSCN
**
****************************************************************************/
QString CommonUtils::wordwrap(const QString& value, const int size)
{
    if (value.length() <= size)
    {
        return value;
    }
    
    QString result = "";
    
    for (int pos = 0; pos < value.length()  ; pos  += size)
    {
        if (pos  >=  value.length() - size)
        {
            result.append(value.mid(pos, value.length()  - pos));
        }
        else
        {
            result.append(value.mid(pos, size)).append("\n");
        }
    }
    
    return result;
}
