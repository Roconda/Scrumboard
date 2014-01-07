#include "View/mainwindow.h"
#include <QApplication>

#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
