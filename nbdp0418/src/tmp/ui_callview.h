/********************************************************************************
** Form generated from reading UI file 'callview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLVIEW_H
#define UI_CALLVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_CallView
{
public:
    TitleWidget *CallTitleWidget;
    QRadioButton *arqRadio;
    QRadioButton *sfecRadio;
    QRadioButton *bfecRadio;
    QFrame *line;
    QFrame *line_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QToolButton *callBtn;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *callCodeTitle;
    QLabel *nameTitle;
    QLabel *rxTitle;
    QLabel *channelTitle;
    QLabel *txTitle;
    QLabel *nameLabel;
    QLabel *callCodeLabel;
    QLabel *channelLabel;
    QLabel *rxLabel;
    QLabel *txLabel;
    QRadioButton *individualRadio;
    QRadioButton *stationRadio;
    QRadioButton *manualRadio;

    void setupUi(QWidget *CallView)
    {
        if (CallView->objectName().isEmpty())
            CallView->setObjectName(QString::fromUtf8("CallView"));
        CallView->resize(800, 544);
        QFont font;
        font.setPointSize(20);
        CallView->setFont(font);
        CallView->setFocusPolicy(Qt::NoFocus);
        CallView->setWindowOpacity(1);
        CallTitleWidget = new TitleWidget(CallView);
        CallTitleWidget->setObjectName(QString::fromUtf8("CallTitleWidget"));
        CallTitleWidget->setGeometry(QRect(0, 0, 800, 45));
        arqRadio = new QRadioButton(CallView);
        arqRadio->setObjectName(QString::fromUtf8("arqRadio"));
        arqRadio->setGeometry(QRect(40, 80, 150, 50));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        arqRadio->setFont(font1);
        arqRadio->setFocusPolicy(Qt::StrongFocus);
        arqRadio->setAutoFillBackground(false);
        arqRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    border:1.5px solid gray;\n"
"    border-radius:25px;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images/images/Call"
                        "_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
""));
        arqRadio->setIconSize(QSize(40, 40));
        sfecRadio = new QRadioButton(CallView);
        sfecRadio->setObjectName(QString::fromUtf8("sfecRadio"));
        sfecRadio->setGeometry(QRect(330, 80, 150, 50));
        sfecRadio->setFont(font1);
        sfecRadio->setFocusPolicy(Qt::NoFocus);
        sfecRadio->setAutoFillBackground(false);
        sfecRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    border:1.5px solid gray;\n"
"    border-radius:25px;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"      background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images"
                        "/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
""));
        sfecRadio->setIconSize(QSize(40, 40));
        bfecRadio = new QRadioButton(CallView);
        bfecRadio->setObjectName(QString::fromUtf8("bfecRadio"));
        bfecRadio->setGeometry(QRect(610, 80, 150, 50));
        bfecRadio->setFont(font1);
        bfecRadio->setFocusPolicy(Qt::NoFocus);
        bfecRadio->setAutoFillBackground(false);
        bfecRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    border:1.5px solid gray;\n"
"    border-radius:25px;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images/images/Call"
                        "_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Mode_SelYes.png);\n"
"}\n"
""));
        bfecRadio->setIconSize(QSize(40, 40));
        line = new QFrame(CallView);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 139, 801, 16));
        line->setAutoFillBackground(false);
        line->setStyleSheet(QString::fromUtf8("background:transparent;"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(CallView);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 400, 800, 16));
        line_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        okBtn = new QPushButton(CallView);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(130, 420, 99, 30));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);
        cancelBtn = new QPushButton(CallView);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(470, 420, 99, 30));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        controlWidget = new QWidget(CallView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeBtn = new QToolButton(controlWidget);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));
        homeBtn->setGeometry(QRect(80, 0, 141, 61));
        homeBtn->setFocusPolicy(Qt::NoFocus);
        homeBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:rgb(86, 74, 74);\n"
"\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeBtn->setIcon(icon2);
        homeBtn->setIconSize(QSize(56, 42));
        homeBtn->setPopupMode(QToolButton::DelayedPopup);
        homeBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setGeometry(QRect(640, 0, 141, 61));
        receiveBtn->setFocusPolicy(Qt::NoFocus);
        receiveBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon3);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        callBtn = new QToolButton(controlWidget);
        callBtn->setObjectName(QString::fromUtf8("callBtn"));
        callBtn->setGeometry(QRect(450, 0, 145, 61));
        callBtn->setFocusPolicy(Qt::NoFocus);
        callBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelYes.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        callBtn->setIcon(icon4);
        callBtn->setIconSize(QSize(40, 40));
        callBtn->setPopupMode(QToolButton::DelayedPopup);
        callBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        gridLayoutWidget = new QWidget(CallView);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(350, 160, 441, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        callCodeTitle = new QLabel(gridLayoutWidget);
        callCodeTitle->setObjectName(QString::fromUtf8("callCodeTitle"));
        QPalette palette;
        QBrush brush(QColor(8, 249, 14, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        callCodeTitle->setPalette(palette);
        callCodeTitle->setFont(font);
        callCodeTitle->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(8, 249,14);\n"
"font-size :20pt;"));

        gridLayout->addWidget(callCodeTitle, 1, 0, 1, 1);

        nameTitle = new QLabel(gridLayoutWidget);
        nameTitle->setObjectName(QString::fromUtf8("nameTitle"));
        nameTitle->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(8, 249,14);\n"
"font-size :20pt;"));
        nameTitle->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Call_Info_Name.png")));
        nameTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(nameTitle, 0, 0, 1, 1);

        rxTitle = new QLabel(gridLayoutWidget);
        rxTitle->setObjectName(QString::fromUtf8("rxTitle"));
        rxTitle->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(8, 249,14);\n"
"font-size :20pt;"));

        gridLayout->addWidget(rxTitle, 4, 0, 1, 1);

        channelTitle = new QLabel(gridLayoutWidget);
        channelTitle->setObjectName(QString::fromUtf8("channelTitle"));
        channelTitle->setFont(font);
        channelTitle->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(8, 249,14);\n"
"font-size :20pt;"));

        gridLayout->addWidget(channelTitle, 2, 0, 1, 1);

        txTitle = new QLabel(gridLayoutWidget);
        txTitle->setObjectName(QString::fromUtf8("txTitle"));
        txTitle->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(8, 249,14);\n"
"font-size :20pt;"));

        gridLayout->addWidget(txTitle, 3, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font-size: 20px;\n"
"color: white;\n"
"font-wight:bold;"));

        gridLayout->addWidget(nameLabel, 0, 1, 1, 1);

        callCodeLabel = new QLabel(gridLayoutWidget);
        callCodeLabel->setObjectName(QString::fromUtf8("callCodeLabel"));
        callCodeLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font-size: 20px;\n"
"color: gray;"));

        gridLayout->addWidget(callCodeLabel, 1, 1, 1, 1);

        channelLabel = new QLabel(gridLayoutWidget);
        channelLabel->setObjectName(QString::fromUtf8("channelLabel"));
        channelLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font-size: 20px;\n"
"color: gray;"));

        gridLayout->addWidget(channelLabel, 2, 1, 1, 1);

        rxLabel = new QLabel(gridLayoutWidget);
        rxLabel->setObjectName(QString::fromUtf8("rxLabel"));
        rxLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font-size: 20px;\n"
"color: gray;"));

        gridLayout->addWidget(rxLabel, 4, 1, 1, 1);

        txLabel = new QLabel(gridLayoutWidget);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font-size: 20px;\n"
"color: gray;"));

        gridLayout->addWidget(txLabel, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 8);
        individualRadio = new QRadioButton(CallView);
        individualRadio->setObjectName(QString::fromUtf8("individualRadio"));
        individualRadio->setGeometry(QRect(10, 170, 311, 50));
        individualRadio->setFont(font1);
        individualRadio->setFocusPolicy(Qt::StrongFocus);
        individualRadio->setAutoFillBackground(false);
        individualRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"   border: none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Individual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Individual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images/images/Call_Indi"
                        "vidual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Individual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Individual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/images/Call_Individual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Individual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Individual_SelYes.png);\n"
"}\n"
""));
        individualRadio->setIconSize(QSize(40, 40));
        stationRadio = new QRadioButton(CallView);
        stationRadio->setObjectName(QString::fromUtf8("stationRadio"));
        stationRadio->setGeometry(QRect(10, 250, 311, 50));
        stationRadio->setFont(font1);
        stationRadio->setFocusPolicy(Qt::StrongFocus);
        stationRadio->setAutoFillBackground(false);
        stationRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"   border: none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Station_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Station_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images/images/Call_Station_Se"
                        "lNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Station_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Station_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"   image: url(:/images/images/Call_Station_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Station_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Station_SelYes.png);\n"
"}\n"
""));
        stationRadio->setIconSize(QSize(40, 40));
        manualRadio = new QRadioButton(CallView);
        manualRadio->setObjectName(QString::fromUtf8("manualRadio"));
        manualRadio->setGeometry(QRect(10, 330, 311, 50));
        manualRadio->setFont(font1);
        manualRadio->setFocusPolicy(Qt::StrongFocus);
        manualRadio->setAutoFillBackground(false);
        manualRadio->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"   border: none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"    padding:2px 5px;\n"
"	color:rgb(175, 171, 171);\n"
"}\n"
"\n"
"QRadioButton:focus\n"
"{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:white;\n"
"}\n"
"\n"
"QRadioButton::checked{\n"
"   border: none;\n"
"    outline: none;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"width:40px;\n"
"height:40px;\n"
"margin-left: 5px;\n"
"\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"image: url(:/images/images/Call_Manual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:focus {\n"
"image: url(:/images/images/Call_Manual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:hover {\n"
"image: url(:/images/images/Call_Manual_SelNo"
                        ".png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/images/Call_Manual_SelNo.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked{\n"
"    image: url(:/images/images/Call_Manual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover {\n"
"    image: url(:/images/images/Call_Manual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:pressed {\n"
"    image: url(:/images/images/Call_Manual_SelYes.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:focus {\n"
"    image: url(:/images/images/Call_Manual_SelYes.png);\n"
"}\n"
""));
        manualRadio->setIconSize(QSize(40, 40));
        QWidget::setTabOrder(arqRadio, sfecRadio);
        QWidget::setTabOrder(sfecRadio, bfecRadio);
        QWidget::setTabOrder(bfecRadio, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, homeBtn);
        QWidget::setTabOrder(homeBtn, callBtn);
        QWidget::setTabOrder(callBtn, receiveBtn);

        retranslateUi(CallView);

        QMetaObject::connectSlotsByName(CallView);
    } // setupUi

    void retranslateUi(QWidget *CallView)
    {
        CallView->setWindowTitle(QApplication::translate("CallView", "Form", 0, QApplication::UnicodeUTF8));
        arqRadio->setText(QApplication::translate("CallView", "&ARQ", 0, QApplication::UnicodeUTF8));
        sfecRadio->setText(QApplication::translate("CallView", "S&FEC", 0, QApplication::UnicodeUTF8));
        bfecRadio->setText(QApplication::translate("CallView", "&BFEC", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("CallView", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("CallView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        homeBtn->setText(QApplication::translate("CallView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("CallView", "&Receive", 0, QApplication::UnicodeUTF8));
        callBtn->setText(QApplication::translate("CallView", "&Transmit", 0, QApplication::UnicodeUTF8));
        callCodeTitle->setText(QApplication::translate("CallView", "Callcode", 0, QApplication::UnicodeUTF8));
        nameTitle->setText(QString());
        rxTitle->setText(QApplication::translate("CallView", "RX", 0, QApplication::UnicodeUTF8));
        channelTitle->setText(QApplication::translate("CallView", "Channel", 0, QApplication::UnicodeUTF8));
        txTitle->setText(QApplication::translate("CallView", "TX", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QString());
        callCodeLabel->setText(QString());
        channelLabel->setText(QString());
        rxLabel->setText(QString());
        txLabel->setText(QString());
        individualRadio->setText(QApplication::translate("CallView", "Contacts &Indivual", 0, QApplication::UnicodeUTF8));
        stationRadio->setText(QApplication::translate("CallView", "Contacts &Station", 0, QApplication::UnicodeUTF8));
        manualRadio->setText(QApplication::translate("CallView", "&Manual Frequency", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CallView: public Ui_CallView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLVIEW_H
