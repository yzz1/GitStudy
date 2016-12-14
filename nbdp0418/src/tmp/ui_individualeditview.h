/********************************************************************************
** Form generated from reading UI file 'individualeditview.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDIVIDUALEDITVIEW_H
#define UI_INDIVIDUALEDITVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include <widgets/contactsinput.h>
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_IndividualEditView
{
public:
    TitleWidget *tiltewidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *frequencyGrid;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QFrame *Contactsline;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    QLabel *nameLabel;
    QLineEdit *callcode;
    QLineEdit *name;
    QLabel *callcodeLabel;
    QWidget *controlWidget;
    QToolButton *homeTBnt;
    QToolButton *stationTBnt;
    QToolButton *individualTBnt;
    ContactsInput *widget;
    ContactsInput *widget_2;
    QLineEdit *txHeader;
    QLineEdit *rxHeader;
    QLineEdit *channel2;
    QLineEdit *no2;
    QLineEdit *channelHeader;
    QLineEdit *no;
    QLineEdit *channel3;
    QLineEdit *rx1;
    QLineEdit *channel1;
    QLineEdit *noHeader;
    QLineEdit *no3;
    QLineEdit *tx1;
    ContactsInput *widget_3;
    ContactsInput *widget_4;
    ContactsInput *widget_5;
    ContactsInput *widget_6;
    QLineEdit *tx2;
    QLineEdit *tx3;
    QLineEdit *rx2;
    QLineEdit *rx3;

    void setupUi(QWidget *IndividualEditView)
    {
        if (IndividualEditView->objectName().isEmpty())
            IndividualEditView->setObjectName(QString::fromUtf8("IndividualEditView"));
        IndividualEditView->resize(800, 544);
        tiltewidget = new TitleWidget(IndividualEditView);
        tiltewidget->setObjectName(QString::fromUtf8("tiltewidget"));
        tiltewidget->setGeometry(QRect(0, 0, 800, 45));
        gridLayoutWidget_2 = new QWidget(IndividualEditView);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 170, 801, 228));
        frequencyGrid = new QGridLayout(gridLayoutWidget_2);
        frequencyGrid->setObjectName(QString::fromUtf8("frequencyGrid"));
        frequencyGrid->setSizeConstraint(QLayout::SetDefaultConstraint);
        frequencyGrid->setHorizontalSpacing(20);
        frequencyGrid->setVerticalSpacing(12);
        frequencyGrid->setContentsMargins(40, 10, 40, 10);
        horizontalLayoutWidget_2 = new QWidget(IndividualEditView);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 410, 801, 10));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Contactsline = new QFrame(horizontalLayoutWidget_2);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setStyleSheet(QString::fromUtf8("color: gray;"));
        Contactsline->setFrameShadow(QFrame::Plain);
        Contactsline->setFrameShape(QFrame::HLine);

        horizontalLayout_4->addWidget(Contactsline);

        horizontalLayoutWidget_3 = new QWidget(IndividualEditView);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 420, 801, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        okBtn = new QPushButton(horizontalLayoutWidget_3);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);

        horizontalLayout_5->addWidget(okBtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);

        cancelBtn = new QPushButton(horizontalLayoutWidget_3);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);

        horizontalLayout_5->addWidget(cancelBtn);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        arrowUpButton = new QPushButton(IndividualEditView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(340, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(IndividualEditView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(420, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        nameLabel = new QLabel(IndividualEditView);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(90, 40, 144, 61));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy);
        nameLabel->setMinimumSize(QSize(144, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        nameLabel->setAlignment(Qt::AlignCenter);
        callcode = new QLineEdit(IndividualEditView);
        callcode->setObjectName(QString::fromUtf8("callcode"));
        callcode->setEnabled(true);
        callcode->setGeometry(QRect(520, 110, 240, 40));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(callcode->sizePolicy().hasHeightForWidth());
        callcode->setSizePolicy(sizePolicy1);
        callcode->setMinimumSize(QSize(0, 40));
        callcode->setFocusPolicy(Qt::NoFocus);
        callcode->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"color: rgb(190,190,190);"));
        callcode->setAlignment(Qt::AlignCenter);
        name = new QLineEdit(IndividualEditView);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(40, 110, 240, 40));
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setMinimumSize(QSize(240, 40));
        name->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"color: rgb(190,190,190);"));
        name->setAlignment(Qt::AlignCenter);
        callcodeLabel = new QLabel(IndividualEditView);
        callcodeLabel->setObjectName(QString::fromUtf8("callcodeLabel"));
        callcodeLabel->setGeometry(QRect(570, 40, 144, 61));
        sizePolicy.setHeightForWidth(callcodeLabel->sizePolicy().hasHeightForWidth());
        callcodeLabel->setSizePolicy(sizePolicy);
        callcodeLabel->setMinimumSize(QSize(144, 61));
        callcodeLabel->setStyleSheet(QString::fromUtf8("border-image: url(:/images/Ellipse_144_61);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183);"));
        callcodeLabel->setAlignment(Qt::AlignCenter);
        controlWidget = new QWidget(IndividualEditView);
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
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Active, QIcon::On);
        icon2.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeTBnt->setIcon(icon2);
        homeTBnt->setIconSize(QSize(56, 42));
        homeTBnt->setPopupMode(QToolButton::DelayedPopup);
        homeTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        stationTBnt = new QToolButton(controlWidget);
        stationTBnt->setObjectName(QString::fromUtf8("stationTBnt"));
        stationTBnt->setGeometry(QRect(663, 0, 111, 61));
        stationTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Normal, QIcon::On);
        icon3.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        stationTBnt->setIcon(icon3);
        stationTBnt->setIconSize(QSize(18, 31));
        stationTBnt->setPopupMode(QToolButton::DelayedPopup);
        stationTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        individualTBnt = new QToolButton(controlWidget);
        individualTBnt->setObjectName(QString::fromUtf8("individualTBnt"));
        individualTBnt->setEnabled(false);
        individualTBnt->setGeometry(QRect(450, 0, 151, 61));
        individualTBnt->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Disabled, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        individualTBnt->setIcon(icon4);
        individualTBnt->setIconSize(QSize(25, 31));
        individualTBnt->setPopupMode(QToolButton::DelayedPopup);
        individualTBnt->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        widget = new ContactsInput(IndividualEditView);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(390, 230, 166, 40));
        widget_2 = new ContactsInput(IndividualEditView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(590, 230, 166, 40));
        txHeader = new QLineEdit(IndividualEditView);
        txHeader->setObjectName(QString::fromUtf8("txHeader"));
        txHeader->setEnabled(false);
        txHeader->setGeometry(QRect(390, 176, 166, 40));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txHeader->sizePolicy().hasHeightForWidth());
        txHeader->setSizePolicy(sizePolicy2);
        txHeader->setMinimumSize(QSize(80, 40));
        txHeader->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"color: rgb(190,190,190);\n"
"background-color: rgb(19, 57, 75);"));
        txHeader->setAlignment(Qt::AlignCenter);
        txHeader->setReadOnly(true);
        rxHeader = new QLineEdit(IndividualEditView);
        rxHeader->setObjectName(QString::fromUtf8("rxHeader"));
        rxHeader->setEnabled(false);
        rxHeader->setGeometry(QRect(590, 176, 166, 40));
        sizePolicy2.setHeightForWidth(rxHeader->sizePolicy().hasHeightForWidth());
        rxHeader->setSizePolicy(sizePolicy2);
        rxHeader->setMinimumSize(QSize(80, 40));
        rxHeader->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"color: rgb(190,190,190);\n"
"background-color: rgb(19, 57, 75);"));
        rxHeader->setAlignment(Qt::AlignCenter);
        rxHeader->setReadOnly(true);
        channel2 = new QLineEdit(IndividualEditView);
        channel2->setObjectName(QString::fromUtf8("channel2"));
        channel2->setGeometry(QRect(190, 284, 166, 40));
        sizePolicy2.setHeightForWidth(channel2->sizePolicy().hasHeightForWidth());
        channel2->setSizePolicy(sizePolicy2);
        channel2->setMinimumSize(QSize(80, 40));
        QFont font;
        font.setPointSize(15);
        channel2->setFont(font);
        channel2->setFocusPolicy(Qt::NoFocus);
        channel2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        channel2->setAlignment(Qt::AlignCenter);
        no2 = new QLineEdit(IndividualEditView);
        no2->setObjectName(QString::fromUtf8("no2"));
        no2->setGeometry(QRect(49, 284, 121, 40));
        sizePolicy2.setHeightForWidth(no2->sizePolicy().hasHeightForWidth());
        no2->setSizePolicy(sizePolicy2);
        no2->setMinimumSize(QSize(20, 40));
        no2->setFont(font);
        no2->setFocusPolicy(Qt::NoFocus);
        no2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        no2->setAlignment(Qt::AlignCenter);
        channelHeader = new QLineEdit(IndividualEditView);
        channelHeader->setObjectName(QString::fromUtf8("channelHeader"));
        channelHeader->setEnabled(false);
        channelHeader->setGeometry(QRect(190, 176, 166, 40));
        sizePolicy2.setHeightForWidth(channelHeader->sizePolicy().hasHeightForWidth());
        channelHeader->setSizePolicy(sizePolicy2);
        channelHeader->setMinimumSize(QSize(80, 40));
        channelHeader->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"color: rgb(190,190,190);\n"
"background-color: rgb(19, 57, 75);"));
        channelHeader->setAlignment(Qt::AlignCenter);
        channelHeader->setReadOnly(true);
        no = new QLineEdit(IndividualEditView);
        no->setObjectName(QString::fromUtf8("no"));
        no->setGeometry(QRect(49, 230, 121, 40));
        sizePolicy2.setHeightForWidth(no->sizePolicy().hasHeightForWidth());
        no->setSizePolicy(sizePolicy2);
        no->setMinimumSize(QSize(20, 40));
        no->setFont(font);
        no->setFocusPolicy(Qt::NoFocus);
        no->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        no->setAlignment(Qt::AlignCenter);
        channel3 = new QLineEdit(IndividualEditView);
        channel3->setObjectName(QString::fromUtf8("channel3"));
        channel3->setGeometry(QRect(190, 338, 166, 40));
        sizePolicy2.setHeightForWidth(channel3->sizePolicy().hasHeightForWidth());
        channel3->setSizePolicy(sizePolicy2);
        channel3->setMinimumSize(QSize(80, 40));
        channel3->setFont(font);
        channel3->setFocusPolicy(Qt::NoFocus);
        channel3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        channel3->setAlignment(Qt::AlignCenter);
        rx1 = new QLineEdit(IndividualEditView);
        rx1->setObjectName(QString::fromUtf8("rx1"));
        rx1->setEnabled(false);
        rx1->setGeometry(QRect(590, 230, 166, 40));
        sizePolicy2.setHeightForWidth(rx1->sizePolicy().hasHeightForWidth());
        rx1->setSizePolicy(sizePolicy2);
        rx1->setMinimumSize(QSize(80, 40));
        rx1->setFont(font);
        rx1->setFocusPolicy(Qt::NoFocus);
        rx1->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx1->setAlignment(Qt::AlignCenter);
        channel1 = new QLineEdit(IndividualEditView);
        channel1->setObjectName(QString::fromUtf8("channel1"));
        channel1->setGeometry(QRect(190, 230, 166, 40));
        sizePolicy2.setHeightForWidth(channel1->sizePolicy().hasHeightForWidth());
        channel1->setSizePolicy(sizePolicy2);
        channel1->setMinimumSize(QSize(80, 40));
        channel1->setFont(font);
        channel1->setFocusPolicy(Qt::NoFocus);
        channel1->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        channel1->setAlignment(Qt::AlignCenter);
        noHeader = new QLineEdit(IndividualEditView);
        noHeader->setObjectName(QString::fromUtf8("noHeader"));
        noHeader->setEnabled(false);
        noHeader->setGeometry(QRect(49, 176, 121, 40));
        noHeader->setMinimumSize(QSize(20, 40));
        noHeader->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";\n"
"background-color: rgb(19, 57, 75);\n"
"\n"
"\n"
"color: rgb(190,190,190);\n"
""));
        noHeader->setAlignment(Qt::AlignCenter);
        noHeader->setReadOnly(true);
        no3 = new QLineEdit(IndividualEditView);
        no3->setObjectName(QString::fromUtf8("no3"));
        no3->setGeometry(QRect(49, 338, 121, 40));
        sizePolicy2.setHeightForWidth(no3->sizePolicy().hasHeightForWidth());
        no3->setSizePolicy(sizePolicy2);
        no3->setMinimumSize(QSize(20, 40));
        no3->setFont(font);
        no3->setFocusPolicy(Qt::NoFocus);
        no3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        no3->setAlignment(Qt::AlignCenter);
        tx1 = new QLineEdit(IndividualEditView);
        tx1->setObjectName(QString::fromUtf8("tx1"));
        tx1->setEnabled(false);
        tx1->setGeometry(QRect(390, 230, 166, 40));
        sizePolicy2.setHeightForWidth(tx1->sizePolicy().hasHeightForWidth());
        tx1->setSizePolicy(sizePolicy2);
        tx1->setMinimumSize(QSize(80, 40));
        tx1->setFont(font);
        tx1->setFocusPolicy(Qt::NoFocus);
        tx1->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx1->setAlignment(Qt::AlignCenter);
        widget_3 = new ContactsInput(IndividualEditView);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(390, 284, 166, 40));
        widget_4 = new ContactsInput(IndividualEditView);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(590, 284, 166, 40));
        widget_5 = new ContactsInput(IndividualEditView);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(390, 338, 166, 40));
        widget_6 = new ContactsInput(IndividualEditView);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(590, 338, 166, 40));
        tx2 = new QLineEdit(IndividualEditView);
        tx2->setObjectName(QString::fromUtf8("tx2"));
        tx2->setEnabled(false);
        tx2->setGeometry(QRect(390, 284, 166, 40));
        sizePolicy2.setHeightForWidth(tx2->sizePolicy().hasHeightForWidth());
        tx2->setSizePolicy(sizePolicy2);
        tx2->setMinimumSize(QSize(80, 40));
        tx2->setFont(font);
        tx2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx2->setAlignment(Qt::AlignCenter);
        tx3 = new QLineEdit(IndividualEditView);
        tx3->setObjectName(QString::fromUtf8("tx3"));
        tx3->setEnabled(false);
        tx3->setGeometry(QRect(390, 338, 166, 40));
        sizePolicy2.setHeightForWidth(tx3->sizePolicy().hasHeightForWidth());
        tx3->setSizePolicy(sizePolicy2);
        tx3->setMinimumSize(QSize(80, 40));
        tx3->setFont(font);
        tx3->setFocusPolicy(Qt::NoFocus);
        tx3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx3->setAlignment(Qt::AlignCenter);
        rx2 = new QLineEdit(IndividualEditView);
        rx2->setObjectName(QString::fromUtf8("rx2"));
        rx2->setEnabled(false);
        rx2->setGeometry(QRect(590, 284, 166, 40));
        sizePolicy2.setHeightForWidth(rx2->sizePolicy().hasHeightForWidth());
        rx2->setSizePolicy(sizePolicy2);
        rx2->setMinimumSize(QSize(80, 40));
        rx2->setFont(font);
        rx2->setFocusPolicy(Qt::NoFocus);
        rx2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx2->setAlignment(Qt::AlignCenter);
        rx3 = new QLineEdit(IndividualEditView);
        rx3->setObjectName(QString::fromUtf8("rx3"));
        rx3->setEnabled(false);
        rx3->setGeometry(QRect(590, 338, 166, 40));
        sizePolicy2.setHeightForWidth(rx3->sizePolicy().hasHeightForWidth());
        rx3->setSizePolicy(sizePolicy2);
        rx3->setMinimumSize(QSize(80, 40));
        rx3->setFont(font);
        rx3->setFocusPolicy(Qt::NoFocus);
        rx3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx3->setAlignment(Qt::AlignCenter);
        controlWidget->raise();
        tiltewidget->raise();
        gridLayoutWidget_2->raise();
        horizontalLayoutWidget_2->raise();
        horizontalLayoutWidget_3->raise();
        arrowUpButton->raise();
        arrowDownButton->raise();
        nameLabel->raise();
        callcode->raise();
        name->raise();
        callcodeLabel->raise();
        widget->raise();
        widget_2->raise();
        txHeader->raise();
        rxHeader->raise();
        channel2->raise();
        no2->raise();
        channelHeader->raise();
        no->raise();
        channel3->raise();
        rx1->raise();
        channel1->raise();
        noHeader->raise();
        no3->raise();
        tx1->raise();
        widget_3->raise();
        widget_4->raise();
        widget_5->raise();
        widget_6->raise();
        tx2->raise();
        tx3->raise();
        rx2->raise();
        rx3->raise();

        retranslateUi(IndividualEditView);

        QMetaObject::connectSlotsByName(IndividualEditView);
    } // setupUi

    void retranslateUi(QWidget *IndividualEditView)
    {
        IndividualEditView->setWindowTitle(QApplication::translate("IndividualEditView", "Form", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("IndividualEditView", "&Ok", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("IndividualEditView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        nameLabel->setText(QApplication::translate("IndividualEditView", "Name", 0, QApplication::UnicodeUTF8));
        callcodeLabel->setText(QApplication::translate("IndividualEditView", "Callcode", 0, QApplication::UnicodeUTF8));
        homeTBnt->setText(QApplication::translate("IndividualEditView", "&Home", 0, QApplication::UnicodeUTF8));
        stationTBnt->setText(QApplication::translate("IndividualEditView", "&Station", 0, QApplication::UnicodeUTF8));
        individualTBnt->setText(QApplication::translate("IndividualEditView", "Individual", 0, QApplication::UnicodeUTF8));
        txHeader->setText(QApplication::translate("IndividualEditView", "Tx(KHz)", 0, QApplication::UnicodeUTF8));
        rxHeader->setText(QApplication::translate("IndividualEditView", "Rx(KHz)", 0, QApplication::UnicodeUTF8));
        channelHeader->setText(QApplication::translate("IndividualEditView", "Channel", 0, QApplication::UnicodeUTF8));
        noHeader->setText(QApplication::translate("IndividualEditView", "NO.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IndividualEditView: public Ui_IndividualEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDIVIDUALEDITVIEW_H
