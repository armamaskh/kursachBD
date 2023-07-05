#ifndef DOBOTV_H
#define DOBOTV_H

#include <QMainWindow>
#include<QDataWidgetMapper>

namespace Ui {
class dobOTV;
}

class dobOTV : public QMainWindow
{
    Q_OBJECT

public:
    explicit dobOTV(QWidget *parent = nullptr);
    ~dobOTV();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:
    void on_pushButton_clicked();

    void on_nazad_clicked();

private:
    Ui::dobOTV *ui;
};

#endif // DOBOTV_H
