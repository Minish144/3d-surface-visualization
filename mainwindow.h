#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logic.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include "data_types.h"

#define ERROR "ERROR"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern figure_t surface;

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
