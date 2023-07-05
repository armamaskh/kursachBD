#ifndef ADMINS_H
#define ADMINS_H

#include <QMainWindow>
#include <dobpolzovat.h>
#include<vohod.h>
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

#include<dobinfo.h>
#include<dobsotrudn.h>
#include<dobotv.h>
#include<QSqlRecord>
#include<QSqlQueryModel>

namespace Ui {
class admins;
}

class admins : public QMainWindow
{
    Q_OBJECT

public:
    explicit admins(QWidget *parent = nullptr);
    ~admins();


signals:
    void firstWindow();

private slots:
    void on_dobavlPOLZ_clicked();

    void on_nazad_clicked();

    void on_vihod_clicked();

    void on_saveedit_clicked();

    void on_undoedits_clicked();

    void on_saveedit_2_clicked();

    void on_addline_clicked();

    void on_delline_clicked();

    void on_personal_clicked();

    void on_information_clicked();

    void on_feedback_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::admins *ui;
    QSqlDatabase bazadannih;
    QSqlQuery *query;
    QSqlTableModel *model;
    QSqlQueryModel *qquery;
    dobpolzovat addpolz;
    vohod out;

    dobINFO *editinf;
    dobSOTRUDN *editS;
    dobOTV *editOTV;


};

#endif // ADMINS_H
