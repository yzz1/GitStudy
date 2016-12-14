/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QWidget *widget_main;
    QFrame *line_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widget_title;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lab_Title;
    QFrame *line;

    void setupUi(QDialog *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QString::fromUtf8("MessageDialog"));
        MessageDialog->resize(745, 295);
        MessageDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 89, 104);"));
        widget_main = new QWidget(MessageDialog);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));
        widget_main->setEnabled(true);
        widget_main->setGeometry(QRect(0, 40, 741, 260));
        widget_main->setStyleSheet(QString::fromUtf8(""));
        line_2 = new QFrame(widget_main);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(-200, 170, 941, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(widget_main);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 0, 231, 171));
        label_2 = new QLabel(widget_main);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 32, 30, 30));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/Call_Wait_flash")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(widget_main);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 70, 30, 30));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/Call_Wait_flash")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(widget_main);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 110, 30, 30));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/Call_Wait_flash")));
        label_4->setScaledContents(true);
        okBtn = new QPushButton(widget_main);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(80, 200, 85, 28));
        okBtn->setCursor(QCursor(Qt::PointingHandCursor));
        okBtn->setFocusPolicy(Qt::StrongFocus);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/OK.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);
        okBtn->setIconSize(QSize(20, 20));
        cancelBtn = new QPushButton(widget_main);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setGeometry(QRect(570, 200, 85, 28));
        cancelBtn->setCursor(QCursor(Qt::PointingHandCursor));
        cancelBtn->setFocusPolicy(Qt::StrongFocus);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cancel"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);
        cancelBtn->setIconSize(QSize(20, 20));
        label_5 = new QLabel(widget_main);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 60, 41, 51));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Call_Waiting_signs.png")));
        label_6 = new QLabel(widget_main);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 70, 71, 31));
        label_6->setStyleSheet(QString::fromUtf8("font: 57 22pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255)"));
        widget_title = new QWidget(MessageDialog);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setGeometry(QRect(0, 0, 761, 28));
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

        line = new QFrame(MessageDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 30, 741, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QDialog *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        widget_main->setAccessibleName(QApplication::translate("MessageDialog", ".", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("MessageDialog", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600; color:#f3efef;\">Terminal Unit Test</span></p><p><span style=\" font-size:16pt; font-weight:600; color:#f3efef;\">Receive Unit Test</span></p><p><span style=\" font-size:16pt; font-weight:600; color:#f3efef;\">Transmission Unit Test</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        okBtn->setText(QApplication::translate("MessageDialog", "&OK", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("MessageDialog", "Ca&ncel", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QString());
        lab_Title->setText(QApplication::translate("MessageDialog", "title", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
