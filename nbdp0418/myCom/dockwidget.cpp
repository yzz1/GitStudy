#include "dockwidget.h"
#include "ui_dockwidget.h"

DockWidget::DockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DockWidget)
{
    ui->setupUi(this);
}

DockWidget::~DockWidget()
{
    delete ui;
}
void DockWidget::setConnectState(int flag) // 0 disconnect ; 1 connected
  {
    QPalette pe;


    if(flag ==0)
    {
        pe.setColor(QPalette::WindowText,Qt::red);
        ui->label->setPalette(pe);
        ui->label->setText(tr("disconnected"));
    }else
    {
        pe.setColor(QPalette::WindowText,Qt::green);
        ui->label->setPalette(pe);
        ui->label->setText(tr("connected"));
    }

  }
void DockWidget::insertDebugInfo(QString str)
{
    ui->textBrowser->append(str);
    ui->textBrowser->moveCursor(QTextCursor::End);
}
