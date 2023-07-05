#include "admins.h"
#include "ui_admins.h"


admins::admins(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admins) {
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

    editS = new dobSOTRUDN(this);
    editS->setParent(this, Qt::Window);

    editinf = new dobINFO();
    editinf->setParent(this, Qt::Window);

    editOTV = new dobOTV();
    editOTV->setParent(this, Qt::Window);

    bazadannih = QSqlDatabase::addDatabase("QSQLITE");
    bazadannih.setDatabaseName("./marskikbarsik.db");
    if(!bazadannih.open())
        qDebug()<<bazadannih.lastError().text();
    else
        qDebug()<<"БАЗА ДАННЫХ ОТКРЫТА! ДАВАЙ РАБОТАЙ!";
    query = new QSqlQuery(bazadannih);

    query->exec("CREATE TABLE PERSONAL("
                " СОТРУДНИК TEXT PRIMARY KEY,"
                " ТЕЛЕФОН TEXT NOT NULL,"
                " ЭЛ_ПОЧТА TEXT NOT NULL,"
                " ГРАФИК_РАБОТЫ TEXT NOT NULL);");

    query->exec("CREATE TABLE POLZOVAT("
                " ИМЯ_ФАМИЛИЯ_КЛИЕНТА TEXT PRIMARY KEY,"
                " НОМЕР_ТЕЛЕФОНА TEXT NOT NULL,"
                " ЭЛ_ПОЧТА TEXT NOT NULL);");

    query->exec("CREATE TABLE INFORMATION"
                "(ТЕМА TEXT,"
                " СОТРУДНИК TEXT,"
                " ДАТА_СОЗДАНИЯ TEXT NOT NULL,"
                " ИНФОРМАЦИЯ TEXT NOT NULL, "
                "FOREIGN KEY (СОТРУДНИК) REFERENCES PERSONAL(СОТРУДНИК));");

    query->exec("CREATE TABLE FEEDBACK("
                " ИМЯ_ФАМИЛИЯ_КЛИЕНТА TEXT,"
                " НОМЕР_ТЕЛЕФОНА TEXT,"
                " ЭЛ_ПОЧТА TEXT,"
                " ОБРАЩЕНИЕ_КЛИЕТА TEXT NOT NULL,"
                " СОТРУДНИК TEXT,"
                " ОТВЕТ_СОТРУДНИКА TEXT,"
                "FOREIGN KEY (ИМЯ_ФАМИЛИЯ_КЛИЕНТА) REFERENCES POLZOVAT(ИМЯ_ФАМИЛИЯ_КЛИЕНТА),"
                "FOREIGN KEY (СОТРУДНИК) REFERENCES PERSONAL(СОТРУДНИК));");

    model = new QSqlTableModel(this,bazadannih);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    qquery = new QSqlQueryModel;}


admins::~admins()
{
    delete ui;
}


