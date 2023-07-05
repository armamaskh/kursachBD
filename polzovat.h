#ifndef POLZOVAT_H
#define POLZOVAT_H

#include <QMainWindow>
#include<vohod.h>
#include"support.h"
#include<QWidget>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QtDebug>
#include<QSqlError>
#include<QSqlRecord>
#include<QString>
#include<QTableView>
#include<QHeaderView>
#include<dobvoprOTV.h>
#include<inform.h>
#include<dobclient.h>



namespace Ui {
class polzovat;
}

class polzovat : public QMainWindow
{
    Q_OBJECT

public:
    explicit polzovat(QWidget *parent = nullptr);
    ~polzovat();
    vohod out;
    support help;


signals:
    void firstWindow();

private slots:
    void on_nazad_clicked();

    void on_vihod_clicked();

    void on_obn_clicked();

    void on_personal_clicked();

    void on_information_clicked();

    void on_feedback_clicked();

    void on_dobavlinf_clicked();

    void on_udaleninf_clicked();

    void on_udaleninf_2_clicked();

    void on_obn_2_clicked();

    void on_obn_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_polzz_clicked();

private:
    Ui::polzovat *ui;
    QSqlDatabase bazadannih;
    QSqlQuery *query;
    QSqlTableModel *model;
    dobpolzovat addpolz;

    dobVOPROTV *editVO;
    inform *editinform;
    dobclient *editclient;

};

#endif // POLZOVAT_H
