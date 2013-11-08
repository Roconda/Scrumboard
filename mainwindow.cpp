#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "sbi.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    BurndownChart *r1 = new BurndownChart(this); r1->show();
}

void MainWindow::on_sbiOverview_clicked()
{
    SBI *sbi1 = new SBI(); sbi1->show();
}