int k = 0;
void admins::on_personal_clicked()
{
    //QHeaderView::Stretch
    k = 1;
    model->setTable("PERSONAL");
    model->select();
    editS->setModel(model);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ


}
void admins::on_information_clicked()
{
    k = 2;
    model->setTable("INFORMATION");
    model->select();
    editinf->setModel(model);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);





}
void admins::on_feedback_clicked()
{

    k = 3;
    model->setTable("FEEDBACK");
    model->select();
    editOTV->setModel(model);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->setColumnHidden(1,true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableView->setColumnHidden(4,true);
    ui->tableView->setColumnHidden(5,true);

}
void admins::on_dobavlPOLZ_clicked()
{
    addpolz.show();
}
void admins::on_nazad_clicked()
{
    this->close();
    emit firstWindow();
}
void admins::on_vihod_clicked()
{
    out.show();
}
void admins::on_saveedit_clicked()
{    model->submitAll();}
void admins::on_undoedits_clicked()
{    model->revertAll();}
void admins::on_saveedit_2_clicked()
{model->select();}
void admins::on_addline_clicked()
{if(k == 1 || k == 2) qDebug() << "СТРОКА ДЛЯ ЗАПОЛЕНИЯ ДОБАВЛЕНИА!" << model ->insertRow(model->rowCount());}
void admins::on_delline_clicked(){
    int sr = ui->tableView->currentIndex().row();
    if (sr >=0){qDebug() << "УДАЛЕНИЕ СТРОКИ" << model->removeRow(sr);}
    else{qDebug() << "СТРОКА НЕ НАЙДЕНА";}
}
void admins::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(k == 1){
        editS -> mapper -> setCurrentModelIndex(index);
        editS->setWindowFlag(Qt::FramelessWindowHint,true);
        editS->show();}

    if(k == 2){
        editinf -> mapper -> setCurrentModelIndex(index);
        editinf->setWindowFlag(Qt::FramelessWindowHint,true);
        editinf->show();}

    if(k == 3){
        editOTV -> mapper -> setCurrentModelIndex(index);
        editOTV->setWindowFlag(Qt::FramelessWindowHint,true);
        editOTV->show();}
}
void admins::on_pushButton_clicked()
{   QSqlQuery qry1;
   if(ui -> personal->isChecked()){
       if(ui->col1->isChecked()){
           qry1.prepare( "SELECT СОТРУДНИК, ТЕЛЕФОН, ЭЛ_ПОЧТА, ГРАФИК_РАБОТЫ FROM PERSONAL WHERE СОТРУДНИК  LIKE :IO " );
           qry1.bindValue(":IO", ui->lineEdit->text()+ '%');}
       if(ui->radioButton_2->isChecked()){
           qry1.prepare( "SELECT СОТРУДНИК, ТЕЛЕФОН, ЭЛ_ПОЧТА, ГРАФИК_РАБОТЫ FROM PERSONAL WHERE ТЕЛЕФОН  LIKE:IO " );
           qry1.bindValue(":IO", ui->lineEdit->text() + '%');}
       qry1.exec();
       qquery -> setQuery(qry1);
       model->setTable("PERSONAL");
       model->select();
       editS->setModel(model);
       ui->tableView->setModel(qquery);
       ui->tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
       ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
       ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);   //РАСТЯГИВАЕТ ПЕРВУЮ СЕКЦИЮ ТАБЛИЦЫ
       ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents); }

   if(ui -> information->isChecked()){

       if(ui->col1->isChecked()){
           qry1.prepare( "SELECT ТЕМА, СОТРУДНИК, ДАТА_СОЗДАНИЯ, ИНФОРМАЦИЯ FROM INFORMATION WHERE ТЕМА LIKE :tema  " );
           qry1.bindValue(":tema", ui->lineEdit->text()+ '%');}
       if(ui->radioButton_2->isChecked()){
           qry1.prepare( "SELECT ТЕМА, СОТРУДНИК, ДАТА_СОЗДАНИЯ, ИНФОРМАЦИЯ FROM INFORMATION WHERE СОТРУДНИК LIKE  :tema  " );
           qry1.bindValue(":tema", ui->lineEdit->text()+ '%');}

       qry1.exec();
       qquery -> setQuery(qry1);
       model->setTable("INFORMATION");
       model->select();
       editinf->setModel(model);
       ui->tableView->setModel(qquery);
       ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
       ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
       ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
       ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);}

   if(ui -> feedback->isChecked()){
       if(ui->col1->isChecked()){
           qry1.prepare( "SELECT ИМЯ_ФАМИЛИЯ_КЛИЕНТА, НОМЕР_ТЕЛЕФОНА, ЭЛ_ПОЧТА, ОБРАЩЕНИЕ_КЛИЕНТА, СОТРУДНИК, ОТВЕТ_СОТРУДНИКА FROM FEEDBACK WHERE ИМЯ_ФАМИЛИЯ_КЛИЕНТА  LIKE :cl " );
           qry1.bindValue(":cl", ui->lineEdit->text()+ '%');}
       if(ui->radioButton_2->isChecked()){
           qry1.prepare( "SELECT ИМЯ_ФАМИЛИЯ_КЛИЕНТА, НОМЕР_ТЕЛЕФОНА, ЭЛ_ПОЧТА, ОБРАЩЕНИЕ_КЛИЕНТА, СОТРУДНИК, ОТВЕТ_СОТРУДНИКА FROM FEEDBACK WHERE НОМЕР_ТЕЛЕФОНА  LIKE :cl " );
           qry1.bindValue(":cl", ui->lineEdit->text()+ '%');}

           qry1.exec();
           qquery -> setQuery(qry1);
           ui->tableView->setModel(qquery);

           model->setTable("FEEDBACK");
           model->select();
           editOTV->setModel(model);
           ui->tableView->setModel(model);
           ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
           ui->tableView->setColumnHidden(1,true);
           ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
           ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
           ui->tableView->setColumnHidden(4,true);
           ui->tableView->setColumnHidden(5,true);
       }
}

