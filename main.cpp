#include "nachokno.h"
#include <dobpolzovat.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    nachokno w;
    w.show();
    return a.exec();
}
