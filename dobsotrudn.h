#ifndef DOBSOTRUDN_H
#define DOBSOTRUDN_H

#include <QMainWindow>
#include<QDataWidgetMapper>

namespace Ui {
class dobSOTRUDN;
}

class dobSOTRUDN : public QMainWindow
{
    Q_OBJECT

public:
    explicit dobSOTRUDN(QWidget *parent = nullptr);
    ~dobSOTRUDN();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:
    void on_pushButton_clicked();

    void on_nazad_clicked();

private:
    Ui::dobSOTRUDN *ui;
};

#endif // DOBSOTRUDN_H
