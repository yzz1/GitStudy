/****************************************************************************
**
** 文件名称： button.h
** 功能概述:  按钮类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "core/database/database.h"
#include <QToolButton>

typedef bool(*ClickEevent)(Database*);

class Button : public QToolButton
{
        Q_OBJECT
        
        Q_PROPERTY(QString iconName READ iconName WRITE setIconName)
    public:
        explicit Button(QWidget* parent = 0);
        Button(const QString& iconName, const QString& textLabel, QWidget* parent = 0);
        
        void setIconName(const QString& iconName);
        QString iconName() const;
        
        ClickEevent onClick;
        
    signals:
    
    public slots:
    
    protected:
        void mousePressEvent(QMouseEvent*);
        void mouseReleaseEvent(QMouseEvent*);
        void enterEvent(QEvent*);
        void focusInEvent(QFocusEvent*);
        void focusOutEvent(QFocusEvent*);
        
    private:
        QString m_iconName;
        
    signals:
        void buttonClicked();
};

#endif // BUTTON_H
