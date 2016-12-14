#ifndef CALLPHRASEBOOKSTYLE_H
#define CALLPHRASEBOOKSTYLE_H

#include <QWidget>
#include <views/manager/managerfilestyle.h>

class CallPhraseBookStyle : public ContactsStyle
{
        Q_OBJECT
    public:
        CallPhraseBookStyle(QWidget* parent = 0);
};

#endif // CALLPHRASEBOOKSTYLE_H
