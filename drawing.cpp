#include "drawing.h"

void setAxis(QLabel *graphArea, canvas_t &canvas)
{
    canvas.paint->fillRect(0, 0, 981, 561, QBrush(QColor(Qt::GlobalColor::transparent)));
    canvas.paint->setPen(QColor(Qt::GlobalColor::blue));
    canvas.paint->drawLine(10, 551, 971, 551);
    canvas.paint->setPen(QColor(Qt::GlobalColor::green));
    canvas.paint->drawLine(10, 10, 10, 551);
    canvas.paint->setPen(QColor(Qt::GlobalColor::black));
    graphArea->setPixmap(*canvas.pix);
}
