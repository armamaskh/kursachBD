#include "polzovat.h"
#include "ui_polzovat.h"

polzovat::polzovat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::polzovat)
{
        ui->setupUi(this);

    editVO = new dobVOPROTV(this);
    editVO->setParent(this, Qt::Window);


    editinform = new inform(this);
    editinform->setParent(this, Qt::Window);

    editclient = new dobclient(this);
    editclient->setParent(this, Qt::Window);


    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());
    bazadannih = QSqlDatabase::database("./marskikbarsik.db");
    if(!bazadannih.open())
        qDebug()<<bazadannih.lastError().text();
    else
        qDebug()<<"БАЗА ДАННЫХ ОТКРЫТА! ДАВАЙ РАБОТАЙ!";

    model = new QSqlTableModel(this,bazadannih);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);



}

int t = 0;

void polzovat::on_polzz_clicked()
{
    t = 4;
    model->setTable("POLZOVAT");
    model->select();
    ui->tableView->setModel(model);
    editclient->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ

}
void polzovat::on_personal_clicked()
{
    t = 1;
    model->setTable("PERSONAL");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);


}
void polzovat::on_information_clicked()
{
    t = 2;
    model->setTable("INFORMATION");
    model->select();
    ui->tableView->setModel(model);
    editinform->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

}
void polzovat::on_feedback_clicked()
{
    t = 3;
    model->setTable("FEEDBACK");
    model->select();
    ui->tableView->setModel(model);
    editVO->setModel(model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(4,  QHeaderView::Stretch);
    ui->tableView->setColumnHidden(1,true);
    ui->tableView->setColumnHidden(2,true);
    ui->tableView->setColumnHidden(5,true);
}
polzovat::~polzovat()
{
    delete ui;
}
void polzovat::on_nazad_clicked()
{
    close();
    emit firstWindow();
}
void polzovat::on_vihod_clicked()
{
    out.show();
}
void polzovat::on_obn_clicked()
{
    help.show();
}
void polzovat::on_dobavlinf_clicked()
{
    if (t == 2){
        editinform->show();
    }
    if (t == 3)
        editVO->show();
    if (t == 4)
        editclient->show();
}
void polzovat::on_udaleninf_clicked()
{
    if (t == 3)
        qDebug() << "СТРОКА ДЛЯ ДОБАВЛЕНИЯ ВОПРОСА ДОБАВЛЕНА!" << model -> insertRow(model->rowCount());
    if (t == 4)
        qDebug() << "СТРОКА ДЛЯ ДОБАВЛЕНИЯ КЛИЕНТА ДОБАВЛЕНА!" << model -> insertRow(model->rowCount());
}
void polzovat::on_udaleninf_2_clicked()
{
    if (t == 3){
        int sr = ui->tableView->currentIndex().row();
        if (sr >=0)
            qDebug() << "УДАЛЕНИЕ СТРОКИ" << model->removeRow(sr);
        else
            qDebug() << "СТРОКА НЕ НАЙДЕНА";}
    if (t == 4){
        int sr = ui->tableView->currentIndex().row();
        if (sr >=0)
            qDebug() << "УДАЛЕНИЕ СТРОКИ" << model->removeRow(sr);
        else
            qDebug() << "СТРОКА НЕ НАЙДЕНА";}
}
void polzovat::on_obn_2_clicked()
{
    model->submitAll();}
void polzovat::on_obn_3_clicked()
{
    model->select();
}
void polzovat::on_tableView_clicked(const QModelIndex &index)
{
    if (t == 2 ){
        editinform -> mapper -> setCurrentModelIndex(index);
        editinform->setWindowFlag(Qt::FramelessWindowHint,true);
}
    if (t == 3 ){
        editVO -> mapper -> setCurrentModelIndex(index);
        editVO->setWindowFlag(Qt::FramelessWindowHint,true);
    }
    if (t == 4 ){
        editclient -> mapper -> setCurrentModelIndex(index);
        editclient->setWindowFlag(Qt::FramelessWindowHint,true);
    }


}


