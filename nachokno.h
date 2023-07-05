#ifndef NACHOKNO_H
#define NACHOKNO_H

#include <QMainWindow>
#include "avtorizat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class nachokno; }
QT_END_NAMESPACE

class nachokno : public QMainWindow
{
    Q_OBJECT

public:
    nachokno(QWidget *parent = nullptr);
    ~nachokno();
    avtorizat avt;

private slots:
    void on_pushButton_clicked();


private:
    Ui::nachokno *ui;
};
#endif // NACHOKNO_H
