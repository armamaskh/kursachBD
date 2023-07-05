#include "inform.h"
#include "ui_inform.h"

inform::inform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inform)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

inform::~inform()
{
    delete ui;
}

void inform::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->tema,0);
    mapper->addMapping(ui->autor,1);
    mapper->addMapping(ui->date,2);
    mapper->addMapping(ui->inf,3,"plainText");

}


void inform::on_clcl_clicked()
{
    close();
}

