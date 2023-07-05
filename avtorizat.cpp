#include "avtorizat.h"
#include "ui_avtorizat.h"

#include"dobpolzovat.h"

avtorizat::avtorizat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::avtorizat)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

    admin = new admins();
    connect(admin, &admins::firstWindow,this, &QMainWindow::show);
    polz = new polzovat();
    connect(polz, &polzovat::firstWindow,this, &QMainWindow::show);

}

avtorizat::~avtorizat()
{
    delete ui;
}

void avtorizat::on_vihodAVTORIZ_clicked()
{
    out.show();
}


void avtorizat::on_AVTORIZ_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    int t = addpolz.avtorizati(login,password);

    switch(t){
    case 1:
        admin->show();
        this->close();
        break;
    case 2:
        polz->show();
        this->close();
        break;
    }

}

