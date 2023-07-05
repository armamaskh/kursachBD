#include "support.h"
#include "ui_support.h"
#include<QDir>
#include <QDebug>
#include<QFile>
#include<QTextStream>
support::support(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::support)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    QPainterPath painPath;
    painPath.addRoundedRect(rect(), 30, 30, Qt::AbsoluteSize);
    this->setMask(painPath.toFillPolygon().toPolygon());

}

support::~support()
{
    delete ui;
}

void support::on_pushButton_clicked()
{
    QFile M("TEHPODDERZHKA.txt");
    if(!M.open(QFile::WriteOnly | QFile::Text) ){
        return;}
    else {
        QTextStream out(&M);
    out << "___ТЕХНИЧЕСКАЯ ПОДДЕРЖКА____________________________"<<"\n\n";
    out << "_________________________________________ОБРАЩЕНИЕ_№"<<"__\n\n";
    out <<"\t"<< ui-> IMYA->text() << "\n";
    out <<"\t"<< ui-> TEXT->text() << "\n";
    out <<"\t\t\t\t                        "<< ui-> DATA->text() << "\n";
    out << "________________________________________________________";
    M.close();
    close();
    }
}

