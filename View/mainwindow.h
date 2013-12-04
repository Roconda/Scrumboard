#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../itemhandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_sbiOverview_clicked();

    void on_pushButton_2_clicked();

    void on_sprintSlider_sliderMoved(int position);

// members
private:
    Ui::MainWindow *ui;
    static ItemHandler itemhandler;

// functions
private:
    void updateSprintIndex(int newposition);
};

#endif // MAINWINDOW_H
