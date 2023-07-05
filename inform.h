#ifndef INFORM_H
#define INFORM_H

#include <QMainWindow>
#include<QDataWidgetMapper>

namespace Ui {
class inform;
}

class inform : public QMainWindow
{
    Q_OBJECT

public:
    explicit inform(QWidget *parent = nullptr);
    ~inform();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:

    void on_clcl_clicked();

private:
    Ui::inform *ui;
};

#endif // INFORM_H
