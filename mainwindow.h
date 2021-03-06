#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logic.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include "data_types.h"
#include "point_movement.h"
#include <thread>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

#define ERROR "ERROR"
#define EMPTY "EMPTY"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern figure_t surface;
extern canvas_t canvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_select_button_clicked();

    std::string getFilePath();

    void errorMessage();

    void on_visualize_button_clicked();

    void on_scale_up_clicked();

    void on_scale_down_clicked();

    void on_move_left_clicked();

    void on_move_right_clicked();

    void on_move_up_clicked();

    void on_move_down_clicked();

    void on_rotate_xAxis_right_clicked();

    void on_rotate_xAxis_left_clicked();

    void on_rotate_yAxis_right_clicked();

    void on_rotate_yAxis_left_clicked();

    void on_rotate_zAxis_right_clicked();

    void on_rotate_zAxis_left_clicked();

    void on_set_recommended_clicked();

    void on_reset_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
