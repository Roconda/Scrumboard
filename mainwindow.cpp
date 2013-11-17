#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "userstorydelegate.h"
#include "sbi.h"
#include "adddefect.h"
#include "sbilistmodel.h"

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

    // instellen test data voor Not started SBI's
    SBIListModel *model = new SBIListModel();
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
    r1->show();
}

void MainWindow::on_sbiOverview_clicked()
{
    SBI *sbi1 = new SBI();
    sbi1->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    AddDefect *ad = new AddDefect();
    ad->exec();
}
