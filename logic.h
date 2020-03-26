#ifndef LOGIC_H
#define LOGIC_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QFileDialog>

#include <stdio.h>
#include <QString>
#include <fstream>
#include <string>
#include <iostream>
#include <QDebug>
#include <vector>
#include <math.h>

using namespace std;

int checkFile(string filepath);

vector<string> readCSV(string filepath);

vector<string> splitString(string str, string sep);


#endif // LOGIC_H
