#ifndef DOBCLIENT_H
#define DOBCLIENT_H

#include <QMainWindow>
#include<QDataWidgetMapper>


namespace Ui {
class dobclient;
}

class dobclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit dobclient(QWidget *parent = nullptr);
    ~dobclient();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:
    void on_pushButton_clicked();

    void on_nazad_clicked();

private:
    Ui::dobclient *ui;
};

#endif // DOBCLIENT_H
