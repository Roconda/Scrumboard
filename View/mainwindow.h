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

// members
    void on_sprintSlider_valueChanged(int value);

    void on_PBIcombobox_currentIndexChanged(int index);

    void on_lineEdit_returnPressed();

    void on_filterChooser_currentIndexChanged(int index);

    void on_btn_clear_clicked();

    void on_btn_filter_clicked();

    void on_userComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    static ItemHandler itemhandler;
    int currentFilterChooserIndex;
    int currentPBIChooserIndex;

// functions
private:
    void updateSprintIndex(int newposition);
};

#endif // MAINWINDOW_H
