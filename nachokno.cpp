#include "nachokno.h"
#include "ui_nachokno.h"

nachokno::nachokno(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::nachokno)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}

nachokno::~nachokno()
{
    delete ui;
}


void nachokno::on_pushButton_clicked()
{
    avt.show();
    hide();
}

