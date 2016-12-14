/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created: Wed May 4 11:49:55 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Title;
    QWidget *widget_main;
    QFrame *line;
    QFrame *line_2;
    QLineEdit *lineEdit;
    QPushButton *cancelBtn;
    QPushButton *okBtn;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QString::fromUtf8("InputDialog"));
        InputDialog->resize(493, 251);
        InputDialog->setFocusPolicy(Qt::NoFocus);
        InputDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 89, 104);"));
        widget_title = new QWidget(InputDialog);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setGeometry(QRect(0, 2, 493, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_title->sizePolicy().hasHeightForWidth());
        widget_title->setSizePolicy(sizePolicy);
        widget_title->setMinimumSize(QSize(100, 28));
        horizontalLayout_2 = new QHBoxLayout(widget_title);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lab_Title = new QLabel(widget_title);
        lab_Title->setObjectName(QString::fromUtf8("lab_Title"));
        lab_Title->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lab_Title->setFont(font);
        lab_Title->setStyleSheet(QString::fromUtf8("font: 22pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        lab_Title->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lab_Title);

        widget_main = new QWidget(InputDialog);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));
        widget_main->setEnabled(true);
        widget_main->setGeometry(QRect(0, 41, 493, 210));
        widget_main->setFocusPolicy(Qt::NoFocus);
        widget_main->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(widget_main);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 5, 493, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widget_main);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 124, 493, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(widget_main);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 431, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font1);
        lineEdit->setFocusPolicy(Qt::TabFocus);
        lineEdit->setStyleSheet(QString::fromUtf8(" border: none;\n"
" border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Ubuntu\";"));
        cancelBtn = new QPushButton(widget_main);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(320, 160, 86, 28));
        cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
        cancelBtn->setFocusPolicy(Qt::TabFocus);
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    color:rgb(86, 74, 74);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.46, y1:0.017, x2:0.49, y2:1, stop:0 rgba(122, 124, 125, 255), stop:0.95 rgba(108, 131, 140, 255));\n"
"}\n"
"\n"
"QPushButton:focus{\n"
"    color:white;\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon);
        cancelBtn->setIconSize(QSize(20, 20));
        okBtn = new QPushButton(widget_main);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(81, 160, 85, 28));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn->setFocusPolicy(Qt::TabFocus);
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    color:rgb(86, 74, 74);\n"
" border: none;\n"
" border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.46, y1:0.017, x2:0.49, y2:1, stop:0 rgba(122, 124, 125, 255), stop:0.95 rgba(108, 131, 140, 255));\n"
"}\n"
"\n"
"QPushButton:focus{\n"
"    color:white;\n"
"\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon1);
        okBtn->setIconSize(QSize(20, 20));
        QWidget::setTabOrder(lineEdit, okBtn);
        QWidget::setTabOrder(okBtn, cancelBtn);

        retranslateUi(InputDialog);

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lab_Title->setText(QApplication::translate("InputDialog", "title", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        cancelBtn->setText(QApplication::translate("InputDialog", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("InputDialog", "&OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
