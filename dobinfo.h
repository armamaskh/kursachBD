#ifndef DOBINFO_H
#define DOBINFO_H

#include <QMainWindow>
#include<QDataWidgetMapper>

namespace Ui {
class dobINFO;
}

class dobINFO : public QMainWindow
{
    Q_OBJECT

public:
    explicit dobINFO(QWidget *parent = nullptr);
    ~dobINFO();
    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:
    void on_pushButton_clicked();

    void on_nazad_clicked();

private:
    Ui::dobINFO *ui;
};

#endif // DOBINFO_H
