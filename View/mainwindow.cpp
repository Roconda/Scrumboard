#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "sbi.h"
#include "adddefect.h"
#include "../Model/sbilistmodel.h"
#include "../Model/pbilistmodel.h"
#include "../Model/userlistmodel.h"
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
    currentFilterChooserIndex = -1;

    // Stel het sprint nummer in.
    size_t sprintindex = TFSWrapper::instance().getSelectedSprintIndex();
    updateSprintIndex(sprintindex);

    this->setStyleSheet("QPushButton, QComboBox, QSlider, QLineEdit { padding: 8 8 8 8 } ");

    ui->filterChooser->setCurrentIndex(0);

    // Edit scrollbar's item count to the amount of sprints
    int sprintSize = 0;
    for(Sprint* sprint : TFSWrapper::instance().getSelectedProject()->getSprintArray()) if(sprint != NULL) sprintSize++;


    ui->sprintSlider->setRange(0, sprintSize-1);
    ui->sprintSlider->setValue(sprintindex);

    // set PBIListmodel to PBIcombobox
    PBIListModel *pbilm = new PBIListModel();
    ui->PBIcombobox->setModel(pbilm);

    // set UserListmodel to userComboBox
    UserListModel *ulm = new UserListModel();
    ui->userComboBox->setModel(ulm);
    ui->userComboBox->setCurrentIndex(0);
    ui->userComboBox->setCurrentIndex(TFSWrapper::instance().getSelectedUserIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSprintIndex(int newposition)
{
    TFSWrapper::instance().setSelectedSprint(newposition);

    QString msg = QString("Sprint #%1").arg(newposition+1);

    ui->widget->Reload();
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
    ui->PBIcombobox->setCurrentIndex(0);
    TFSWrapper::instance().setSelectedPBI(0);
    ui->PBIcombobox->update();
}

void MainWindow::on_PBIcombobox_currentIndexChanged(int index)
{
    TFSWrapper::instance().setSelectedPBI(index);
    ui->widget->updateSprintData();
}

void MainWindow::on_lineEdit_returnPressed()
{
    ui->widget->updateSprintData();
}

void MainWindow::on_filterChooser_currentIndexChanged(int index)
{
    currentFilterChooserIndex = index;
}

void MainWindow::on_btn_clear_clicked()
{
    ui->widget->ClearFilterOptions();
    ui->widget->updateSprintData();
}

void MainWindow::on_btn_filter_clicked()
{
    ui->widget->Reload();
    ui->widget->FilterIt(currentFilterChooserIndex, ui->lineEdit->text());
    ui->widget->updateSprintData();
}

void MainWindow::on_userComboBox_currentIndexChanged(int index)
{
    TFSWrapper &tfsp = TFSWrapper::instance();

    TFSWrapper::instance().setSelectedUser(index);
    ui->userComboBox->setCurrentIndex(index);
}
