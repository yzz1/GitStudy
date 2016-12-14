#ifndef RECETIMER_H
#define RECETIMER_H

#include <QThread>
class MainWindow;
class ReceTimer : public QThread
{
    Q_OBJECT
public:
    explicit ReceTimer(QObject *parent = 0);
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

#endif


