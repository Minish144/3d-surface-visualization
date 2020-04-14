#ifndef DRAWING_H
#define DRAWING_H

#include "data_types.h"
#include <QPainter>
#include <QLabel>
#include <iostream>
#include <QDebug>

using namespace std;

void setAxis(QLabel *graphArea, canvas_t &canvas);

void DrawFigure(figure_t &surface, canvas_t &canvas);

#endif // DRAWING_H
