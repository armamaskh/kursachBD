#include "dobotv.h"
#include "ui_dobotv.h"

dobOTV::dobOTV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobOTV)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
}

dobOTV::~dobOTV()
{
    delete ui;
}

void dobOTV::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->IO,0);
    mapper->addMapping(ui->vopros,3);
    mapper->addMapping(ui->sotr,4);
    mapper->addMapping(ui->textEdit, 5,"plainText");



}
void dobOTV::on_pushButton_clicked()
{
    mapper->submit();
    dobOTV::close();
}
void dobOTV::on_nazad_clicked()
{
    dobOTV::close();
}
