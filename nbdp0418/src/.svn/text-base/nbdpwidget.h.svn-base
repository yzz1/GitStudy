#ifndef NbdpView_H
#define NbdpView_H

#include <QSplitter>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include <QSettings>
#include <QDateTime>
#include <QLabel>
#include <QCloseEvent>
#include <QStackedWidget>
#include <QSplitterHandle>
#include <QPainter>
#include <QVBoxLayout>
#include <QStackedWidget>

#include "views/common/baseview.h"
#include "views/common/statuswidget.h"
#include "views/home/homeview.h"
#include "views/call/callview.h"
#include "views/contacts/contactsview.h"
#include "views/common/controlwidget.h"

class NbdpView : public BaseWidget
{
        Q_OBJECT
        Q_PROPERTY(QString backPix READ backPix WRITE setBackPix DESIGNABLE true SCRIPTABLE true)
        
    public:
        explicit NbdpView(QWidget* parent = 0);
        ~NbdpView();
        
        const QString& backPix()
        {
            return m_backgroundPix;
        }
        
        void setBackPix(const QString& backPix);
        
        void closeEvent(QCloseEvent* event);
    protected:
        void paintEvent(QPaintEvent* event);
    private:
        QVBoxLayout* m_mainLayout;
        StatusWidget* m_statusWidget;
        ControlWidget* m_controlWidget;
        HomeWidget* m_homeWidget;
        QString m_backgroundPix;
        QStackedWidget*  m_stackWidget;
        
        CallWidget* m_callWidget;
        ContactsWidget* m_contactsWidget;
    private slots:
        void forward(int index);
        void forward2(int index);
};

#endif // NbdpView_H
