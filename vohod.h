#ifndef VOHOD_H
#define VOHOD_H

#include <QMainWindow>
#include <dobpolzovat.h>


namespace Ui {
class vohod;
}

class vohod : public QMainWindow
{
    Q_OBJECT

public:
    explicit vohod(QWidget *parent = nullptr);
    ~vohod();
    dobpolzovat *addpolz;

private slots:
    void on_vihod_clicked();

    void on_nazad_clicked();

private:
    Ui::vohod *ui;
};

#endif // VOHOD_H
