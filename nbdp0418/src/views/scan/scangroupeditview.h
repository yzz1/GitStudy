/****************************************************************************
**
** 文件名称： scangroupeditview.h
** 功能概述:  扫描频率编辑界面类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef SCANGROUPEDITVIEW_H
#define SCANGROUPEDITVIEW_H

#include <QWidget>
#include <QMap>
class FrequencyScanData
{
    public :
        QString strTx;
        QString strRx;
        QString scanFlag;
        bool display;//显示状态
        void clear();
};
namespace Ui
{
    class ScanGroupEditView;
}

class ScanGroupEditView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit ScanGroupEditView(QWidget* parent = 0);
        ~ScanGroupEditView();
        
    signals:
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        
    public  slots:
        void frontPageSlot(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void  homeClickedSlot();
        void okButtonClickedSlot();
        void cancelButtonClickedSlot();
        void arrowUpButtonClicked();
        void arrowDownButtonClicked();
        void pushButtonClickedSlot();
        void activatedSlot(const QString& str);
        //void exitEditSlot();
        
    private:
        Ui::ScanGroupEditView* ui;
        QString m_strModle;		//保存编辑或新建模式标记
        QMap <QString, QString> m_stationMap;
        QList<FrequencyScanData> m_list;	//保存频率组的缓存
        bool eventFilter(QObject* watched, QEvent* event);
        bool m_editmode;			//频率编辑标记
};

#endif // SCANGROUPEDITVIEW_H
