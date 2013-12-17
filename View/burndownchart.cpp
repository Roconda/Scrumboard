#include "burndownchart.h"
#include "ui_burndownchart.h"
#include "../qcustomplot/qcustomplot.h"
#include "../tfswrapper.h"
#include "../TFS/Sprint.h"
#include "../Visitors/sbivisitor.h"
#include "../TFS/RemainingWorkHistory.h"

BurndownChart::BurndownChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BurndownChart)
{
    ui->setupUi(this);
    ui->widget->move(0,0);
    ui->widget->resize(this->width(), this->height());
    this->loadCustomPlot();
}

BurndownChart::~BurndownChart()
{
    delete ui;
}


void BurndownChart::loadCustomPlot(){
    SBIVisitor visitor;
    for(int i = 0; i < TFSWrapper::instance().getSelectedSprint()->getWorkItemArray().size(); i++){
        WorkItem *workitem = TFSWrapper::instance().getSelectedSprint()->getWorkItem(i);
        if(workitem)
            workitem->accept(visitor);
    }

    double remainingWorkTotal = 0.0;
    double totalWork = 0.0;
    Sprint *sprint = TFSWrapper::instance().getSelectedSprint();
    QDate *beginDate = new QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
    QDate *endDate = new QDate(sprint->getEndYear(), sprint->getEndMonth(), sprint->getEndDay());
    vector<SprintBacklogItem*> &SBIlist = visitor.getList();
    for(vector<SprintBacklogItem*>::const_iterator it = SBIlist.begin(); it != SBIlist.end(); ++it){
        SprintBacklogItem *SBIitem = *it;
        remainingWorkTotal += SBIitem->getRemainingWork();
        totalWork += SBIitem->getBaselineWork();
    }

    // generate some data:
    QVector<double> x(beginDate->daysTo(*endDate) + 1), y(beginDate->daysTo(*endDate) + 1); // initialize with entries 0..100
    QDate currDate = QDate::currentDate();
    for (int i=0; i< beginDate->daysTo(*endDate) + 1; ++i)
    {
        x[i] = i;
        if(i != beginDate->daysTo(currDate)){
            QDate *date = new QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
            date->addDays(i);
            double status;
            for(vector<SprintBacklogItem*>::const_iterator it = SBIlist.begin(); it != SBIlist.end(); ++it){
                SprintBacklogItem *SBIitem = *it;
                for(int i = 0; i < SBIitem->getRemainingWorkHistoryArray().size(); i++){
                    RemainingWorkHistory *workhistory = SBIitem->getRemainingWorkHistory(i);
                    if(workhistory){
                        QDate *workhistoryDate = new QDate(workhistory->getYear(), workhistory->getMonth(), workhistory->getDay());
                        if(workhistoryDate > date){
                            workhistory = SBIitem->getRemainingWorkHistory(i - 1);
                            status += workhistory->getRemainingWork();
                            break;
                        }
                    }
                }
            }
            y[i] = status;
        }
    }
    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("Days");
    ui->widget->yAxis->setLabel("Remaining Hours");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(0, beginDate->daysTo(*endDate));
    ui->widget->yAxis->setRange(0, totalWork);
    ui->widget->replot();
}

void BurndownChart::resizeEvent(QResizeEvent *){
    ui->widget->resize(this->width(), this->height());
}

