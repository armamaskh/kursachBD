#include "dobpolzovat.h"
#include "ui_dobpolzovat.h"
#include <QMap>
#include<QDir>
#include <QDebug>
#include<QFile>
#include<QDataStream>



QMap <int, QVector <QString>> LP; // СЛОВАРЬ С ЛОГИНАМИ И ПАРОЛЯМИ ДЛЯ АДМИНОВ И ПОЛЬЗОВАТЕЛЕЙ
int n = 0;


dobpolzovat::dobpolzovat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dobpolzovat)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}


dobpolzovat::~dobpolzovat()
{
    delete ui;
}


void dobpolzovat::openLP(){ // НАЧАЛЬЬНОЕ ОТКРЫТИЕ ФАЙЛА
    QDataStream io;
    QFile loginparol;
    loginparol.setFileName("C:/Users/Marsi/Desktop/BD/OTCHENASHKOTORYNANEBESAH/LP.txt");
    loginparol.open(QIODevice::WriteOnly|QIODevice::Append);
    if(loginparol.pos() == 0){
        LP[1].push_back("postavte");
        LP[1].push_back("pyat");
        LP[2].push_back("user");
        LP[2].push_back("user");
        loginparol.flush();
        loginparol.close();
    }
    else{
        loginparol.close();
        loginparol.open(QIODevice::ReadOnly);
        io.setDevice(&loginparol);
        io.setVersion(QDataStream::Qt_5_12);
        io >> LP;
        loginparol.flush();
        loginparol.close();
    }
}

int dobpolzovat::avtorizati(QString login, QString password) //
{
    if (n == 0)
        openLP();
    for (auto T:LP[1])
            for(int v = 0 ; v < LP[1].size() - 1; v++)
                if (LP[1][v] == login && LP[1][v+1] == password ){
                    n++;
                    return 1;}
    for (auto T:LP[2])
            for(int v = 0 ; v < LP[2].size() - 1; v++)
                if (LP[2][v] == login && LP[2][v+1] == password ){
                    n++;
                    return 2;}
}

void dobpolzovat::saveLP(){
    QDataStream p;
    QFile lp("C:/Users/Marsi/Desktop/BD/OTCHENASHKOTORYNANEBESAH/LP.txt");
    lp.open(QIODevice::WriteOnly |QIODevice::Truncate| QIODevice::Append);
    p.setDevice(&lp);
    p.setVersion(QDataStream::Qt_5_12);
    p << LP;
    lp.flush();
    lp.close();
}

void dobpolzovat::on_dobavlPOLZ_clicked()
{
    int i = 2;
    if (ui->addadmin->isChecked())
        i = 1;

    if (i == 1){
            LP[1].push_back(ui->login->text());
            LP[1].push_back(ui->password->text());}
    if (i == 2){
                LP[2].push_back(ui->login->text());
                LP[2].push_back(ui->password->text());}
    dobpolzovat::close();

}


void dobpolzovat::on_vihodAVTORIZ_clicked()
{
    dobpolzovat::close();
}


