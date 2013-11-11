#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "userstorydelegate.h"
#include "sbi.h"

#include "TFS/TFSTransaction.h"

#include <QStringListModel>
#include <algorithm>
#include <iostream>
#include <string>

using std::for_each;
using std::string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // instellen test data voor user stories
    QStringListModel *model = new QStringListModel();
    QStringList list;

    /* TFS test! */
    std::list<string>              saFilenameList;
    std::list<string>::iterator    iList;
    string                         sFilename;

    TFSTransaction::remoteListProjects( saFilenameList );
    for_each(begin(saFilenameList), end(saFilenameList), [&](string s) {
        list << s.c_str();
    });
    /* Einde TFS test */

    model->setStringList(list);

    ui->userStoriesList->setModel(model);
    // Stel de delegate in, deze doet custom view.
    //ui->userStoriesList->setItemDelegate(new userStoryDelegate);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    BurndownChart *r1 = new BurndownChart(this);
    r1->exec();
}

void MainWindow::on_sbiOverview_clicked()
{
    SBI *sbi1 = new SBI();
    sbi1->exec();
}
