#include "dobvoprOTV.h"
#include "ui_dobvoprotv.h"

dobVOPROTV::dobVOPROTV(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobVOPROTV)
{
    ui->setupUi(this);
        mapper = new QDataWidgetMapper(this);
        mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
        QPainterPath painPath;
        painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
        this->setMask(painPath.toFillPolygon().toPolygon());

}

dobVOPROTV::~dobVOPROTV()
{
    delete ui;
}

void dobVOPROTV::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->IO,0);
    mapper->addMapping(ui->NOMERTELEF,1);
    mapper->addMapping(ui->EMAIL,2);
    mapper->addMapping(ui->vopros,3);
    mapper->addMapping(ui->textEdit,5,"plainText");


}
void dobVOPROTV::on_pushButton_clicked()
{
    mapper->submit();
    close();

}
void dobVOPROTV::on_nazad_clicked()
{
    close();

}
