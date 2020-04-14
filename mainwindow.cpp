#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "drawing.h"


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
    canvas_t canvas = {};
    canvas.setData(981, 561);
    setAxis(ui->graphArea, canvas);
    float step = ui->step_lineedit->text().toDouble();
    vector<vector<string>> matrix = dataVariable;
    figure_t surface = setFigure(dataVariable, ui->step_lineedit->text().toDouble());
    qDebug() << surface.Count();
    DrawFigure(surface, canvas, ui->graphArea);
}


