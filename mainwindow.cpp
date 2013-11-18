#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "sbi.h"
#include "adddefect.h"
#include "sbinotstartedlistmodel.h"
#include "laneui.h"
#include "itemui.h"

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

    SBINotStartedListModel *model = new SBINotStartedListModel();

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

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
    SBI *sbi1 = new SBI(this);
    sbi1->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    AddDefect *ad = new AddDefect(this);
    ad->exec();
}
