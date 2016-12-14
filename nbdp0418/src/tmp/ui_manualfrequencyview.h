/********************************************************************************
** Form generated from reading UI file 'manualfrequencyview.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALFREQUENCYVIEW_H
#define UI_MANUALFREQUENCYVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "widgets/frequencyinput.h"
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ManualFrequencyView
{
public:
    TitleWidget *titleWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *codelEdit;
    QLineEdit *channelEdit;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *nameEdit;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listWidget_2;
    QListWidget *listWidget_3;
    QListWidget *listWidget_4;
    QListWidget *listWidget_5;
    FrequencyInput *widget;
    FrequencyInput *widget_2;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QToolButton *callBtn;
    QFrame *line_;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *ManualFrequencyView)
    {
        if (ManualFrequencyView->objectName().isEmpty())
            ManualFrequencyView->setObjectName(QString::fromUtf8("ManualFrequencyView"));
        ManualFrequencyView->resize(800, 544);
        titleWidget = new TitleWidget(ManualFrequencyView);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 800, 45));
        gridLayoutWidget = new QWidget(ManualFrequencyView);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 50, 801, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        codelEdit = new QLineEdit(gridLayoutWidget);
        codelEdit->setObjectName(QString::fromUtf8("codelEdit"));
        codelEdit->setFocusPolicy(Qt::ClickFocus);
        codelEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"   padding: 5px;\n"
"   border: none;\n"
"	font-size: 20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QLineEdit::focus\n"
"{\n"
"   color:white;\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(95, 158, 160, 50), stop:1 rgba(95, 158, 160, 100));\n"
"}"));

        gridLayout->addWidget(codelEdit, 2, 3, 1, 1);

        channelEdit = new QLineEdit(gridLayoutWidget);
        channelEdit->setObjectName(QString::fromUtf8("channelEdit"));
        channelEdit->setFocusPolicy(Qt::ClickFocus);
        channelEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"   padding: 5px;\n"
"   border: none;\n"
"	font-size: 20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QLineEdit::focus\n"
"{\n"
"   color:white;\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(95, 158, 160, 50), stop:1 rgba(95, 158, 160, 100));\n"
"}"));

        gridLayout->addWidget(channelEdit, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        nameEdit->setMaximumSize(QSize(500, 16777215));
        nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"   padding: 5px;\n"
"   border: none;\n"
"	font-size: 20px;\n"
"   color:gray;\n"
"}\n"
"\n"
"QLineEdit::focus\n"
"{\n"
"   color:white;\n"
"   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(95, 158, 160, 50), stop:1 rgba(95, 158, 160, 100));\n"
"}"));

        gridLayout->addWidget(nameEdit, 0, 3, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMaximumSize(QSize(250, 40));
        listWidget->setFocusPolicy(Qt::NoFocus);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"   color:gray;\n"
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
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));

        gridLayout->addWidget(listWidget, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        listWidget_2 = new QListWidget(gridLayoutWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        sizePolicy1.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy1);
        listWidget_2->setMaximumSize(QSize(250, 40));
        listWidget_2->setFocusPolicy(Qt::NoFocus);
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"      color:gray;\n"
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
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));

        gridLayout->addWidget(listWidget_2, 1, 1, 1, 1);

        listWidget_3 = new QListWidget(gridLayoutWidget);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        sizePolicy1.setHeightForWidth(listWidget_3->sizePolicy().hasHeightForWidth());
        listWidget_3->setSizePolicy(sizePolicy1);
        listWidget_3->setMaximumSize(QSize(250, 40));
        listWidget_3->setFocusPolicy(Qt::NoFocus);
        listWidget_3->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"   color:gray;\n"
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
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));

        gridLayout->addWidget(listWidget_3, 2, 1, 1, 1);

        listWidget_4 = new QListWidget(gridLayoutWidget);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        sizePolicy1.setHeightForWidth(listWidget_4->sizePolicy().hasHeightForWidth());
        listWidget_4->setSizePolicy(sizePolicy1);
        listWidget_4->setMaximumSize(QSize(250, 40));
        listWidget_4->setFocusPolicy(Qt::NoFocus);
        listWidget_4->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"       color:gray;\n"
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
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));

        gridLayout->addWidget(listWidget_4, 3, 1, 1, 1);

        listWidget_5 = new QListWidget(gridLayoutWidget);
        listWidget_5->setObjectName(QString::fromUtf8("listWidget_5"));
        sizePolicy1.setHeightForWidth(listWidget_5->sizePolicy().hasHeightForWidth());
        listWidget_5->setSizePolicy(sizePolicy1);
        listWidget_5->setMaximumSize(QSize(250, 40));
        listWidget_5->setFocusPolicy(Qt::NoFocus);
        listWidget_5->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border:none;\n"
"    outline: none;\n"
"    icon-size: 40px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QListWidget::item{\n"
"   height:40px;\n"
"   color:gray;\n"
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
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"    border: none;\n"
"    outline: none;\n"
"    font: bold 25pt;\n"
"    color:white;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"}\n"
" "));

        gridLayout->addWidget(listWidget_5, 4, 1, 1, 1);

        widget = new FrequencyInput(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(140, 40));

        gridLayout->addWidget(widget, 3, 3, 1, 1);

        widget_2 = new FrequencyInput(gridLayoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(140, 40));

        gridLayout->addWidget(widget_2, 4, 3, 1, 1);

        controlWidget = new QWidget(ManualFrequencyView);
        controlWidget->setObjectName(QString::fromUtf8("controlWidget"));
        controlWidget->setGeometry(QRect(0, 470, 800, 72));
        controlWidget->setAutoFillBackground(false);
        controlWidget->setStyleSheet(QString::fromUtf8(" background-color:rgb(10,21,31);"));
        homeBtn = new QToolButton(controlWidget);
        homeBtn->setObjectName(QString::fromUtf8("homeBtn"));
        homeBtn->setGeometry(QRect(80, 0, 141, 61));
        homeBtn->setFocusPolicy(Qt::ClickFocus);
        homeBtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
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
        icon.addFile(QString::fromUtf8(":/images/home_normal"), QSize(), QIcon::Selected, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/images/home_hover"), QSize(), QIcon::Selected, QIcon::On);
        homeBtn->setIcon(icon);
        homeBtn->setIconSize(QSize(56, 42));
        homeBtn->setPopupMode(QToolButton::DelayedPopup);
        homeBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        receiveBtn = new QToolButton(controlWidget);
        receiveBtn->setObjectName(QString::fromUtf8("receiveBtn"));
        receiveBtn->setGeometry(QRect(640, 0, 141, 61));
        receiveBtn->setFocusPolicy(Qt::ClickFocus);
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
        callBtn->setFocusPolicy(Qt::ClickFocus);
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
        line_ = new QFrame(ManualFrequencyView);
        line_->setObjectName(QString::fromUtf8("line_"));
        line_->setGeometry(QRect(0, 400, 800, 16));
        line_->setStyleSheet(QString::fromUtf8("background:transparent;"));
        line_->setFrameShadow(QFrame::Plain);
        line_->setLineWidth(2);
        line_->setFrameShape(QFrame::HLine);
        horizontalLayoutWidget = new QWidget(ManualFrequencyView);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 420, 801, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        okBtn = new QPushButton(horizontalLayoutWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setFocusPolicy(Qt::ClickFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon3);

        horizontalLayout->addWidget(okBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        cancelBtn = new QPushButton(horizontalLayoutWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setFocusPolicy(Qt::ClickFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon4);

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        QWidget::setTabOrder(channelEdit, codelEdit);
        QWidget::setTabOrder(codelEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);
        QWidget::setTabOrder(cancelBtn, homeBtn);
        QWidget::setTabOrder(homeBtn, callBtn);
        QWidget::setTabOrder(callBtn, receiveBtn);

        retranslateUi(ManualFrequencyView);

        QMetaObject::connectSlotsByName(ManualFrequencyView);
    } // setupUi

    void retranslateUi(QWidget *ManualFrequencyView)
    {
        ManualFrequencyView->setWindowTitle(QApplication::translate("ManualFrequencyView", "Form", 0, QApplication::UnicodeUTF8));
        codelEdit->setText(QString());
        channelEdit->setText(QString());
        nameEdit->setText(QString());
        homeBtn->setText(QApplication::translate("ManualFrequencyView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("ManualFrequencyView", "&Receive", 0, QApplication::UnicodeUTF8));
        callBtn->setText(QApplication::translate("ManualFrequencyView", "&Transmit", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("ManualFrequencyView", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ManualFrequencyView", "Ca&ncel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManualFrequencyView: public Ui_ManualFrequencyView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALFREQUENCYVIEW_H
