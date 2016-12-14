/********************************************************************************
** Form generated from reading UI file 'frequencyview.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCYVIEW_H
#define UI_FREQUENCYVIEW_H

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

class Ui_FrequencyView
{
public:
    QLabel *channelLabel;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QToolButton *callBtn;
    QLabel *rxLabel;
    TitleWidget *titleWidget;
    QLabel *txLabel;
    QPushButton *arrowUpButton;
    QTableView *tableView;
    QPushButton *arrowDownButton;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QFrame *Contactsline;

    void setupUi(QWidget *FrequencyView)
    {
        if (FrequencyView->objectName().isEmpty())
            FrequencyView->setObjectName(QString::fromUtf8("FrequencyView"));
        FrequencyView->resize(800, 544);
        channelLabel = new QLabel(FrequencyView);
        channelLabel->setObjectName(QString::fromUtf8("channelLabel"));
        channelLabel->setGeometry(QRect(30, 50, 211, 61));
        channelLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/Call_Ellipse.png);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        channelLabel->setAlignment(Qt::AlignCenter);
        controlWidget = new QWidget(FrequencyView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeBtn = new QToolButton(controlWidget);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));
        homeBtn->setGeometry(QRect(80, 0, 141, 61));
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
        receiveBtn->setGeometry(QRect(640, 0, 141, 61));
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
        callBtn->setGeometry(QRect(450, 0, 145, 61));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/Call_Bnt_SelNo.png"), QSize(), QIcon::Normal, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/images/individual_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        callBtn->setIcon(icon2);
        callBtn->setIconSize(QSize(40, 40));
        callBtn->setPopupMode(QToolButton::DelayedPopup);
        callBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        rxLabel = new QLabel(FrequencyView);
        rxLabel->setObjectName(QString::fromUtf8("rxLabel"));
        rxLabel->setGeometry(QRect(560, 50, 211, 61));
        rxLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/Call_Ellipse.png);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        rxLabel->setAlignment(Qt::AlignCenter);
        titleWidget = new TitleWidget(FrequencyView);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 800, 45));
        txLabel = new QLabel(FrequencyView);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setGeometry(QRect(300, 50, 211, 61));
        txLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/Call_Ellipse.png);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        txLabel->setAlignment(Qt::AlignCenter);
        arrowUpButton = new QPushButton(FrequencyView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(370, 390, 30, 15));
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        tableView = new QTableView(FrequencyView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 110, 800, 281));
        tableView->setStyleSheet(QString::fromUtf8(" color: gray;\n"
"background: transparent;\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
"    border:none;\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(true);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(40);
        arrowDownButton = new QPushButton(FrequencyView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(450, 390, 30, 15));
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        okBtn = new QPushButton(FrequencyView);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(160, 420, 99, 30));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon3);
        cancelBtn = new QPushButton(FrequencyView);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(500, 420, 99, 30));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon4);
        Contactsline = new QFrame(FrequencyView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);

        retranslateUi(FrequencyView);

        QMetaObject::connectSlotsByName(FrequencyView);
    } // setupUi

    void retranslateUi(QWidget *FrequencyView)
    {
        FrequencyView->setWindowTitle(QApplication::translate("FrequencyView", "Form", 0, QApplication::UnicodeUTF8));
        channelLabel->setText(QApplication::translate("FrequencyView", "Channel", 0, QApplication::UnicodeUTF8));
        homeBtn->setText(QApplication::translate("FrequencyView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("FrequencyView", "&Receive", 0, QApplication::UnicodeUTF8));
        callBtn->setText(QApplication::translate("FrequencyView", "&Transmit", 0, QApplication::UnicodeUTF8));
        rxLabel->setText(QApplication::translate("FrequencyView", "RX Frequency", 0, QApplication::UnicodeUTF8));
        txLabel->setText(QApplication::translate("FrequencyView", "TX Frequency", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        okBtn->setText(QApplication::translate("FrequencyView", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("FrequencyView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FrequencyView: public Ui_FrequencyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCYVIEW_H
