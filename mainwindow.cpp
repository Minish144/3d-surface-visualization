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
    if (!filepath.empty())
    {
        ui->filepath_lineedit->setText(QString::fromStdString(filepath));
        vector<string> vctrstring = readCSV(filepath);
        getStringMatrix(vctrstring);
    }
}

string MainWindow::getFilePath()
{
    QString file_path = QFileDialog::getOpenFileName(this, "/Users/minish144/Desktop/compass/asdasd/bmstu-3d-surface-visualization/dataSet",
                                                     "/Users/minish144/Desktop/compass/asdasd/bmstu-3d-surface-visualization/dataSet",
                                                     tr("CSV tables (*.csv)"));

    return file_path.toStdString();
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
    if (!ui->filepath_lineedit->text().isEmpty() and
         ui->range1_lineedit->text().toFloat() > 0 and
         ui->step_lineedit->text().toFloat() != 0.0)
    {
        vector<vector<string>> matrix = dataVariable;
        surface = setSurface(matrix, ui->step_lineedit->text().toFloat());
        normalize(surface, ui->range0_lineedit->text().toFloat(), ui->range1_lineedit->text().toFloat());
        Rotate(surface, 2.74, ANGULAAR_COEFFICIENT, ZERO);
        replot(surface, canvas, ui->graphArea);
    }
    else
        errorMessage();
}

void MainWindow::on_scale_up_clicked()
{
    Scale(surface, SCALE_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_scale_down_clicked()
{
    UnScale(surface, SCALE_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_move_left_clicked()
{
    Move(surface, -MOVE_COEFFICIENT, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_move_right_clicked()
{
    Move(surface, MOVE_COEFFICIENT, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_move_up_clicked()
{
    Move(surface, ZERO, -MOVE_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_move_down_clicked()
{
    Move(surface, ZERO, MOVE_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_xAxis_right_clicked()
{
    Rotate(surface, -ANGULAAR_COEFFICIENT, ZERO, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_xAxis_left_clicked()
{
    Rotate(surface, ANGULAAR_COEFFICIENT, ZERO, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_yAxis_right_clicked()
{
    Rotate(surface, ZERO, ANGULAAR_COEFFICIENT, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_yAxis_left_clicked()
{
    Rotate(surface, ZERO, -ANGULAAR_COEFFICIENT, ZERO);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_zAxis_right_clicked()
{
    Rotate(surface, ZERO, ZERO, -ANGULAAR_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}

void MainWindow::on_rotate_zAxis_left_clicked()
{
    Rotate(surface, ZERO, ZERO, ANGULAAR_COEFFICIENT);
    replot(surface, canvas, ui->graphArea);
}
