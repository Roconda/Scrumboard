#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "sbi.h"
#include "adddefect.h"
#include "../Model/sbilistmodel.h"
#include "../Model/pbilistmodel.h"
#include "../itemhandler.h"
#include "../tfswrapper.h"
#include "../TFS/Project.h"
#include "../TFS/Sprint.h"
#include "../TFS/User.h"
#include "../tfswrapper.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentFilterChooserIndex = 0;

    // Stel het sprint nummer in.
    size_t sprintindex = TFSWrapper::instance().getSelectedSprintIndex();
    updateSprintIndex(sprintindex);

    this->setStyleSheet("QPushButton, QComboBox, QSlider, QLineEdit { padding: 8 8 8 8 } ");

    // Edit scrollbar's item count to the amount of sprints
    int sprintSize = 0;
    for(Sprint* sprint : TFSWrapper::instance().getSelectedProject()->getSprintArray()) if(sprint != NULL) sprintSize++;


    ui->sprintSlider->setRange(0, sprintSize-1);
    ui->sprintSlider->setValue(sprintindex);

    // add PBIListmodel to PBIcombobox
    PBIListModel *pbilm = new PBIListModel();
    ui->PBIcombobox->setModel(pbilm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSprintIndex(int newposition)
{
    TFSWrapper::instance().setSelectedSprint(newposition);

    QString msg = QString("Sprint #%1").arg(newposition+1);

    ui->widget->updateSprintData();
    ui->sprint_titleLabel->setText(msg);
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

void MainWindow::on_sprintSlider_valueChanged(int value)
{
    updateSprintIndex(value);
    TFSWrapper::instance().setSelectedPBI(0);
    ui->PBIcombobox->update();
}

void MainWindow::on_PBIcombobox_currentIndexChanged(int index)
{
    TFSWrapper::instance().setSelectedPBI(index-1);
    ui->widget->updateSprintData(currentFilterChooserIndex, ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
    ui->widget->updateSprintData(currentFilterChooserIndex, ui->lineEdit->text());
}

void MainWindow::on_filterChooser_currentIndexChanged(int index)
{
    currentFilterChooserIndex = index;
}

void MainWindow::on_btn_clear_clicked()
{
    ui->widget->ClearFilterOptions();
}

void MainWindow::on_btn_filter_clicked()
{
    ui->widget->FilterIt();
}

void MainWindow::on_test_clicked()
{
    ui->widget->Reload();
    ui->widget->updateSprintData();
}
