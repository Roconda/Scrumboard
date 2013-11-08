#include "burndownchart.h"
#include "ui_burndownchart.h"
#include "qcustomplot/qcustomplot.h"

BurndownChart::BurndownChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BurndownChart)
{
    ui->setupUi(this);

    this->loadCustomPlot();
}

BurndownChart::~BurndownChart()
{
    delete ui;
}

void BurndownChart::loadCustomPlot(){

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
        if(i%5 == 0){
            x[i] = i / 5; // x goes from -1 to 1
        }
        y[i] = 100 - i; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->widget->xAxis->setLabel("Dagen");
    ui->widget->yAxis->setLabel("Punten");
    // set axes ranges, so we see all data:
    ui->widget->xAxis->setRange(0, 20);
    ui->widget->yAxis->setRange(0, 100);
    ui->widget->replot();
}

