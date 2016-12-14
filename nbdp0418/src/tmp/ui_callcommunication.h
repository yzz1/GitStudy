/********************************************************************************
** Form generated from reading UI file 'callcommunication.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLCOMMUNICATION_H
#define UI_CALLCOMMUNICATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CallCommunication
{
public:
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *receiveBtn;
    QToolButton *callBtn;
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
    QFrame *upline_2;
    QLabel *namelabel_2;
    QLabel *timer;
    QLineEdit *inputEdit;
    QPushButton *sendBnt;
    QPushButton *optionBnt;
    QPushButton *printBnt;
    QPushButton *loadBnt;
    QPushButton *insertBnt;
    QPushButton *phrasebookBnt;
    QPushButton *MacroBnt;
    QPushButton *wruBnt;
    QPushButton *HRBnt;
    QPushButton *overBnt;
    QPushButton *breakBnt;
    QFrame *upline_3;
    QLabel *calltype;

    void setupUi(QWidget *CallCommunication)
    {
        if (CallCommunication->objectName().isEmpty())
            CallCommunication->setObjectName(QString::fromUtf8("CallCommunication"));
        CallCommunication->resize(800, 544);
        CallCommunication->setStyleSheet(QString::fromUtf8(""));
        controlWidget = new QWidget(CallCommunication);
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
"        font: 18pt \"Ubuntu\";\n"
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
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setEnabled(false);
        receiveBtn->setGeometry(QRect(630, 0, 141, 61));
        receiveBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"        font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus\n"
"{\n"
"    color:white;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Receive_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon1);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        callBtn = new QToolButton(controlWidget);
        callBtn->setObjectName(QString::fromUtf8("callBtn"));
        callBtn->setEnabled(false);
        callBtn->setGeometry(QRect(440, 0, 145, 61));
        callBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"     background: transparent;\n"
"        font: 18pt \"Ubuntu\";\n"
"\n"
"}\n"
"QToolButton:focus\n"
"{\n"
"    color:white;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelNo.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        callBtn->setIcon(icon2);
        callBtn->setIconSize(QSize(40, 40));
        callBtn->setPopupMode(QToolButton::DelayedPopup);
        callBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        upline = new QFrame(CallCommunication);
        upline->setObjectName(QString::fromUtf8("upline"));
        upline->setGeometry(QRect(0, 230, 121, 20));
        upline->setFrameShape(QFrame::HLine);
        upline->setFrameShadow(QFrame::Sunken);
        rightline = new QFrame(CallCommunication);
        rightline->setObjectName(QString::fromUtf8("rightline"));
        rightline->setGeometry(QRect(110, 2, 20, 471));
        rightline->setLineWidth(1);
        rightline->setFrameShape(QFrame::VLine);
        rightline->setFrameShadow(QFrame::Sunken);
        namelabel = new QLabel(CallCommunication);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(0, 120, 121, 41));
        namelabel->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: gray;\n"
"background: transparent;\n"
"font-weight:bold;"));
        namelabel->setAlignment(Qt::AlignCenter);
        txlabel = new QLabel(CallCommunication);
        txlabel->setObjectName(QString::fromUtf8("txlabel"));
        txlabel->setGeometry(QRect(30, 240, 60, 40));
        txlabel->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font: 15pt \"Ubuntu\";\n"
"background: transparent;"));
        txlabel->setAlignment(Qt::AlignCenter);
        rxlabel = new QLabel(CallCommunication);
        rxlabel->setObjectName(QString::fromUtf8("rxlabel"));
        rxlabel->setGeometry(QRect(30, 290, 60, 50));
        rxlabel->setLayoutDirection(Qt::LeftToRight);
        rxlabel->setAutoFillBackground(false);
        rxlabel->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font: 15pt \"Ubuntu\";\n"
"background: transparent;"));
        rxlabel->setAlignment(Qt::AlignCenter);
        rxlabel->setTextInteractionFlags(Qt::NoTextInteraction);
        callmode = new QLabel(CallCommunication);
        callmode->setObjectName(QString::fromUtf8("callmode"));
        callmode->setGeometry(QRect(0, 10, 121, 50));
        callmode->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: gray;\n"
"background: transparent;\n"
"font-weight:bold;"));
        callmode->setAlignment(Qt::AlignCenter);
        name = new QLabel(CallCommunication);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(0, 160, 121, 81));
        name->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font: 11pt \"Ubuntu\";\n"
""));
        name->setAlignment(Qt::AlignCenter);
        name->setWordWrap(true);
        tx = new QLabel(CallCommunication);
        tx->setObjectName(QString::fromUtf8("tx"));
        tx->setGeometry(QRect(6, 260, 111, 40));
        tx->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font: 12pt \"Ubuntu\";\n"
"background: transparent;"));
        tx->setAlignment(Qt::AlignCenter);
        rx = new QLabel(CallCommunication);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(10, 320, 111, 40));
        rx->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font: 12pt \"Ubuntu\";\n"
"background: transparent;"));
        rx->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(CallCommunication);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(125, 0, 681, 351));
        tableView->setStyleSheet(QString::fromUtf8(" color: gray;\n"
"background: transparent;\n"
"selection-color: rgb(255, 255, 255);\n"
"selection-background-color:rgba(11, 79, 89,18);\n"
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
        upline_2 = new QFrame(CallCommunication);
        upline_2->setObjectName(QString::fromUtf8("upline_2"));
        upline_2->setGeometry(QRect(0, 350, 121, 16));
        upline_2->setFrameShape(QFrame::HLine);
        upline_2->setFrameShadow(QFrame::Sunken);
        namelabel_2 = new QLabel(CallCommunication);
        namelabel_2->setObjectName(QString::fromUtf8("namelabel_2"));
        namelabel_2->setGeometry(QRect(40, 370, 36, 42));
        namelabel_2->setStyleSheet(QString::fromUtf8("image: url(:/images/Call_OS_ICO);\n"
""));
        timer = new QLabel(CallCommunication);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(0, 420, 121, 42));
        timer->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: gray;\n"
"background: transparent;"));
        timer->setAlignment(Qt::AlignCenter);
        inputEdit = new QLineEdit(CallCommunication);
        inputEdit->setObjectName(QString::fromUtf8("inputEdit"));
        inputEdit->setGeometry(QRect(124, 370, 540, 40));
        inputEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"   padding: 5px;\n"
"   border: none;\n"
"	font-size: 20px;\n"
"   color:gray;\n"
"background-color: rgb(22, 39, 46);\n"
"}\n"
"\n"
"QLineEdit::focus\n"
"{\n"
"   color:white;\n"
"background-color: rgb(69, 89, 104);\n"
"}"));
        sendBnt = new QPushButton(CallCommunication);
        sendBnt->setObjectName(QString::fromUtf8("sendBnt"));
        sendBnt->setGeometry(QRect(680, 370, 105, 36));
        sendBnt->setFocusPolicy(Qt::NoFocus);
        sendBnt->setAutoFillBackground(false);
        sendBnt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    border: none;\n"
"selection-color: rgb(255, 255, 255);\n"
"    border-radius:10px;\n"
"        color: rgb(105, 115, 119);\n"
"    border-radius:10px;\n"
"background-color: rgb(16, 34, 56);\n"
"font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        sendBnt->setCheckable(true);
        optionBnt = new QPushButton(CallCommunication);
        optionBnt->setObjectName(QString::fromUtf8("optionBnt"));
        optionBnt->setGeometry(QRect(680, 420, 105, 36));
        optionBnt->setFocusPolicy(Qt::NoFocus);
        optionBnt->setAutoFillBackground(false);
        optionBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color: rgb(105, 115, 119);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Call_Option_ico"), QSize(), QIcon::Normal, QIcon::Off);
        optionBnt->setIcon(icon3);
        optionBnt->setCheckable(true);
        printBnt = new QPushButton(CallCommunication);
        printBnt->setObjectName(QString::fromUtf8("printBnt"));
        printBnt->setGeometry(QRect(600, 410, 80, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        printBnt->setFont(font);
        printBnt->setFocusPolicy(Qt::NoFocus);
        printBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        printBnt->setCheckable(true);
        loadBnt = new QPushButton(CallCommunication);
        loadBnt->setObjectName(QString::fromUtf8("loadBnt"));
        loadBnt->setGeometry(QRect(600, 330, 80, 45));
        loadBnt->setFont(font);
        loadBnt->setFocusPolicy(Qt::NoFocus);
        loadBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        insertBnt = new QPushButton(CallCommunication);
        insertBnt->setObjectName(QString::fromUtf8("insertBnt"));
        insertBnt->setGeometry(QRect(600, 370, 80, 45));
        insertBnt->setFont(font);
        insertBnt->setFocusPolicy(Qt::NoFocus);
        insertBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        insertBnt->setIcon(icon3);
        insertBnt->setCheckable(true);
        phrasebookBnt = new QPushButton(CallCommunication);
        phrasebookBnt->setObjectName(QString::fromUtf8("phrasebookBnt"));
        phrasebookBnt->setGeometry(QRect(490, 410, 110, 45));
        phrasebookBnt->setFont(font);
        phrasebookBnt->setFocusPolicy(Qt::NoFocus);
        phrasebookBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        phrasebookBnt->setCheckable(true);
        MacroBnt = new QPushButton(CallCommunication);
        MacroBnt->setObjectName(QString::fromUtf8("MacroBnt"));
        MacroBnt->setGeometry(QRect(490, 370, 110, 45));
        MacroBnt->setFont(font);
        MacroBnt->setFocusPolicy(Qt::NoFocus);
        MacroBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"	color: rgb(105, 115, 119);\n"
"	background-color:rgb(65, 85, 100);\n"
"	font: 14pt \"Ubuntu\";\n"
"   text-align:left;\n"
"}\n"
"QPushButton:focus{\n"
"    color:rgb(255, 255, 255);\n"
"	background-color: rgb(16, 34, 56);\n"
"}"));
        MacroBnt->setCheckable(true);
        wruBnt = new QPushButton(CallCommunication);
        wruBnt->setObjectName(QString::fromUtf8("wruBnt"));
        wruBnt->setGeometry(QRect(140, 420, 71, 36));
        wruBnt->setFocusPolicy(Qt::NoFocus);
        wruBnt->setAutoFillBackground(false);
        wruBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"   outline:none;\n"
"	color: rgb(105, 115, 119);\n"
"	font: 18pt \"Ubuntu\";\n"
"   background: transparent;\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        wruBnt->setCheckable(true);
        HRBnt = new QPushButton(CallCommunication);
        HRBnt->setObjectName(QString::fromUtf8("HRBnt"));
        HRBnt->setGeometry(QRect(220, 420, 71, 36));
        HRBnt->setFocusPolicy(Qt::NoFocus);
        HRBnt->setAutoFillBackground(false);
        HRBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"   outline:none;\n"
"	color: rgb(105, 115, 119);\n"
"	font: 18pt \"Ubuntu\";\n"
"   background: transparent;\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        HRBnt->setCheckable(true);
        overBnt = new QPushButton(CallCommunication);
        overBnt->setObjectName(QString::fromUtf8("overBnt"));
        overBnt->setGeometry(QRect(310, 420, 71, 36));
        overBnt->setFocusPolicy(Qt::NoFocus);
        overBnt->setAutoFillBackground(false);
        overBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"   outline:none;\n"
"	color: rgb(105, 115, 119);\n"
"	font: 18pt \"Ubuntu\";\n"
"   background: transparent;\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        overBnt->setCheckable(true);
        breakBnt = new QPushButton(CallCommunication);
        breakBnt->setObjectName(QString::fromUtf8("breakBnt"));
        breakBnt->setGeometry(QRect(400, 420, 71, 36));
        breakBnt->setFocusPolicy(Qt::NoFocus);
        breakBnt->setAutoFillBackground(false);
        breakBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"   outline:none;\n"
"	color: rgb(105, 115, 119);\n"
"	font: 18pt \"Ubuntu\";\n"
"   background: transparent;\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        breakBnt->setCheckable(true);
        upline_3 = new QFrame(CallCommunication);
        upline_3->setObjectName(QString::fromUtf8("upline_3"));
        upline_3->setGeometry(QRect(0, 100, 121, 20));
        upline_3->setFrameShape(QFrame::HLine);
        upline_3->setFrameShadow(QFrame::Sunken);
        calltype = new QLabel(CallCommunication);
        calltype->setObjectName(QString::fromUtf8("calltype"));
        calltype->setGeometry(QRect(0, 60, 121, 50));
        calltype->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: gray;\n"
"background: transparent;\n"
"font-weight:bold;"));
        calltype->setAlignment(Qt::AlignCenter);

        retranslateUi(CallCommunication);

        QMetaObject::connectSlotsByName(CallCommunication);
    } // setupUi

    void retranslateUi(QWidget *CallCommunication)
    {
        CallCommunication->setWindowTitle(QApplication::translate("CallCommunication", "Form", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("CallCommunication", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("CallCommunication", "Receive", 0, QApplication::UnicodeUTF8));
        callBtn->setText(QApplication::translate("CallCommunication", "Transmit", 0, QApplication::UnicodeUTF8));
        namelabel->setText(QApplication::translate("CallCommunication", "Name", 0, QApplication::UnicodeUTF8));
        txlabel->setText(QApplication::translate("CallCommunication", "TX", 0, QApplication::UnicodeUTF8));
        rxlabel->setText(QApplication::translate("CallCommunication", "RX", 0, QApplication::UnicodeUTF8));
        callmode->setText(QApplication::translate("CallCommunication", "ARQ", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("CallCommunication", "WWWWWWWW", 0, QApplication::UnicodeUTF8));
        tx->setText(QApplication::translate("CallCommunication", "26685.30 kHz", 0, QApplication::UnicodeUTF8));
        rx->setText(QApplication::translate("CallCommunication", "16685.30 kHz", 0, QApplication::UnicodeUTF8));
        namelabel_2->setText(QString());
        timer->setText(QApplication::translate("CallCommunication", "00:00:00", 0, QApplication::UnicodeUTF8));
        inputEdit->setText(QString());
        sendBnt->setText(QApplication::translate("CallCommunication", "&Send", 0, QApplication::UnicodeUTF8));
        optionBnt->setText(QApplication::translate("CallCommunication", "Op&tion", 0, QApplication::UnicodeUTF8));
        printBnt->setText(QApplication::translate("CallCommunication", " &Print", 0, QApplication::UnicodeUTF8));
        loadBnt->setText(QApplication::translate("CallCommunication", " &Load", 0, QApplication::UnicodeUTF8));
        insertBnt->setText(QApplication::translate("CallCommunication", " &Insert", 0, QApplication::UnicodeUTF8));
        phrasebookBnt->setText(QApplication::translate("CallCommunication", " Phr&asebook", 0, QApplication::UnicodeUTF8));
        MacroBnt->setText(QApplication::translate("CallCommunication", "       &Macro", 0, QApplication::UnicodeUTF8));
        wruBnt->setText(QApplication::translate("CallCommunication", "&WRU", 0, QApplication::UnicodeUTF8));
        HRBnt->setText(QApplication::translate("CallCommunication", "H&R", 0, QApplication::UnicodeUTF8));
        overBnt->setText(QApplication::translate("CallCommunication", "&Over", 0, QApplication::UnicodeUTF8));
        breakBnt->setText(QApplication::translate("CallCommunication", "&Break", 0, QApplication::UnicodeUTF8));
        calltype->setText(QApplication::translate("CallCommunication", "CALL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CallCommunication: public Ui_CallCommunication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLCOMMUNICATION_H
