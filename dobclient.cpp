#include "dobclient.h"
#include "ui_dobclient.h"

dobclient::dobclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobclient)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

dobclient::~dobclient()
{
    delete ui;
}


void dobclient::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->IO,0);
    mapper->addMapping(ui->NOMERTELEF,1);
    mapper->addMapping(ui->EMAIL,2);

}
void dobclient::on_pushButton_clicked()
{
        mapper->submit();
        close();
}
void dobclient::on_nazad_clicked()
{
    close();
}

