/********************************************************************************
** Form generated from reading UI file 'scangroupview.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANGROUPVIEW_H
#define UI_SCANGROUPVIEW_H

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
#include "widgets/titlewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScanGroupView
{
public:
    TitleWidget *titleWidget;
    QWidget *controlWidget;
    QToolButton *homeBtn;
    QToolButton *receiveBtn;
    QPushButton *editBnt;
    QPushButton *deleteBnt;
    QPushButton *startBnt;
    QPushButton *stopBnt;
    QFrame *Contactsline;
    QLabel *nameLabel;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
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
    QFrame *line_2;
    QTableView *tableView;
    QPushButton *arrowUpButton_2;
    QPushButton *arrowDownButton_2;
    QPushButton *newBnt;

    void setupUi(QWidget *ScanGroupView)
    {
        if (ScanGroupView->objectName().isEmpty())
            ScanGroupView->setObjectName(QString::fromUtf8("ScanGroupView"));
        ScanGroupView->resize(800, 544);
        titleWidget = new TitleWidget(ScanGroupView);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));
        titleWidget->setGeometry(QRect(0, 0, 800, 45));
        controlWidget = new QWidget(ScanGroupView);
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
"    outline: none;  \n"
"  color:rgb(86, 74, 74);\n"
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
        icon1.addFile(QString::fromUtf8(":/images/images/Scan_ICO_SelYes.png"), QSize(), QIcon::Normal, QIcon::On);
        icon1.addFile(QString::fromUtf8(":/images/images/station_gray.png"), QSize(), QIcon::Selected, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/images/images/individual_white.png"), QSize(), QIcon::Selected, QIcon::On);
        receiveBtn->setIcon(icon1);
        receiveBtn->setIconSize(QSize(40, 40));
        receiveBtn->setPopupMode(QToolButton::DelayedPopup);
        receiveBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        editBnt = new QPushButton(ScanGroupView);
        editBnt->setObjectName(QString::fromUtf8("editBnt"));
        editBnt->setGeometry(QRect(110, 420, 64, 36));
        editBnt->setFocusPolicy(Qt::NoFocus);
        editBnt->setAutoFillBackground(false);
        editBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        editBnt->setCheckable(true);
        deleteBnt = new QPushButton(ScanGroupView);
        deleteBnt->setObjectName(QString::fromUtf8("deleteBnt"));
        deleteBnt->setGeometry(QRect(190, 420, 85, 36));
        deleteBnt->setFocusPolicy(Qt::NoFocus);
        deleteBnt->setAutoFillBackground(false);
        deleteBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        deleteBnt->setCheckable(true);
        startBnt = new QPushButton(ScanGroupView);
        startBnt->setObjectName(QString::fromUtf8("startBnt"));
        startBnt->setGeometry(QRect(590, 420, 64, 36));
        startBnt->setFocusPolicy(Qt::NoFocus);
        startBnt->setAutoFillBackground(false);
        startBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        startBnt->setCheckable(true);
        stopBnt = new QPushButton(ScanGroupView);
        stopBnt->setObjectName(QString::fromUtf8("stopBnt"));
        stopBnt->setGeometry(QRect(690, 420, 64, 36));
        stopBnt->setFocusPolicy(Qt::NoFocus);
        stopBnt->setAutoFillBackground(false);
        stopBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        stopBnt->setCheckable(true);
        Contactsline = new QFrame(ScanGroupView);
        Contactsline->setObjectName(QString::fromUtf8("Contactsline"));
        Contactsline->setGeometry(QRect(0, 410, 800, 5));
        Contactsline->setFrameShape(QFrame::HLine);
        Contactsline->setFrameShadow(QFrame::Sunken);
        nameLabel = new QLabel(ScanGroupView);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(30, 70, 181, 61));
        nameLabel->setStyleSheet(QString::fromUtf8("background-image: url(:/images/manager_File_dateTimeEllipse);\n"
"background-image-size:100px 200px;\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(183, 183, 183); "));
        nameLabel->setAlignment(Qt::AlignCenter);
        arrowUpButton = new QPushButton(ScanGroupView);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(50, 390, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(ScanGroupView);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(130, 390, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        tx = new QLineEdit(ScanGroupView);
        tx->setObjectName(QString::fromUtf8("tx"));
        tx->setGeometry(QRect(410, 100, 140, 40));
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
        tx_2 = new QLineEdit(ScanGroupView);
        tx_2->setObjectName(QString::fromUtf8("tx_2"));
        tx_2->setEnabled(false);
        tx_2->setGeometry(QRect(410, 150, 140, 40));
        sizePolicy.setHeightForWidth(tx_2->sizePolicy().hasHeightForWidth());
        tx_2->setSizePolicy(sizePolicy);
        tx_2->setMinimumSize(QSize(80, 40));
        QFont font1;
        font1.setPointSize(15);
        tx_2->setFont(font1);
        tx_2->setFocusPolicy(Qt::ClickFocus);
        tx_2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_2->setAlignment(Qt::AlignCenter);
        tx_3 = new QLineEdit(ScanGroupView);
        tx_3->setObjectName(QString::fromUtf8("tx_3"));
        tx_3->setEnabled(false);
        tx_3->setGeometry(QRect(410, 200, 140, 40));
        sizePolicy.setHeightForWidth(tx_3->sizePolicy().hasHeightForWidth());
        tx_3->setSizePolicy(sizePolicy);
        tx_3->setMinimumSize(QSize(80, 40));
        tx_3->setFont(font1);
        tx_3->setFocusPolicy(Qt::ClickFocus);
        tx_3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_3->setAlignment(Qt::AlignCenter);
        tx_4 = new QLineEdit(ScanGroupView);
        tx_4->setObjectName(QString::fromUtf8("tx_4"));
        tx_4->setEnabled(false);
        tx_4->setGeometry(QRect(410, 250, 140, 40));
        sizePolicy.setHeightForWidth(tx_4->sizePolicy().hasHeightForWidth());
        tx_4->setSizePolicy(sizePolicy);
        tx_4->setMinimumSize(QSize(80, 40));
        tx_4->setFont(font1);
        tx_4->setFocusPolicy(Qt::ClickFocus);
        tx_4->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_4->setAlignment(Qt::AlignCenter);
        rx = new QLineEdit(ScanGroupView);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(580, 100, 140, 40));
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
        rx_2 = new QLineEdit(ScanGroupView);
        rx_2->setObjectName(QString::fromUtf8("rx_2"));
        rx_2->setEnabled(false);
        rx_2->setGeometry(QRect(580, 150, 140, 40));
        sizePolicy.setHeightForWidth(rx_2->sizePolicy().hasHeightForWidth());
        rx_2->setSizePolicy(sizePolicy);
        rx_2->setMinimumSize(QSize(80, 40));
        rx_2->setFont(font1);
        rx_2->setFocusPolicy(Qt::ClickFocus);
        rx_2->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_2->setAlignment(Qt::AlignCenter);
        rx_3 = new QLineEdit(ScanGroupView);
        rx_3->setObjectName(QString::fromUtf8("rx_3"));
        rx_3->setEnabled(false);
        rx_3->setGeometry(QRect(580, 200, 140, 40));
        sizePolicy.setHeightForWidth(rx_3->sizePolicy().hasHeightForWidth());
        rx_3->setSizePolicy(sizePolicy);
        rx_3->setMinimumSize(QSize(80, 40));
        rx_3->setFont(font1);
        rx_3->setFocusPolicy(Qt::ClickFocus);
        rx_3->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_3->setAlignment(Qt::AlignCenter);
        rx_4 = new QLineEdit(ScanGroupView);
        rx_4->setObjectName(QString::fromUtf8("rx_4"));
        rx_4->setEnabled(false);
        rx_4->setGeometry(QRect(580, 250, 140, 40));
        sizePolicy.setHeightForWidth(rx_4->sizePolicy().hasHeightForWidth());
        rx_4->setSizePolicy(sizePolicy);
        rx_4->setMinimumSize(QSize(80, 40));
        rx_4->setFont(font1);
        rx_4->setFocusPolicy(Qt::ClickFocus);
        rx_4->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_4->setAlignment(Qt::AlignCenter);
        rx_5 = new QLineEdit(ScanGroupView);
        rx_5->setObjectName(QString::fromUtf8("rx_5"));
        rx_5->setEnabled(false);
        rx_5->setGeometry(QRect(580, 300, 140, 40));
        sizePolicy.setHeightForWidth(rx_5->sizePolicy().hasHeightForWidth());
        rx_5->setSizePolicy(sizePolicy);
        rx_5->setMinimumSize(QSize(80, 40));
        rx_5->setFont(font1);
        rx_5->setFocusPolicy(Qt::ClickFocus);
        rx_5->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        rx_5->setAlignment(Qt::AlignCenter);
        tx_5 = new QLineEdit(ScanGroupView);
        tx_5->setObjectName(QString::fromUtf8("tx_5"));
        tx_5->setEnabled(false);
        tx_5->setGeometry(QRect(410, 300, 140, 40));
        sizePolicy.setHeightForWidth(tx_5->sizePolicy().hasHeightForWidth());
        tx_5->setSizePolicy(sizePolicy);
        tx_5->setMinimumSize(QSize(80, 40));
        tx_5->setFont(font1);
        tx_5->setFocusPolicy(Qt::ClickFocus);
        tx_5->setStyleSheet(QString::fromUtf8("color:rgb(190,190,190)"));
        tx_5->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(ScanGroupView);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(250, 140, 2, 211));
        line_2->setStyleSheet(QString::fromUtf8("background:rgb(105, 115, 119);"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::VLine);
        tableView = new QTableView(ScanGroupView);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(39, 149, 200, 200));
        tableView->setFocusPolicy(Qt::StrongFocus);
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
        arrowUpButton_2 = new QPushButton(ScanGroupView);
        arrowUpButton_2->setObjectName(QString::fromUtf8("arrowUpButton_2"));
        arrowUpButton_2->setGeometry(QRect(500, 390, 30, 15));
        arrowUpButton_2->setFocusPolicy(Qt::NoFocus);
        arrowUpButton_2->setAutoFillBackground(false);
        arrowUpButton_2->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton_2 = new QPushButton(ScanGroupView);
        arrowDownButton_2->setObjectName(QString::fromUtf8("arrowDownButton_2"));
        arrowDownButton_2->setGeometry(QRect(600, 390, 30, 15));
        arrowDownButton_2->setFocusPolicy(Qt::NoFocus);
        arrowDownButton_2->setAutoFillBackground(false);
        arrowDownButton_2->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        newBnt = new QPushButton(ScanGroupView);
        newBnt->setObjectName(QString::fromUtf8("newBnt"));
        newBnt->setGeometry(QRect(30, 420, 64, 36));
        newBnt->setFocusPolicy(Qt::NoFocus);
        newBnt->setAutoFillBackground(false);
        newBnt->setStyleSheet(QString::fromUtf8("QPushButton{    border: none;\n"
"    border-radius:10px;\n"
"	color:rgb(86, 74, 74);\n"
"    border-radius:10px;\n"
"	background-color: rgb(16, 34, 56);\n"
"	font: 18pt \"Ubuntu\";\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}"));
        newBnt->setCheckable(true);

        retranslateUi(ScanGroupView);

        QMetaObject::connectSlotsByName(ScanGroupView);
    } // setupUi

    void retranslateUi(QWidget *ScanGroupView)
    {
        ScanGroupView->setWindowTitle(QApplication::translate("ScanGroupView", "Form", 0, QApplication::UnicodeUTF8));
        homeBtn->setText(QApplication::translate("ScanGroupView", "&Home", 0, QApplication::UnicodeUTF8));
        receiveBtn->setText(QApplication::translate("ScanGroupView", "Scan", 0, QApplication::UnicodeUTF8));
        editBnt->setText(QApplication::translate("ScanGroupView", "&Edit", 0, QApplication::UnicodeUTF8));
        deleteBnt->setText(QApplication::translate("ScanGroupView", "&Delete", 0, QApplication::UnicodeUTF8));
        startBnt->setText(QApplication::translate("ScanGroupView", "&Start", 0, QApplication::UnicodeUTF8));
        stopBnt->setText(QApplication::translate("ScanGroupView", "S&top", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ScanGroupView", "Group Name", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
        tx->setText(QApplication::translate("ScanGroupView", "Tx(KHz)", 0, QApplication::UnicodeUTF8));
        rx->setText(QApplication::translate("ScanGroupView", "Rx(KHz)", 0, QApplication::UnicodeUTF8));
        arrowUpButton_2->setText(QString());
        arrowDownButton_2->setText(QString());
        newBnt->setText(QApplication::translate("ScanGroupView", "Ne&w", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ScanGroupView: public Ui_ScanGroupView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANGROUPVIEW_H
