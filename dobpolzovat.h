#ifndef DOBPOLZOVAT_H
#define DOBPOLZOVAT_H

#include <QMainWindow>
#include <dobpolzovat.h>


namespace Ui {
class dobpolzovat;
}

class dobpolzovat : public QMainWindow
{
    Q_OBJECT

public slots:
    int avtorizati(QString login,QString password);
public:
    explicit dobpolzovat(QWidget *parent = nullptr);
    ~dobpolzovat();
    void saveLP();


private slots:
    void on_dobavlPOLZ_clicked();

    void on_vihodAVTORIZ_clicked();

    void openLP();

private:
    Ui::dobpolzovat *ui;
};

#endif // DOBPOLZOVAT_H
