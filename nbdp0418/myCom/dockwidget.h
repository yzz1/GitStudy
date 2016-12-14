#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QtGui/QDockWidget>
#include <QtGui/QPalette>

namespace Ui {
class DockWidget;
}

class DockWidget : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit DockWidget(QWidget *parent = 0);
    ~DockWidget();
    void setConnectState(int flag); // 0 disconnect ; 1 connected
    void insertDebugInfo(QString str);
private:
    Ui::DockWidget *ui;

};

#endif // DOCKWIDGET_H
