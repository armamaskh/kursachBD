#ifndef SUPPORT_H
#define SUPPORT_H

#include <QMainWindow>

namespace Ui {
class support;
}

class support : public QMainWindow
{
    Q_OBJECT

public:
    explicit support(QWidget *parent = nullptr);
    ~support();

private slots:
    void on_pushButton_clicked();

private:
    Ui::support *ui;
};

#endif // SUPPORT_H
