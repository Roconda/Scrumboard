#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "userstorydelegate.h"
#include "sbi.h"

#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // instellen test data voor user stories
    QStringListModel *model = new QStringListModel();
    QStringList list;
    list << "Test";
    model->setStringList(list);

    ui->userStoriesList->setModel(model);
    // Stel de delegate in, deze doet custom view.
    ui->userStoriesList->setItemDelegate(new userStoryDelegate);
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
