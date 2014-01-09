#include "burndownchart.h"
#include "ui_burndownchart.h"
#include "../qcustomplot/qcustomplot.h"
#include "../tfswrapper.h"
#include "../TFS/Sprint.h"
#include "../Visitors/sbivisitor.h"
#include "../TFS/RemainingWorkHistory.h"
#include <QDebug>

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
    //get SBI's with visitor
    SBIVisitor visitor;
    for(int i = 0; i < TFSWrapper::instance().getSelectedSprint()->getWorkItemArray().size(); i++){
        WorkItem *workitem = TFSWrapper::instance().getSelectedSprint()->getWorkItem(i);
        if(workitem)
            workitem->accept(visitor);
    }
    vector<SprintBacklogItem*> &SBIlist = visitor.getList();
    double totalWork = 0.0;
    double yAxis = 0.0;
    for(vector<SprintBacklogItem*>::const_iterator itr = SBIlist.begin(); itr != SBIlist.end(); ++itr){
        SprintBacklogItem *SBIitem = *itr;
        totalWork += SBIitem->getBaselineWork();
        yAxis += SBIitem->getBaselineWork();
    }

    Sprint *sprint = TFSWrapper::instance().getSelectedSprint();
    QDate *beginDate = new QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
    QDate *endDate = new QDate(sprint->getEndYear(), sprint->getEndMonth(), sprint->getEndDay());

    // generate some data:
    QVector<double> x(beginDate->daysTo(*endDate) + 1), y(beginDate->daysTo(*endDate) + 1);
    QDate currDate = QDate::currentDate();
    QDate *date = new QDate(sprint->getBeginYear(), sprint->getBeginMonth(), sprint->getBeginDay());
    for (int n = 0; n < beginDate->daysTo(*endDate) + 1; n++)
    {
        x[n] = n;
        date = &date->addDays(1);
        double workremainingforday = 0.0;
        if(n <= beginDate->daysTo(currDate)){
            for(vector<SprintBacklogItem*>::const_iterator it = SBIlist.begin(); it != SBIlist.end(); ++it){
                SprintBacklogItem *SBIitem = *it;
                for(int x = 0; x < SBIitem->getRemainingWorkHistoryArray().size(); x++){
                    RemainingWorkHistory *workhistory = SBIitem->getRemainingWorkHistory(x);
                    if(workhistory){
                        QDate *workhistoryDate = new QDate(workhistory->getYear(), workhistory->getMonth(), workhistory->getDay());
                        if(workhistoryDate->daysTo(*date) == 0){
                            workremainingforday += workhistory->getRemainingWork();
                        }
                    }
                }
            }
            totalWork = totalWork - workremainingforday;
            y[n] = totalWork;
        }else{
            break;
        }
    }

    double projectedEndPoint = (totalWork - (((yAxis - ((yAxis + totalWork) / 2)) / (beginDate->daysTo(currDate))) * (currDate.daysTo(*endDate))));
    double difference = totalWork - projectedEndPoint;
    for(int i = 0; i < y.size() - 1; i++){
        if(y[i] == 0.0){
            y[i] == totalWork - (difference / QDate::currentDate().daysTo(*endDate));
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
    ui->widget->yAxis->setRange(0, yAxis);
    ui->widget->replot();
}

void BurndownChart::resizeEvent(QResizeEvent *){
    ui->widget->resize(this->width(), this->height());
}

