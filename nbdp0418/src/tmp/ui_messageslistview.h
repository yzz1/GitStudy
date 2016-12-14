/********************************************************************************
** Form generated from reading UI file 'messageslistview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESLISTVIEW_H
#define UI_MESSAGESLISTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MessagesListView
{
public:
    TitleWidget *contactsTiltewidget;
    QPushButton *arrowDownButton;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *outBoxTBnt;
    QToolButton *inBoxTBnt;
    QFrame *Contactsline;
    QPushButton *arrowUpButton;
    QPushButton *selectBnt;
    QPushButton *selectallBnt;
    QPushButton *openBnt;
    QPushButton *exportBnt;
    QPushButton *deleteBnt;
    QTableView *tableView;

    void setupUi(QWidget *MessagesListView)
    {
        if (MessagesListView->objectName().isEmpty())
            MessagesListView->setObjectName(QString::fromUtf8("MessagesListView"));
        MessagesListView->resize(800, 544);
        MessagesListView->setStyleSheet(QString::fromUtf8(""));
        contactsTiltewidget = new TitleWidget(MessagesListView);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 0, 800, 45));
        arrowDownButton = new QPushButton(MessagesListView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-image: url(:/images/Arrow_down_white);"));
        controlWidget = new QWidget(MessagesListView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeTBnt = new QToolButton(controlWidget);
        homeTBnt->setObjectName(QString::fromUtf8("homeTBnt"));
        homeTBnt->setGeometry(QRect(80, 0, 141, 61));
        homeTBnt->setFocusPolicy(Qt::NoFocus);
        homeTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Active, QIcon::On);
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        outBoxTBnt = new QToolButton(controlWidget);
        outBoxTBnt->setObjectName(QString::fromUtf8("outBoxTBnt"));
        outBoxTBnt->setGeometry(QRect(640, 0, 131, 61));
        outBoxTBnt->setFocusPolicy(Qt::NoFocus);
        outBoxTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/message_outBox_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/message_outBox_SelNo.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/message_outBox_SelYes.png"), QSize(), QIcon::Selected, QIcon::On);
        outBoxTBnt->setIcon(icon1);
        outBoxTBnt->setIconSize(QSize(28, 26));
        outBoxTBnt->setPopupMode(QToolButton::DelayedPopup);
        outBoxTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        inBoxTBnt = new QToolButton(controlWidget);
        inBoxTBnt->setObjectName(QString::fromUtf8("inBoxTBnt"));
        inBoxTBnt->setGeometry(QRect(450, 0, 151, 61));
        inBoxTBnt->setFocusPolicy(Qt::NoFocus);
        inBoxTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"	font: 18pt \"Ubuntu\";\n"
"    \n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/message_inBox_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/images/message_inBox_SelYes.png"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/images/message_inBox_SelNo.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/images/message_inBox_SelYes.png"), QSize(), QIcon::Selected, QIcon::On);
        inBoxTBnt->setIcon(icon2);
        inBoxTBnt->setIconSize(QSize(28, 25));
        inBoxTBnt->setPopupMode(QToolButton::DelayedPopup);
        inBoxTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Contactsline = new QFrame(MessagesListView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(MessagesListView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-image: url(:/images/Arrow_up_white);"));
        selectBnt = new QPushButton(MessagesListView);
        selectBnt->setObjectName(QString::fromUtf8("selectBnt"));
        selectBnt->setGeometry(QRect(160, 420, 85, 36));
        selectBnt->setFocusPolicy(Qt::NoFocus);
        selectBnt->setAutoFillBackground(false);
        selectBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        selectBnt->setCheckable(true);
        selectallBnt = new QPushButton(MessagesListView);
        selectallBnt->setObjectName(QString::fromUtf8("selectallBnt"));
        selectallBnt->setGeometry(QRect(20, 420, 121, 36));
        selectallBnt->setFocusPolicy(Qt::NoFocus);
        selectallBnt->setAutoFillBackground(false);
        selectallBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        selectallBnt->setCheckable(true);
        openBnt = new QPushButton(MessagesListView);
        openBnt->setObjectName(QString::fromUtf8("openBnt"));
        openBnt->setGeometry(QRect(460, 420, 81, 36));
        openBnt->setFocusPolicy(Qt::NoFocus);
        openBnt->setAutoFillBackground(false);
        openBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        openBnt->setCheckable(true);
        exportBnt = new QPushButton(MessagesListView);
        exportBnt->setObjectName(QString::fromUtf8("exportBnt"));
        exportBnt->setGeometry(QRect(680, 420, 85, 36));
        exportBnt->setFocusPolicy(Qt::NoFocus);
        exportBnt->setAutoFillBackground(false);
        exportBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        exportBnt->setCheckable(true);
        deleteBnt = new QPushButton(MessagesListView);
        deleteBnt->setObjectName(QString::fromUtf8("deleteBnt"));
        deleteBnt->setGeometry(QRect(570, 420, 85, 36));
        deleteBnt->setFocusPolicy(Qt::NoFocus);
        deleteBnt->setAutoFillBackground(false);
        deleteBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"color: rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        deleteBnt->setCheckable(true);
        tableView = new QTableView(MessagesListView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 40, 800, 331));
        tableView->setFocusPolicy(Qt::StrongFocus);
        tableView->setStyleSheet(QString::fromUtf8(" color: gray;\n"
"background: transparent;\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
" border:none;\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(true);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);

        retranslateUi(MessagesListView);

        QMetaObject::connectSlotsByName(MessagesListView);
    } // setupUi

    void retranslateUi(QWidget *MessagesListView)
    {
        MessagesListView->setWindowTitle(QApplication::translate("MessagesListView", "Form", 0, QApplication::UnicodeUTF8));
        arrowDownButton->setText(QString());
        homeTBnt->setText(QApplication::translate("MessagesListView", "&Home", 0, QApplication::UnicodeUTF8));
        outBoxTBnt->setText(QApplication::translate("MessagesListView", "&OutBox", 0, QApplication::UnicodeUTF8));
        inBoxTBnt->setText(QApplication::translate("MessagesListView", "&InBox", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        selectBnt->setText(QApplication::translate("MessagesListView", "Se&lect", 0, QApplication::UnicodeUTF8));
        selectallBnt->setText(QApplication::translate("MessagesListView", "&Select all", 0, QApplication::UnicodeUTF8));
        openBnt->setText(QApplication::translate("MessagesListView", "O&pen", 0, QApplication::UnicodeUTF8));
        exportBnt->setText(QApplication::translate("MessagesListView", "&Export", 0, QApplication::UnicodeUTF8));
        deleteBnt->setText(QApplication::translate("MessagesListView", "&Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessagesListView: public Ui_MessagesListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESLISTVIEW_H
