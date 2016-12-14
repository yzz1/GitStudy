/****************************************************************************
**
** 文件名称： frequencyinput.h
** 功能概述:  频率输入控件类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef FREQUENCYINPUT_H
#define FREQUENCYINPUT_H

#include <QWidget>

namespace Ui
{
    class FrequencyInput;
}

class FrequencyInput : public QWidget
{
        Q_OBJECT
        
    public:
        explicit FrequencyInput(QWidget* parent = 0);
        ~FrequencyInput();
        void openEditmode(bool txOrRx = true);
        void offEditmode(bool save = true);
        void widgetSetFocus();
        void widgetCleanFocus();
        QString getData();
        void setData(QString str);
        void editDataClean();
        
    private:
        Ui::FrequencyInput* ui;
        bool eventFilter(QObject* watched, QEvent* event);
        int editNum;
        bool m_editMode;
        bool m_txOrRx;
        QString m_oldStr;
        QString  getText();
};

#endif // FREQUENCYINPUT_H
