/****************************************************************************
**
** 文件名称： manualfrequencyview.h
** 功能概述:  call手动输入联系人界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef MANUALFREQUENCYVIEW_H
#define MANUALFREQUENCYVIEW_H

#include <QWidget>
#include <QMap>

class MainWindow;
namespace Ui
{
    class ManualFrequencyView;
}

class ManualFrequencyView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ManualFrequencyView(QWidget* parent = 0);
        ~ManualFrequencyView();
        
    private:
        Ui::ManualFrequencyView* ui;
        bool m_callOrReceive;		//主叫被叫模式
        bool eventFilter(QObject* watched, QEvent* event);
        bool m_editmode;
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public slots:
        void  homeClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void  frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void receiveButtonClickedSlot();
        void callButtonClickedSlot();
        
};
extern MainWindow* g_mainWorkFlow;
#endif // MANUALFREQUENCYVIEW_H
