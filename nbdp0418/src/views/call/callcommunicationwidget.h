/****************************************************************************
**
** 文件名称： callcommunicationwidget.h
** 功能概述:  call通讯对话框类
** 版本号：   1.0
** 作成日期： 20151113
** 作成者：   HSCN
** 修改日期： 20151113
** 修改者：   HSCN
**
****************************************************************************/
#ifndef CALLCOMMUNICATIONWIDGET_H
#define CALLCOMMUNICATIONWIDGET_H

#include <QWidget>
#include "models/managermodel.h"
#include "models/managerloadfilemodel.h"
#include "models/managerdelegate.h"

namespace Ui
{
    class CallCommunicationwidget;
}

class CallCommunicationwidget : public QWidget
{
        Q_OBJECT
        
    public:
        explicit CallCommunicationwidget(QWidget* parent = 0);
        ~CallCommunicationwidget();
        void init(QString& table);
        bool eventFilter(QObject* watched, QEvent* event);
        QString dataBack();
        
    signals :
        void afterPageSignal(QString thisID, QString fowordID, QMap<QString, QString>paraMap);
        void okButtonClickedSignal();
        
    private:
        Ui::CallCommunicationwidget* ui;
        ManagerModel* m_model;   //数据模型
        ManagerModel* m_model_2;
        ManagerLoadFileModel* m_model_3;
        ManagerLoadFileModel* m_model_4;
        ManagerDelegate* m_managerDelegate; //数据托管
        ManagerDelegate* m_managerDelegate2;
        ManagerDelegate* m_macroDelegate;
        ManagerDelegate* m_macroDelegate2;
        ManagerDelegate* m_phraseBookDelegate;
        ManagerDelegate* m_phraseBookDelegate2;
        ManagerDelegate* m_fileDelegate;
        ManagerDelegate* m_fileDelegate2;
        CallCommunicationStyle* m_callCommunicationStyle;
        CallFileStyle* m_callFileStyle;
        CallPhraseBookStyle* m_callPhraseBookStyle;
        QString m_str;	//选择的数据
        QString m_table;	//选择的数据库
        
    public slots:
        void  okButtonClickedSlot();
};

#endif // CALLCOMMUNICATIONWIDGET_H
