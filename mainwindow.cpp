#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "drawing.h"

figure_t surface;
canvas_t canvas;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_select_button_clicked()
{
    string filepath = getFilePath();
    if (filepath != ERROR)
    {
        ui->filepath_lineedit->setText(QString::fromStdString(filepath));
        vector<string> vctrstring = readCSV(filepath);
        getStringMatrix(vctrstring);
    }
    else
        errorMessage();
}

string MainWindow::getFilePath()
{
    string filepath = QFileDialog::getOpenFileName().toStdString();
    checkFile(filepath);
    if (!filepath.empty() && filepath.substr(filepath.length()-3, 3) == "csv")
        return filepath;
    else
        return ERROR;
}

void MainWindow::errorMessage()
{
    QMessageBox msgBox;
    msgBox.setText("Ошибка!");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setInformativeText("Попробуйте еще раз");
    msgBox.exec();
}

void MainWindow::on_visualize_button_clicked()
{
    clearGraph(canvas, ui->graphArea);
    vector<vector<string>> matrix = dataVariable;
    surface = setSurface(matrix, ui->step_lineedit->text().toFloat());
    normalize(surface, ui->range0_lineedit->text().toFloat(), ui->range1_lineedit->text().toFloat());
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_rotate_xAxis_right_clicked()
{
    clearGraph(canvas, ui->graphArea);
    Matrix3D mat = xRotate(-15);
    for (int i = 0; i < surface.Count(); i++)
    {
        Multiply(surface.points[i], mat);
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_scale_up_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x *= 1.05;
        surface.points[i].y *= 1.05;
        surface.points[i].z *= 1.05;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_scale_down_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x /= 1.05;
        surface.points[i].y /= 1.05;
        surface.points[i].z /= 1.05;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_move_left_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x -= 20;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_move_right_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x += 20;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_move_up_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].y -= 20;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}

void MainWindow::on_move_down_clicked()
{
    clearGraph(canvas, ui->graphArea);
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].y += 20;
    }
    DrawFigure(surface, canvas, ui->graphArea);
    ui->graphArea->clear();
    ui->graphArea->setPixmap(*canvas.pix);
}
