#ifndef LOGIC_H
#define LOGIC_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QFileDialog>
#include "data_types.h"
#include <stdio.h>
#include <QString>
#include <fstream>
#include <string>
#include <iostream>
#include <QDebug>
#include <vector>
#include <math.h>

using namespace std;

extern vector<vector<string>> dataVariable;

int checkFile(string filepath);

vector<string> readCSV(string filepath);

vector<string> splitString(string str, string sep);

vector<vector<string>> getStringMatrix(vector<string> array);

figure_t setSurface(vector<vector<string>> &zAxisMatrix, float step);

float findExtremums(figure_t &surface, float &min, float &max);

void normalize(figure_t &surface, float a, float b);

#endif // LOGIC_H
