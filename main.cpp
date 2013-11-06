#include "mainwindow.h"
#include <QApplication>

#include <QSplitter>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    QApplication app(argc, argv); // de app, deze heb je altijd
    QSplitter *splitter = new QSplitter; // een QSplitter widget

    QFileSystemModel *model = new QFileSystemModel; // een standaard model, QFileSystemModel. Hier definieer je geen data, enkel een path
    /* Een model in Qt is eigenlijk een manier voor communiceren met de view. Een model kan zelf weer een data source hebben, wat in onze termen weer het 'model' is. */
    model->setRootPath(QDir::currentPath());

    // Dit is een Tree view widget. Let op dat als argument de parent meegegeven wordt bij constructie. Dit is in dit geval de Splitter.
    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model); // ook hier wordt het model ingesteld, we hebben meerdere views met eenzelfde model.
    tree->setRootIndex(model->index(QDir::currentPath())); // views maken gebruik van model indexes

    // Zelfde verhaal, nu met een ander soort widget, met hetzelfde model.
    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    // Een splitter is een frame, hier kan de windowtitle van worden ingesteld.
    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->show(); // show moet aangeroepen worden.
    return app.exec();
}
