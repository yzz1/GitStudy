/********************************************************************************
** Form generated from reading UI file 'callcommunicationwidget.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLCOMMUNICATIONWIDGET_H
#define UI_CALLCOMMUNICATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CallCommunicationwidget
{
public:
    QLabel *lab_Title;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *arrowUpButton;
    QPushButton *arrowDownButton;
    QTableView *tableView;
    QTableView *tableView_2;

    void setupUi(QWidget *CallCommunicationwidget)
    {
        if (CallCommunicationwidget->objectName().isEmpty())
            CallCommunicationwidget->setObjectName(QString::fromUtf8("CallCommunicationwidget"));
        CallCommunicationwidget->resize(680, 400);
        CallCommunicationwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 89, 104);"));
        lab_Title = new QLabel(CallCommunicationwidget);
        lab_Title->setObjectName(QString::fromUtf8("lab_Title"));
        lab_Title->setGeometry(QRect(0, 0, 681, 31));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        lab_Title->setFont(font);
        lab_Title->setStyleSheet(QString::fromUtf8("color:white;"));
        lab_Title->setAlignment(Qt::AlignCenter);
        line = new QFrame(CallCommunicationwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 681, 5));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(CallCommunicationwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(340, 35, 5, 310));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(CallCommunicationwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 340, 681, 5));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        okBtn = new QPushButton(CallCommunicationwidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(50, 350, 85, 28));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn->setFocusPolicy(Qt::NoFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: rgb(255, 255, 255);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:rgb(86, 74, 74);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);
        okBtn->setIconSize(QSize(20, 20));
        cancelBtn = new QPushButton(CallCommunicationwidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(540, 350, 85, 28));
        cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
        cancelBtn->setFocusPolicy(Qt::NoFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"color: rgb(255, 255, 255);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"    color:rgb(86, 74, 74);\n"
"}\n"
"QPushButton:focus{\n"
"    color:white;\n"
"}\n"
"\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        cancelBtn->setIconSize(QSize(20, 20));
        arrowUpButton = new QPushButton(CallCommunicationwidget);
        arrowUpButton->setObjectName(QString::fromUtf8("arrowUpButton"));
        arrowUpButton->setGeometry(QRect(250, 330, 30, 15));
        arrowUpButton->setFocusPolicy(Qt::NoFocus);
        arrowUpButton->setAutoFillBackground(false);
        arrowUpButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_up_gray);\n"
"selection-background-color: url(:/images/Arrow_up_white);"));
        arrowDownButton = new QPushButton(CallCommunicationwidget);
        arrowDownButton->setObjectName(QString::fromUtf8("arrowDownButton"));
        arrowDownButton->setGeometry(QRect(410, 330, 30, 15));
        arrowDownButton->setFocusPolicy(Qt::NoFocus);
        arrowDownButton->setAutoFillBackground(false);
        arrowDownButton->setStyleSheet(QString::fromUtf8("    border: none;\n"
"background-image: url(:/images/Arrow_down_gray);\n"
"selection-background-color: url(:/images/Arrow_down_white);"));
        tableView = new QTableView(CallCommunicationwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 40, 331, 271));
        tableView->setFocusPolicy(Qt::TabFocus);
        tableView->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
" color: gray;\n"
"background: transparent;\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
"    border:none;\n"
"}\n"
""));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setAutoScroll(true);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setTabKeyNavigation(false);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setMinimumSectionSize(61);
        tableView->verticalHeader()->setDefaultSectionSize(27);
        tableView_2 = new QTableView(CallCommunicationwidget);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(350, 40, 331, 271));
        tableView_2->setFocusPolicy(Qt::TabFocus);
        tableView_2->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
" color: gray;\n"
"background: transparent;\n"
"selection-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 60, 76, 255), stop:1 rgba(7, 61, 82, 255));\n"
"selection-color: rgb(255, 255, 255);\n"
"font: 16pt \"Ubuntu\";\n"
"    border:none;\n"
"}\n"
""));
        tableView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView_2->setAutoScroll(true);
        tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_2->setTabKeyNavigation(false);
        tableView_2->setShowGrid(false);
        tableView_2->setWordWrap(true);
        tableView_2->horizontalHeader()->setVisible(false);
        tableView_2->horizontalHeader()->setMinimumSectionSize(61);
        tableView_2->verticalHeader()->setDefaultSectionSize(27);

        retranslateUi(CallCommunicationwidget);

        QMetaObject::connectSlotsByName(CallCommunicationwidget);
    } // setupUi

    void retranslateUi(QWidget *CallCommunicationwidget)
    {
        CallCommunicationwidget->setWindowTitle(QApplication::translate("CallCommunicationwidget", "Form", 0, QApplication::UnicodeUTF8));
        lab_Title->setText(QApplication::translate("CallCommunicationwidget", "title", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("CallCommunicationwidget", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("CallCommunicationwidget", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        arrowUpButton->setText(QString());
        arrowDownButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CallCommunicationwidget: public Ui_CallCommunicationwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLCOMMUNICATIONWIDGET_H
