#include "mainwindow.h"
#include "defect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Defect d;
    d.show();

    return a.exec();
}
