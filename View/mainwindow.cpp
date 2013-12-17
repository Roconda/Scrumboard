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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Stel het sprint nummer in.
    TFSWrapper wrapper = TFSWrapper::instance();
    size_t sprintindex = wrapper.getSelectedSprintIndex();
    updateSprintIndex(sprintindex);

    this->setStyleSheet("QPushButton, QComboBox, QSlider, QLineEdit { padding: 8 8 8 8 } ");

    // Edit scrollbar's item count to the amount of sprints
    int sprintSize = 0;
    for(Sprint* sprint : wrapper.getSelectedProject()->getSprintArray()) if(sprint != NULL) sprintSize++;

    ui->sprintSlider->setRange(1, sprintSize);
    ui->sprintSlider->setValue(sprintindex);

    // add PBIListmodel to PBIcombobox
    PBIListModel *pbilm = new PBIListModel();
    ui->PBIcombobox->setModel(pbilm);

    // TODO: move somewhere else
    for(User* user : wrapper.getAllUsers()) {
        ui->userChooser->addItem(user->getName());
    }

    int userKey = ui->userChooser->findText(wrapper.getSelectedUser()->getName());
    if(userKey != -1) {
        ui->userChooser->setCurrentIndex(userKey);
    }
    // end of todo
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSprintIndex(int newposition)
{
    TFSWrapper wrapper = TFSWrapper::instance();
    wrapper.setSelectedSprint(newposition);

    QString msg = QString("Sprint #%1").arg(newposition);

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
}

void MainWindow::on_PBIcombobox_currentIndexChanged(int index)
{
    TFSWrapper wrapper = TFSWrapper::instance();

}
