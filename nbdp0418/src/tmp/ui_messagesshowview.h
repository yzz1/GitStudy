/********************************************************************************
** Form generated from reading UI file 'messagesshowview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGESSHOWVIEW_H
#define UI_MESSAGESSHOWVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MessagesShowView
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
    QPushButton *copyBnt;
    QPushButton *printBnt;
    QPushButton *closeBnt;
    QFrame *upline;
    QFrame *rightline;
    QLabel *namelabel;
    QLabel *txlabel;
    QLabel *rxlabel;
    QLabel *callmode;
    QLabel *name;
    QLabel *tx;
    QLabel *rx;
    QTableView *tableView;

    void setupUi(QWidget *MessagesShowView)
    {
        if (MessagesShowView->objectName().isEmpty())
            MessagesShowView->setObjectName(QString::fromUtf8("MessagesShowView"));
        MessagesShowView->resize(800, 544);
        MessagesShowView->setStyleSheet(QString::fromUtf8(""));
        contactsTiltewidget = new TitleWidget(MessagesShowView);
        contactsTiltewidget->setObjectName(QString::fromUtf8("contactsTiltewidget"));
        contactsTiltewidget->setGeometry(QRect(0, 0, 800, 45));
        arrowDownButton = new QPushButton(MessagesShowView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        controlWidget = new QWidget(MessagesShowView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeTBnt = new QToolButton(controlWidget);
        homeTBnt->setObjectName(QString::fromUtf8("homeTBnt"));
        homeTBnt->setGeometry(QRect(80, 0, 141, 61));
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
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        outBoxTBnt = new QToolButton(controlWidget);
        outBoxTBnt->setObjectName(QString::fromUtf8("outBoxTBnt"));
        outBoxTBnt->setGeometry(QRect(640, 0, 131, 61));
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
        Contactsline = new QFrame(MessagesShowView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 1));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        arrowUpButton = new QPushButton(MessagesShowView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        copyBnt = new QPushButton(MessagesShowView);
        copyBnt->setObjectName(QString::fromUtf8("copyBnt"));
        copyBnt->setGeometry(QRect(120, 420, 81, 36));
        copyBnt->setFocusPolicy(Qt::NoFocus);
        copyBnt->setAutoFillBackground(false);
        copyBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"	color: rgb(105, 115, 119);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        copyBnt->setCheckable(true);
        printBnt = new QPushButton(MessagesShowView);
        printBnt->setObjectName(QString::fromUtf8("printBnt"));
        printBnt->setGeometry(QRect(470, 420, 81, 36));
        printBnt->setFocusPolicy(Qt::NoFocus);
        printBnt->setAutoFillBackground(false);
        printBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"	color: rgb(105, 115, 119);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        printBnt->setCheckable(true);
        closeBnt = new QPushButton(MessagesShowView);
        closeBnt->setObjectName(QString::fromUtf8("closeBnt"));
        closeBnt->setGeometry(QRect(630, 420, 85, 36));
        closeBnt->setFocusPolicy(Qt::NoFocus);
        closeBnt->setAutoFillBackground(false);
        closeBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"	color: rgb(105, 115, 119);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        closeBnt->setCheckable(true);
        upline = new QFrame(MessagesShowView);
        upline->setObjectName(QString::fromUtf8("upline"));
        upline->setGeometry(QRect(0, 210, 121, 41));
        upline->setFrameShape(QFrame::HLine);
        upline->setFrameShadow(QFrame::Sunken);
        rightline = new QFrame(MessagesShowView);
        rightline->setObjectName(QString::fromUtf8("rightline"));
        rightline->setGeometry(QRect(119, 22, 1, 391));
        rightline->setLineWidth(1);
        rightline->setFrameShape(QFrame::VLine);
        rightline->setFrameShadow(QFrame::Sunken);
        namelabel = new QLabel(MessagesShowView);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(20, 50, 101, 41));
        namelabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/message_call_pepole_84_96.png);\n"
""));
        txlabel = new QLabel(MessagesShowView);
        txlabel->setObjectName(QString::fromUtf8("txlabel"));
        txlabel->setGeometry(QRect(30, 250, 60, 40));
        txlabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 25pt \"Ubuntu\";\n"
"background: transparent;"));
        txlabel->setAlignment(Qt::AlignCenter);
        rxlabel = new QLabel(MessagesShowView);
        rxlabel->setObjectName(QString::fromUtf8("rxlabel"));
        rxlabel->setGeometry(QRect(30, 320, 60, 50));
        rxlabel->setLayoutDirection(Qt::LeftToRight);
        rxlabel->setAutoFillBackground(false);
        rxlabel->setStyleSheet(QString::fromUtf8("font: 25pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"background: transparent;"));
        rxlabel->setAlignment(Qt::AlignCenter);
        rxlabel->setTextInteractionFlags(Qt::NoTextInteraction);
        callmode = new QLabel(MessagesShowView);
        callmode->setObjectName(QString::fromUtf8("callmode"));
        callmode->setGeometry(QRect(-1, 170, 121, 51));
        callmode->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);\n"
"background: transparent;\n"
"font-weight:bold;"));
        callmode->setAlignment(Qt::AlignCenter);
        name = new QLabel(MessagesShowView);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(0, 100, 121, 81));
        name->setStyleSheet(QString::fromUtf8("color: rgb(251, 244, 244);\n"
"color: rgb(255, 255, 255);\n"
"background: transparent;\n"
"font: 15pt \"Ubuntu\";\n"
"\n"
""));
        name->setAlignment(Qt::AlignCenter);
        tx = new QLabel(MessagesShowView);
        tx->setObjectName(QString::fromUtf8("tx"));
        tx->setGeometry(QRect(0, 290, 121, 40));
        tx->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background: transparent;\n"
"font: 12pt \"Ubuntu\";"));
        tx->setAlignment(Qt::AlignCenter);
        rx = new QLabel(MessagesShowView);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(0, 360, 121, 40));
        rx->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"Ubuntu\";\n"
"background: transparent;"));
        rx->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(MessagesShowView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(121, 50, 681, 331));
        tableView->setStyleSheet(QString::fromUtf8(" color: gray;\n"
"background: transparent;\n"
"selection-background-color:rgba(11, 79, 89,18);\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
" border:none;\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(true);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);

        retranslateUi(MessagesShowView);

        QMetaObject::connectSlotsByName(MessagesShowView);
    } // setupUi

    void retranslateUi(QWidget *MessagesShowView)
    {
        MessagesShowView->setWindowTitle(QApplication::translate("MessagesShowView", "Form", 0, QApplication::UnicodeUTF8));
        arrowDownButton->setText(QString());
        homeTBnt->setText(QApplication::translate("MessagesShowView", "&Home", 0, QApplication::UnicodeUTF8));
        outBoxTBnt->setText(QApplication::translate("MessagesShowView", "&OutBox", 0, QApplication::UnicodeUTF8));
        inBoxTBnt->setText(QApplication::translate("MessagesShowView", "&InBox", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        copyBnt->setText(QApplication::translate("MessagesShowView", "&Copy", 0, QApplication::UnicodeUTF8));
        printBnt->setText(QApplication::translate("MessagesShowView", "&Print", 0, QApplication::UnicodeUTF8));
        closeBnt->setText(QApplication::translate("MessagesShowView", "C&lose", 0, QApplication::UnicodeUTF8));
        namelabel->setText(QString());
        txlabel->setText(QApplication::translate("MessagesShowView", "TX", 0, QApplication::UnicodeUTF8));
        rxlabel->setText(QApplication::translate("MessagesShowView", "RX", 0, QApplication::UnicodeUTF8));
        callmode->setText(QApplication::translate("MessagesShowView", "<html><head/><body><p><span style=\" font-weight:600;\">rgb</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("MessagesShowView", "<html><head/><body><p>WWWWWWWW</p></body></html>", 0, QApplication::UnicodeUTF8));
        tx->setText(QApplication::translate("MessagesShowView", "56685.33 kHz", 0, QApplication::UnicodeUTF8));
        rx->setText(QApplication::translate("MessagesShowView", "6685.33 kHz", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessagesShowView: public Ui_MessagesShowView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGESSHOWVIEW_H
