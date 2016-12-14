#ifndef SCANGROUPVIEW_H
#define SCANGROUPVIEW_H

#include <QWidget>
/****************************************************************************
**
** 文件名称： scangroupview.h
** 功能概述:  扫描界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#include "models/contactsmodel.h"
#include "transit.h"
namespace Ui
{
    class ScanGroupView;
}

class ScanGroupFrequency
{
    public :
        QString strTx;
        QString strRx;
        QString scanFlag;
};
class ScanGroupView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ScanGroupView(QWidget* parent = 0);
        ~ScanGroupView();
        
    private:
        Ui::ScanGroupView* ui;
        ContactsModel* m_model;   //数据模型
        bool eventFilter(QObject* watched, QEvent* event);
        QList<ScanGroupFrequency> m_list;	//保存频率组
        int m_recordCount;			//频率记录数
        bool m_display[20];			//显示标记
        ScanClass* m_sc;			//扫描处理下发数据
        
    signals:
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  arrowDownButtonClicked();
        void  arrowUpButtonClicked();
        void deleteSelectedRow();
        void editClickedSolt();
        void  newClickedSolt();
        void  homeClickedSlot();
        void  startClickedSolt();
        void currentChangedSlot(const QModelIndex& current, const QModelIndex& previous);
};

#endif // SCANGROUPVIEW_H
