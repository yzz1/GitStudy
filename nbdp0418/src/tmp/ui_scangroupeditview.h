/********************************************************************************
** Form generated from reading UI file 'scangroupeditview.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANGROUPEDITVIEW_H
#define UI_SCANGROUPEDITVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include <widgets/frequencyinput.h>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScanGroupEditView
{
public:
    TitleWidget *titleWidget;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QFrame *Contactsline;
    QLineEdit *tx;
    QLineEdit *tx_2;
    QLineEdit *tx_3;
    QLineEdit *tx_4;
    QLineEdit *rx;
    QLineEdit *rx_2;
    QLineEdit *rx_3;
    QLineEdit *rx_4;
    QLineEdit *rx_5;
    QLineEdit *tx_5;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    QListWidget *group_name;
    QLineEdit *tx_6;
    QLineEdit *rx_6;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QListWidget *dwell_time;
    QListWidget *scan_mode;
    QLineEdit *dwellTimeEdit;
    QLineEdit *scanModeEdit;
    QLineEdit *tx_7;
    QLineEdit *rx_7;
    QLineEdit *groupNameEdit;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *scanModeFocus;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QComboBox *comboBox_7;
    FrequencyInput *widget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    FrequencyInput *widget_2;
    FrequencyInput *widget_3;
    FrequencyInput *widget_4;
    FrequencyInput *widget_5;
    FrequencyInput *widget_6;
    FrequencyInput *widget_7;
    FrequencyInput *widget_8;
    FrequencyInput *widget_9;
    FrequencyInput *widget_10;
    FrequencyInput *widget_11;
    FrequencyInput *widget_12;

    void setupUi(QWidget *ScanGroupEditView)
    {
        if (ScanGroupEditView->objectName().isEmpty())
            ScanGroupEditView->setObjectName(QString::fromUtf8("ScanGroupEditView"));
        ScanGroupEditView->resize(800, 544);
        titleWidget = new TitleWidget(ScanGroupEditView);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 800, 45));
        controlWidget = new QWidget(ScanGroupEditView);
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
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeBtn->setIcon(icon);
        homeBtn->setIconSize(QSize(56, 42));
        homeBtn->setPopupMode(QToolButton::DelayedPopup);
        homeBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setGeometry(QRect(610, 0, 141, 61));
        receiveBtn->setFocusPolicy(Qt::NoFocus);
        receiveBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    border:none;\n"
"    outline: none;\n"
"     background: transparent;\n"
"        font: 18pt \"Ubuntu\";\n"
"    color:rgb(86, 74, 74);\n"
"}\n"
"QToolButton:focus{\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Scan_ICO_SelYes.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon1);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        Contactsline = new QFrame(ScanGroupEditView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        tx = new QLineEdit(ScanGroupEditView);
        tx->setObjectName(QString::fromUtf8("tx"));
        tx->setGeometry(QRect(440, 55, 140, 40));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tx->sizePolicy().hasHeightForWidth());
        tx->setSizePolicy(sizePolicy);
        tx->setMinimumSize(QSize(80, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tx->setFont(font);
        tx->setFocusPolicy(Qt::NoFocus);
        tx->setStyleSheet(QString::fromUtf8("    border: none;\n"
"    outline: none;\n"
"    font: 20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));"));
        tx->setAlignment(Qt::AlignCenter);
        tx_2 = new QLineEdit(ScanGroupEditView);
        tx_2->setObjectName(QString::fromUtf8("tx_2"));
        tx_2->setEnabled(true);
        tx_2->setGeometry(QRect(440, 105, 140, 40));
        sizePolicy.setHeightForWidth(tx_2->sizePolicy().hasHeightForWidth());
        tx_2->setSizePolicy(sizePolicy);
        tx_2->setMinimumSize(QSize(80, 40));
        QFont font1;
        font1.setPointSize(15);
        tx_2->setFont(font1);
        tx_2->setCursor(QCursor(Qt::BlankCursor));
        tx_2->setMouseTracking(false);
        tx_2->setFocusPolicy(Qt::ClickFocus);
        tx_2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_2->setAlignment(Qt::AlignCenter);
        tx_3 = new QLineEdit(ScanGroupEditView);
        tx_3->setObjectName(QString::fromUtf8("tx_3"));
        tx_3->setGeometry(QRect(440, 150, 140, 40));
        sizePolicy.setHeightForWidth(tx_3->sizePolicy().hasHeightForWidth());
        tx_3->setSizePolicy(sizePolicy);
        tx_3->setMinimumSize(QSize(80, 40));
        tx_3->setFont(font1);
        tx_3->setFocusPolicy(Qt::ClickFocus);
        tx_3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_3->setAlignment(Qt::AlignCenter);
        tx_4 = new QLineEdit(ScanGroupEditView);
        tx_4->setObjectName(QString::fromUtf8("tx_4"));
        tx_4->setGeometry(QRect(440, 195, 140, 40));
        sizePolicy.setHeightForWidth(tx_4->sizePolicy().hasHeightForWidth());
        tx_4->setSizePolicy(sizePolicy);
        tx_4->setMinimumSize(QSize(80, 40));
        tx_4->setFont(font1);
        tx_4->setFocusPolicy(Qt::ClickFocus);
        tx_4->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_4->setAlignment(Qt::AlignCenter);
        rx = new QLineEdit(ScanGroupEditView);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(610, 55, 140, 40));
        sizePolicy.setHeightForWidth(rx->sizePolicy().hasHeightForWidth());
        rx->setSizePolicy(sizePolicy);
        rx->setMinimumSize(QSize(80, 40));
        rx->setFont(font);
        rx->setFocusPolicy(Qt::NoFocus);
        rx->setStyleSheet(QString::fromUtf8("    border: none;\n"
"    outline: none;\n"
"    font:  20pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));"));
        rx->setAlignment(Qt::AlignCenter);
        rx_2 = new QLineEdit(ScanGroupEditView);
        rx_2->setObjectName(QString::fromUtf8("rx_2"));
        rx_2->setGeometry(QRect(610, 105, 140, 40));
        sizePolicy.setHeightForWidth(rx_2->sizePolicy().hasHeightForWidth());
        rx_2->setSizePolicy(sizePolicy);
        rx_2->setMinimumSize(QSize(80, 40));
        rx_2->setFont(font1);
        rx_2->setFocusPolicy(Qt::ClickFocus);
        rx_2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_2->setAlignment(Qt::AlignCenter);
        rx_3 = new QLineEdit(ScanGroupEditView);
        rx_3->setObjectName(QString::fromUtf8("rx_3"));
        rx_3->setGeometry(QRect(610, 150, 140, 40));
        sizePolicy.setHeightForWidth(rx_3->sizePolicy().hasHeightForWidth());
        rx_3->setSizePolicy(sizePolicy);
        rx_3->setMinimumSize(QSize(80, 40));
        rx_3->setFont(font1);
        rx_3->setFocusPolicy(Qt::ClickFocus);
        rx_3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_3->setAlignment(Qt::AlignCenter);
        rx_4 = new QLineEdit(ScanGroupEditView);
        rx_4->setObjectName(QString::fromUtf8("rx_4"));
        rx_4->setGeometry(QRect(610, 195, 140, 40));
        sizePolicy.setHeightForWidth(rx_4->sizePolicy().hasHeightForWidth());
        rx_4->setSizePolicy(sizePolicy);
        rx_4->setMinimumSize(QSize(80, 40));
        rx_4->setFont(font1);
        rx_4->setFocusPolicy(Qt::ClickFocus);
        rx_4->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_4->setAlignment(Qt::AlignCenter);
        rx_5 = new QLineEdit(ScanGroupEditView);
        rx_5->setObjectName(QString::fromUtf8("rx_5"));
        rx_5->setGeometry(QRect(610, 240, 140, 40));
        sizePolicy.setHeightForWidth(rx_5->sizePolicy().hasHeightForWidth());
        rx_5->setSizePolicy(sizePolicy);
        rx_5->setMinimumSize(QSize(80, 40));
        rx_5->setFont(font1);
        rx_5->setFocusPolicy(Qt::ClickFocus);
        rx_5->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_5->setAlignment(Qt::AlignCenter);
        tx_5 = new QLineEdit(ScanGroupEditView);
        tx_5->setObjectName(QString::fromUtf8("tx_5"));
        tx_5->setGeometry(QRect(440, 240, 140, 40));
        sizePolicy.setHeightForWidth(tx_5->sizePolicy().hasHeightForWidth());
        tx_5->setSizePolicy(sizePolicy);
        tx_5->setMinimumSize(QSize(80, 40));
        tx_5->setFont(font1);
        tx_5->setFocusPolicy(Qt::ClickFocus);
        tx_5->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_5->setAlignment(Qt::AlignCenter);
        arrowUpButton = new QPushButton(ScanGroupEditView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(530, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ScanGroupEditView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(630, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        group_name = new QListWidget(ScanGroupEditView);
        group_name->setObjectName(QString::fromUtf8("group_name"));
        group_name->setGeometry(QRect(60, 70, 220, 40));
        group_name->setFocusPolicy(Qt::NoFocus);
        group_name->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"\n"
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
        tx_6 = new QLineEdit(ScanGroupEditView);
        tx_6->setObjectName(QString::fromUtf8("tx_6"));
        tx_6->setGeometry(QRect(440, 285, 140, 40));
        sizePolicy.setHeightForWidth(tx_6->sizePolicy().hasHeightForWidth());
        tx_6->setSizePolicy(sizePolicy);
        tx_6->setMinimumSize(QSize(80, 40));
        tx_6->setFont(font1);
        tx_6->setFocusPolicy(Qt::ClickFocus);
        tx_6->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_6->setAlignment(Qt::AlignCenter);
        rx_6 = new QLineEdit(ScanGroupEditView);
        rx_6->setObjectName(QString::fromUtf8("rx_6"));
        rx_6->setGeometry(QRect(610, 285, 140, 40));
        sizePolicy.setHeightForWidth(rx_6->sizePolicy().hasHeightForWidth());
        rx_6->setSizePolicy(sizePolicy);
        rx_6->setMinimumSize(QSize(80, 40));
        rx_6->setFont(font1);
        rx_6->setFocusPolicy(Qt::ClickFocus);
        rx_6->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_6->setAlignment(Qt::AlignCenter);
        okBtn = new QPushButton(ScanGroupEditView);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(110, 420, 99, 30));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon2);
        cancelBtn = new QPushButton(ScanGroupEditView);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(570, 420, 99, 30));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon3);
        dwell_time = new QListWidget(ScanGroupEditView);
        dwell_time->setObjectName(QString::fromUtf8("dwell_time"));
        dwell_time->setGeometry(QRect(60, 170, 220, 40));
        dwell_time->setFocusPolicy(Qt::NoFocus);
        dwell_time->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"\n"
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
        scan_mode = new QListWidget(ScanGroupEditView);
        scan_mode->setObjectName(QString::fromUtf8("scan_mode"));
        scan_mode->setGeometry(QRect(60, 270, 220, 40));
        scan_mode->setFocusPolicy(Qt::NoFocus);
        scan_mode->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"\n"
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
        dwellTimeEdit = new QLineEdit(ScanGroupEditView);
        dwellTimeEdit->setObjectName(QString::fromUtf8("dwellTimeEdit"));
        dwellTimeEdit->setGeometry(QRect(60, 210, 220, 40));
        sizePolicy.setHeightForWidth(dwellTimeEdit->sizePolicy().hasHeightForWidth());
        dwellTimeEdit->setSizePolicy(sizePolicy);
        dwellTimeEdit->setMinimumSize(QSize(80, 40));
        dwellTimeEdit->setFont(font1);
        dwellTimeEdit->setFocusPolicy(Qt::ClickFocus);
        dwellTimeEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    color:white;\n"
"}\n"
""));
        dwellTimeEdit->setAlignment(Qt::AlignCenter);
        scanModeEdit = new QLineEdit(ScanGroupEditView);
        scanModeEdit->setObjectName(QString::fromUtf8("scanModeEdit"));
        scanModeEdit->setEnabled(false);
        scanModeEdit->setGeometry(QRect(60, 310, 220, 40));
        sizePolicy.setHeightForWidth(scanModeEdit->sizePolicy().hasHeightForWidth());
        scanModeEdit->setSizePolicy(sizePolicy);
        scanModeEdit->setMinimumSize(QSize(80, 40));
        scanModeEdit->setFont(font1);
        scanModeEdit->setFocusPolicy(Qt::NoFocus);
        scanModeEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    color:white;\n"
"}\n"
""));
        scanModeEdit->setAlignment(Qt::AlignCenter);
        tx_7 = new QLineEdit(ScanGroupEditView);
        tx_7->setObjectName(QString::fromUtf8("tx_7"));
        tx_7->setGeometry(QRect(440, 330, 140, 40));
        sizePolicy.setHeightForWidth(tx_7->sizePolicy().hasHeightForWidth());
        tx_7->setSizePolicy(sizePolicy);
        tx_7->setMinimumSize(QSize(80, 40));
        tx_7->setFont(font1);
        tx_7->setFocusPolicy(Qt::ClickFocus);
        tx_7->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_7->setAlignment(Qt::AlignCenter);
        rx_7 = new QLineEdit(ScanGroupEditView);
        rx_7->setObjectName(QString::fromUtf8("rx_7"));
        rx_7->setGeometry(QRect(610, 330, 140, 40));
        sizePolicy.setHeightForWidth(rx_7->sizePolicy().hasHeightForWidth());
        rx_7->setSizePolicy(sizePolicy);
        rx_7->setMinimumSize(QSize(80, 40));
        rx_7->setFont(font1);
        rx_7->setFocusPolicy(Qt::ClickFocus);
        rx_7->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_7->setAlignment(Qt::AlignCenter);
        groupNameEdit = new QLineEdit(ScanGroupEditView);
        groupNameEdit->setObjectName(QString::fromUtf8("groupNameEdit"));
        groupNameEdit->setGeometry(QRect(60, 110, 220, 40));
        sizePolicy.setHeightForWidth(groupNameEdit->sizePolicy().hasHeightForWidth());
        groupNameEdit->setSizePolicy(sizePolicy);
        groupNameEdit->setMinimumSize(QSize(80, 40));
        groupNameEdit->setFont(font1);
        groupNameEdit->setFocusPolicy(Qt::StrongFocus);
        groupNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QLineEdit:focus\n"
"{\n"
"    border:none;\n"
"    outline: none;\n"
"    color:white;\n"
"\n"
"}\n"
"\n"
"QLineEdit:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    color:white;\n"
"}\n"
""));
        groupNameEdit->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(ScanGroupEditView);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 310, 215, 40));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setFocusPolicy(Qt::NoFocus);
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgb(105, 115, 119);\n"
"}\n"
"QComboBox:focus{\n"
"\n"
"color: white;\n"
"}\n"
"QComboBox::down-arrow{image: url(:/images/System_Arrow_Down);}\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        pushButton = new QPushButton(ScanGroupEditView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 107, 90, 35));
        pushButton->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/Scan_Arrow_Down_SelYes.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton_2 = new QPushButton(ScanGroupEditView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 152, 90, 35));
        pushButton_2->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        pushButton_2->setIcon(icon4);
        pushButton_3 = new QPushButton(ScanGroupEditView);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 197, 90, 35));
        pushButton_3->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        pushButton_3->setIcon(icon4);
        pushButton_4 = new QPushButton(ScanGroupEditView);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 242, 90, 35));
        pushButton_4->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        pushButton_4->setIcon(icon4);
        pushButton_5 = new QPushButton(ScanGroupEditView);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 287, 90, 35));
        pushButton_5->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        pushButton_5->setIcon(icon4);
        pushButton_6 = new QPushButton(ScanGroupEditView);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(340, 332, 90, 35));
        pushButton_6->setStyleSheet(QString::fromUtf8(" QPushButton{\n"
"\n"
"    border: none;\n"
"\n"
"    icon-size: 40px;\n"
"    font-size: 16pt;\n"
"    font-weight: bold;\n"
"    color: rgb(105, 115, 119);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        pushButton_6->setIcon(icon4);
        scanModeFocus = new QLabel(ScanGroupEditView);
        scanModeFocus->setObjectName(QString::fromUtf8("scanModeFocus"));
        scanModeFocus->setGeometry(QRect(-10, 320, 67, 17));
        comboBox_2 = new QComboBox(ScanGroupEditView);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(340, 110, 91, 31));
        comboBox_2->setFocusPolicy(Qt::NoFocus);
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        comboBox_3 = new QComboBox(ScanGroupEditView);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(340, 150, 91, 31));
        comboBox_3->setFocusPolicy(Qt::NoFocus);
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        comboBox_4 = new QComboBox(ScanGroupEditView);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(340, 195, 91, 31));
        comboBox_4->setFocusPolicy(Qt::NoFocus);
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        comboBox_5 = new QComboBox(ScanGroupEditView);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(340, 240, 91, 31));
        comboBox_5->setFocusPolicy(Qt::NoFocus);
        comboBox_5->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        comboBox_6 = new QComboBox(ScanGroupEditView);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(340, 285, 91, 31));
        comboBox_6->setFocusPolicy(Qt::NoFocus);
        comboBox_6->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        comboBox_7 = new QComboBox(ScanGroupEditView);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(340, 330, 91, 31));
        comboBox_7->setFocusPolicy(Qt::NoFocus);
        comboBox_7->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border:0px;\n"
"background: transparent;\n"
"font: 14pt \"Ubuntu\";\n"
"color: rgba(105, 115, 119,0);\n"
"}\n"
"\n"
"QComboBox:focus{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"QComboBox QAbstractItemView::item {\n"
"height:100px;\n"
"margin:10px;\n"
"\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"border:0px;\n"
"outer:0px;\n"
"selection-background-color: rgb(140, 146, 150);\n"
"background-color: rgb(140, 146, 150);\n"
"}\n"
""));
        widget = new FrequencyInput(ScanGroupEditView);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(440, 105, 140, 40));
        lineEdit = new QLineEdit(ScanGroupEditView);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(340, 107, 90, 35));
        lineEdit_2 = new QLineEdit(ScanGroupEditView);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(340, 152, 90, 35));
        lineEdit_3 = new QLineEdit(ScanGroupEditView);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(340, 197, 90, 35));
        lineEdit_4 = new QLineEdit(ScanGroupEditView);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(340, 242, 90, 35));
        lineEdit_5 = new QLineEdit(ScanGroupEditView);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setGeometry(QRect(340, 287, 90, 35));
        lineEdit_6 = new QLineEdit(ScanGroupEditView);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);
        lineEdit_6->setGeometry(QRect(340, 332, 90, 35));
        widget_2 = new FrequencyInput(ScanGroupEditView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(610, 105, 140, 40));
        widget_3 = new FrequencyInput(ScanGroupEditView);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(440, 150, 140, 40));
        widget_4 = new FrequencyInput(ScanGroupEditView);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(610, 150, 140, 40));
        widget_5 = new FrequencyInput(ScanGroupEditView);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(440, 195, 140, 40));
        widget_6 = new FrequencyInput(ScanGroupEditView);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(610, 195, 140, 40));
        widget_7 = new FrequencyInput(ScanGroupEditView);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(440, 240, 140, 40));
        widget_8 = new FrequencyInput(ScanGroupEditView);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(610, 240, 140, 40));
        widget_9 = new FrequencyInput(ScanGroupEditView);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(440, 285, 140, 40));
        widget_10 = new FrequencyInput(ScanGroupEditView);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        widget_10->setGeometry(QRect(610, 285, 140, 40));
        widget_11 = new FrequencyInput(ScanGroupEditView);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        widget_11->setGeometry(QRect(440, 330, 140, 40));
        widget_12 = new FrequencyInput(ScanGroupEditView);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setGeometry(QRect(610, 330, 140, 40));

        retranslateUi(ScanGroupEditView);

        QMetaObject::connectSlotsByName(ScanGroupEditView);
    } // setupUi

    void retranslateUi(QWidget *ScanGroupEditView)
    {
        ScanGroupEditView->setWindowTitle(QApplication::translate("ScanGroupEditView", "Form", 0, QApplication::UnicodeUTF8));
        homeBtn->setText(QApplication::translate("ScanGroupEditView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("ScanGroupEditView", "Scan", 0, QApplication::UnicodeUTF8));
        tx->setText(QApplication::translate("ScanGroupEditView", "Tx(KHz)", 0, QApplication::UnicodeUTF8));
        rx->setText(QApplication::translate("ScanGroupEditView", "Rx(KHz)", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        okBtn->setText(QApplication::translate("ScanGroupEditView", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ScanGroupEditView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_6->setText(QString());
        scanModeFocus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScanGroupEditView: public Ui_ScanGroupEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANGROUPEDITVIEW_H
