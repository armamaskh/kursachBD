#ifndef DOBVOPROTV_H
#define DOBVOPROTV_H

#include <QMainWindow>
#include<QDataWidgetMapper>

namespace Ui {
class dobVOPROTV;
}

class dobVOPROTV : public QMainWindow
{
    Q_OBJECT

public:
    explicit dobVOPROTV(QWidget *parent = nullptr);
    ~dobVOPROTV();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;


private slots:
    void on_pushButton_clicked();

    void on_nazad_clicked();

private:
    Ui::dobVOPROTV *ui;
};

#endif // DOBVOPROTV_H
