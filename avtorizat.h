#ifndef AVTORIZAT_H
#define AVTORIZAT_H

#include <QMainWindow>
#include "vohod.h"
#include<polzovat.h>
#include<admins.h>
#include"dobpolzovat.h"

namespace Ui {
class avtorizat;
}

class avtorizat : public QMainWindow
{
    Q_OBJECT

public:
    explicit avtorizat(QWidget *parent = nullptr);
    ~avtorizat();
    vohod out;
    dobpolzovat addpolz;


private slots:
    void on_vihodAVTORIZ_clicked();

    void on_AVTORIZ_clicked();

private:
    Ui::avtorizat *ui;
    admins *admin;
    polzovat *polz;


};

#endif // AVTORIZAT_H
