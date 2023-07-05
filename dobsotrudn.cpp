#include "dobsotrudn.h"
#include "ui_dobsotrudn.h"

dobSOTRUDN::dobSOTRUDN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobSOTRUDN)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}

dobSOTRUDN::~dobSOTRUDN()
{
    delete ui;
}

void dobSOTRUDN::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->IO,0);
    mapper->addMapping(ui->NOMERTELEF,1);
    mapper->addMapping(ui->EMAIL,2);
    mapper->addMapping(ui->GRAFIK,3);

}
void dobSOTRUDN::on_pushButton_clicked()
{
        mapper->submit();
        close();
}
void dobSOTRUDN::on_nazad_clicked()
{
    close();
}

