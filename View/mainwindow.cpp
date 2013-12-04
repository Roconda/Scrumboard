#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "burndownchart.h"
#include "sbi.h"
#include "adddefect.h"
#include "../sbilistmodel.h"
#include "../itemhandler.h"

#include "../TFS/Project.h"
#include "../TFS/Sprint.h"

#include "../tfswrapper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Stel het sprint nummer in.
    TFSWrapper wrapper = TFSWrapper::instance();
    size_t sprintindex = wrapper.getSelectedSprintIndex();
    updateSprintIndex(sprintindex);

    // Edit scrollbar's item count to the amount of sprints
    // TODO: check how many sprints there actually are
    ui->sprintSlider->setMaximum(wrapper.getSelectedProject()->getSprintArray().size()-1);
    ui->sprintSlider->setValue(sprintindex);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSprintIndex(int newposition)
{
    QString titleString("Sprint #");
    TFSWrapper wrapper = TFSWrapper::instance();

    wrapper.setSelectedSprint(newposition);

    ui->sprint_titleLabel->setText(titleString + ('0' + newposition));
    ui->widget->updateSprintData();
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

void MainWindow::on_sprintSlider_sliderMoved(int position)
{
    /* update de sprintindex label */
     updateSprintIndex(position);
}
