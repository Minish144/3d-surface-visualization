#include "drawing.h"

void setAxis(QLabel *graphArea, canvas_t &canvas)
{
    canvas.paint->fillRect(0, 0, 981, 561, QBrush(QColor(Qt::GlobalColor::transparent)));
    canvas.paint->setPen(QColor(Qt::GlobalColor::blue));
    canvas.paint->drawLine(10, 551, 971, 551);
    canvas.paint->setPen(QColor(Qt::GlobalColor::green));
    canvas.paint->drawLine(10, 10, 10, 551);
    canvas.paint->drawLine(10, 551, 10, 10);
    canvas.paint->setPen(QColor(Qt::GlobalColor::black));
}

void DrawFigure(figure_t &surface, canvas_t &canvas, QLabel *graphArea)
{
    canvas.paint->setPen(QColor(Qt::GlobalColor::black));
    for (int i = 0; i < surface.Count() - 1; i++)
    {
        for (int j = 0; j < surface.countEdges(i); j++)
        {
            try
            {
                canvas.paint->drawLine(
                            15 + surface.points[i].x, 15 + surface.points[i].y,
                            15 + surface.points[surface.edges[i][j]].x, 15 + surface.points[surface.edges[i][j]].y);
            }
            catch (...)
            {
                qDebug() << 'error' << i << j;
            }
        }
    }
}
