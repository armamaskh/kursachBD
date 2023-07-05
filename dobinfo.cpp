#include "dobinfo.h"
#include "ui_dobinfo.h"

dobINFO::dobINFO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobINFO)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

dobINFO::~dobINFO()
{
    delete ui;
}
void dobINFO::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->tema,0);
    mapper->addMapping(ui->sotr,1);
    mapper->addMapping(ui->date,2);
    mapper->addMapping(ui->inf,3,"plainText");

}
void dobINFO::on_pushButton_clicked()
{
        mapper->submit();
        close();
}
void dobINFO::on_nazad_clicked()
{
    close();
}

