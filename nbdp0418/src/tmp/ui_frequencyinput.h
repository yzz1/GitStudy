/********************************************************************************
** Form generated from reading UI file 'frequencyinput.ui'
**
** Created: Wed May 4 11:49:56 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCYINPUT_H
#define UI_FREQUENCYINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrequencyInput
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton;

    void setupUi(QWidget *FrequencyInput)
    {
        if (FrequencyInput->objectName().isEmpty())
            FrequencyInput->setObjectName(QString::fromUtf8("FrequencyInput"));
        FrequencyInput->resize(140, 40);
        lineEdit = new QLineEdit(FrequencyInput);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(0, 5, 20, 30));
        lineEdit->setFocusPolicy(Qt::NoFocus);
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
        lineEdit_2 = new QLineEdit(FrequencyInput);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 5, 20, 30));
        lineEdit_2->setFocusPolicy(Qt::NoFocus);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        lineEdit_3 = new QLineEdit(FrequencyInput);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(40, 5, 20, 30));
        lineEdit_3->setFocusPolicy(Qt::NoFocus);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        lineEdit_4 = new QLineEdit(FrequencyInput);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 5, 20, 30));
        lineEdit_4->setFocusPolicy(Qt::NoFocus);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        lineEdit_5 = new QLineEdit(FrequencyInput);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 5, 20, 30));
        lineEdit_5->setFocusPolicy(Qt::NoFocus);
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
        lineEdit_6 = new QLineEdit(FrequencyInput);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(90, 5, 20, 30));
        lineEdit_6->setFocusPolicy(Qt::NoFocus);
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
        lineEdit_7 = new QLineEdit(FrequencyInput);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 5, 20, 30));
        lineEdit_7->setFocusPolicy(Qt::NoFocus);
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
        lineEdit_8 = new QLineEdit(FrequencyInput);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(120, 5, 20, 30));
        lineEdit_8->setFocusPolicy(Qt::NoFocus);
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
        pushButton = new QPushButton(FrequencyInput);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 141, 41));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"    border: none;\n"
"    font-size: 16pt;\n"
"    color: rgb(105, 115, 119);\n"
""));

        retranslateUi(FrequencyInput);

        QMetaObject::connectSlotsByName(FrequencyInput);
    } // setupUi

    void retranslateUi(QWidget *FrequencyInput)
    {
        FrequencyInput->setWindowTitle(QApplication::translate("FrequencyInput", "Form", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit_3->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        lineEdit_6->setText(QString());
        lineEdit_7->setText(QString());
        lineEdit_8->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FrequencyInput: public Ui_FrequencyInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCYINPUT_H
