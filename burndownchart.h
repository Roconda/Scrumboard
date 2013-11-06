#ifndef BURNDOWNCHART_H
#define BURNDOWNCHART_H

#include <QDialog>

namespace Ui {
class BurndownChart;
}

class BurndownChart : public QDialog
{
    Q_OBJECT

public:
    explicit BurndownChart(QWidget *parent = 0);
    ~BurndownChart();
    void loadCustomPlot();

private:
    Ui::BurndownChart *ui;
};

#endif // BURNDOWNCHART_H
