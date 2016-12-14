/********************************************************************************
** Form generated from reading UI file 'identificationsetting.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDENTIFICATIONSETTING_H
#define UI_IDENTIFICATIONSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_IdentificationSetting
{
public:
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *aboutTBtn;
    QToolButton *testTBtn;
    QToolButton *settingTBtn;
    TitleWidget *tiltewidget;
    QWidget *widget_7;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QFrame *line_2;
    QLabel *label;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;
    QTextEdit *textEdit;
    QLabel *numFocus2;
    QLabel *numFocus3;
    QLabel *numFocus;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_21;

    void setupUi(QWidget *IdentificationSetting)
    {
        if (IdentificationSetting->objectName().isEmpty())
            IdentificationSetting->setObjectName(QString::fromUtf8("IdentificationSetting"));
        IdentificationSetting->resize(800, 544);
        controlWidget = new QWidget(IdentificationSetting);
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
        aboutTBtn = new QToolButton(controlWidget);
        aboutTBtn->setObjectName(QString::fromUtf8("aboutTBtn"));
        aboutTBtn->setGeometry(QRect(650, 0, 131, 61));
        aboutTBtn->setFocusPolicy(Qt::NoFocus);
        aboutTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon1.addFile(QString::fromUtf8(":/images/System_AboutBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        aboutTBtn->setIcon(icon1);
        aboutTBtn->setIconSize(QSize(29, 29));
        aboutTBtn->setPopupMode(QToolButton::DelayedPopup);
        aboutTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        testTBtn = new QToolButton(controlWidget);
        testTBtn->setObjectName(QString::fromUtf8("testTBtn"));
        testTBtn->setGeometry(QRect(510, 0, 111, 61));
        testTBtn->setFocusPolicy(Qt::NoFocus);
        testTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon2.addFile(QString::fromUtf8(":/images/System_TestBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        testTBtn->setIcon(icon2);
        testTBtn->setIconSize(QSize(29, 29));
        testTBtn->setPopupMode(QToolButton::DelayedPopup);
        testTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        settingTBtn = new QToolButton(controlWidget);
        settingTBtn->setObjectName(QString::fromUtf8("settingTBtn"));
        settingTBtn->setGeometry(QRect(360, 0, 121, 61));
        settingTBtn->setFocusPolicy(Qt::NoFocus);
        settingTBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/System_SetBtn_SelNo"), QSize(), QIcon::Normal, QIcon::On);
        settingTBtn->setIcon(icon3);
        settingTBtn->setIconSize(QSize(27, 28));
        settingTBtn->setPopupMode(QToolButton::DelayedPopup);
        settingTBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tiltewidget = new TitleWidget(IdentificationSetting);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 0, 800, 45));
        widget_7 = new QWidget(IdentificationSetting);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(0, 420, 800, 51));
        okBtn = new QPushButton(widget_7);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(110, 0, 101, 31));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon4);
        cancelBtn = new QPushButton(widget_7);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(540, 0, 121, 31));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon5);
        line_2 = new QFrame(IdentificationSetting);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 390, 800, 16));
        line_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        label = new QLabel(IdentificationSetting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 247, 41, 51));
        label->setTextFormat(Qt::AutoText);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Call_exclamatory_mark.png")));
        listWidget = new QListWidget(IdentificationSetting);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEnabled(false);
        listWidget->setGeometry(QRect(69, 60, 291, 40));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"    padding-right:20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"}\n"
"\n"
"QListWidget:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"}\n"
"\n"
"QListWidget::item:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        listWidget_2 = new QListWidget(IdentificationSetting);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setEnabled(false);
        listWidget_2->setGeometry(QRect(90, 110, 271, 40));
        listWidget_2->setFocusPolicy(Qt::StrongFocus);
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"    padding-right:20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"}\n"
"\n"
"QListWidget:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"}\n"
"\n"
"QListWidget::item:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        listWidget_3 = new QListWidget(IdentificationSetting);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setEnabled(false);
        listWidget_3->setGeometry(QRect(90, 160, 271, 40));
        listWidget_3->setFocusPolicy(Qt::NoFocus);
        listWidget_3->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"    padding-right:20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"}\n"
"\n"
"QListWidget:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"}\n"
"\n"
"QListWidget::item:focus{\n"
"    border:none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}"));
        textEdit = new QTextEdit(IdentificationSetting);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(130, 240, 551, 71));
        textEdit->setStyleSheet(QString::fromUtf8("\n"
"    border:none;\n"
"    outline: none;\n"
"    background: transparent;\n"
"font: 57 16pt \"Ubuntu\";\n"
"   color:gray;"));
        numFocus2 = new QLabel(IdentificationSetting);
        numFocus2->setObjectName(QString::fromUtf8("numFocus2"));
        numFocus2->setGeometry(QRect(730, 130, 67, 17));
        numFocus3 = new QLabel(IdentificationSetting);
        numFocus3->setObjectName(QString::fromUtf8("numFocus3"));
        numFocus3->setGeometry(QRect(770, 170, 67, 17));
        numFocus = new QLabel(IdentificationSetting);
        numFocus->setObjectName(QString::fromUtf8("numFocus"));
        numFocus->setGeometry(QRect(720, 70, 67, 17));
        lineEdit_4 = new QLineEdit(IdentificationSetting);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(420, 65, 20, 30));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_5 = new QLineEdit(IdentificationSetting);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(440, 65, 20, 30));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background:transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_6 = new QLineEdit(IdentificationSetting);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(460, 65, 20, 30));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_7 = new QLineEdit(IdentificationSetting);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(480, 65, 20, 30));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_8 = new QLineEdit(IdentificationSetting);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(500, 65, 20, 30));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_9 = new QLineEdit(IdentificationSetting);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setEnabled(false);
        lineEdit_9->setGeometry(QRect(400, 65, 20, 30));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_10 = new QLineEdit(IdentificationSetting);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setEnabled(false);
        lineEdit_10->setGeometry(QRect(520, 65, 20, 30));
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(IdentificationSetting);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setEnabled(false);
        lineEdit_11->setGeometry(QRect(400, 113, 20, 30));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_12 = new QLineEdit(IdentificationSetting);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(420, 113, 20, 30));
        lineEdit_12->setFocusPolicy(Qt::NoFocus);
        lineEdit_12->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_13 = new QLineEdit(IdentificationSetting);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(440, 113, 20, 30));
        lineEdit_13->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_14 = new QLineEdit(IdentificationSetting);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(460, 113, 20, 30));
        lineEdit_14->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_15 = new QLineEdit(IdentificationSetting);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setGeometry(QRect(480, 113, 20, 30));
        lineEdit_15->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_16 = new QLineEdit(IdentificationSetting);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(500, 113, 20, 30));
        lineEdit_16->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_17 = new QLineEdit(IdentificationSetting);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(520, 113, 20, 30));
        lineEdit_17->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_18 = new QLineEdit(IdentificationSetting);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(540, 113, 20, 30));
        lineEdit_18->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_19 = new QLineEdit(IdentificationSetting);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(560, 113, 20, 30));
        lineEdit_19->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_20 = new QLineEdit(IdentificationSetting);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setEnabled(true);
        lineEdit_20->setGeometry(QRect(580, 113, 20, 30));
        lineEdit_20->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit = new QLineEdit(IdentificationSetting);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(420, 165, 321, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));
        lineEdit_21 = new QLineEdit(IdentificationSetting);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setEnabled(false);
        lineEdit_21->setGeometry(QRect(600, 113, 20, 30));
        lineEdit_21->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"    border:none;\n"
"    outline: none;    \n"
" background: transparent;\n"
"    color:white;\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    color:rgb(0, 0, 0);\n"
"    background-color:white;\n"
"}\n"
""));

        retranslateUi(IdentificationSetting);

        QMetaObject::connectSlotsByName(IdentificationSetting);
    } // setupUi

    void retranslateUi(QWidget *IdentificationSetting)
    {
        IdentificationSetting->setWindowTitle(QApplication::translate("IdentificationSetting", "Dialog", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("IdentificationSetting", "&Home", 0, QApplication::UnicodeUTF8));
        aboutTBtn->setText(QApplication::translate("IdentificationSetting", "&About", 0, QApplication::UnicodeUTF8));
        testTBtn->setText(QApplication::translate("IdentificationSetting", "&Test", 0, QApplication::UnicodeUTF8));
        settingTBtn->setText(QApplication::translate("IdentificationSetting", "&Setting", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("IdentificationSetting", "&Ok", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("IdentificationSetting", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        textEdit->setHtml(QApplication::translate("IdentificationSetting", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:16pt; font-weight:56; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Caution!  Confirm the 'Code' before pressing OK. You can not change the Code once it has been entered!</p></body></html>", 0, QApplication::UnicodeUTF8));
        numFocus2->setText(QString());
        numFocus3->setText(QString());
        numFocus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IdentificationSetting: public Ui_IdentificationSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDENTIFICATIONSETTING_H
