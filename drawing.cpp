#include "drawing.h"

void setAxis(QLabel *graphArea, canvas_t &canvas)
{
    canvas.paint->fillRect(0, 0, 981, 561, QBrush(QColor::fromRgb(238, 238, 238)));
    canvas.paint->setPen(QColor(Qt::GlobalColor::green));

    canvas.paint->drawLine(200, 420, 200, 220);
    canvas.paint->drawLine(200, 420, 200, 220);

    canvas.paint->setPen(QColor(Qt::GlobalColor::blue));
    canvas.paint->drawLine(200, 420, 400, 420);
    canvas.paint->drawLine(200, 420, 400, 420);

    canvas.paint->setPen(QColor(Qt::GlobalColor::red));
    canvas.paint->drawLine(200, 420, 100, 520);
    canvas.paint->drawLine(200, 420, 100, 520);
}

void DrawFigure(figure_t &surface, canvas_t &canvas, QLabel *graphArea)
{
    canvas.paint->setPen(QColor(Qt::GlobalColor::black));
    for (int i = 0; i < surface.Count(); i++)
    {
        for (int j = 0; j < surface.countEdges(i); j++)
        {
            try
            {
                canvas.paint->drawLine(
                            surface.basePoint.x + surface.points[i].x,
                            surface.basePoint.y + surface.points[i].y,
                            surface.basePoint.x + surface.points[surface.edges[i][j]].x,
                            surface.basePoint.y + surface.points[surface.edges[i][j]].y);
            }
            catch (...)
            {
                qDebug() << "error" << i << j;
            }
        }
    }
}

void clearGraph(canvas_t &canvas, QLabel *graphArea)
{
    canvas.setData(981, 561);
    setAxis(graphArea, canvas);
}

void replot(figure_t &surface, canvas_t &canvas, QLabel *graphArea)
{
    clearGraph(canvas, graphArea);
    DrawFigure(surface, canvas, graphArea);
    graphArea->clear();
    graphArea->setPixmap(*canvas.pix);
}
