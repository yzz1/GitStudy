#ifndef MAINTIMER_H
#define MAINTIMER_H

#include <QThread>

class MainWindow;
class MainTimer : public QThread
{
    Q_OBJECT
public:
    explicit MainTimer(QObject *parent = 0);
    

public:
        void setMessage(QString message);
        void stop();

protected:
        void run();
        void printMessage();

private:
        QString messageStr;
        volatile bool stopped;
         int m_mSec;

signals:
    
public slots:
    
};
extern MainWindow* g_mainWorkFlow;
#endif // MAINTIMER_H
