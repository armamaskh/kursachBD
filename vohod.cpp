#include "vohod.h"
#include "ui_vohod.h"
#include <dobpolzovat.h>

vohod::vohod(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vohod)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}

vohod::~vohod()
{
    delete ui;
}

void vohod::on_vihod_clicked()
{
    addpolz->saveLP();
    QApplication::quit();
}


void vohod::on_nazad_clicked()
{

}

