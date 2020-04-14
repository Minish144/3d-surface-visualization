#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#include <vector>
#include <QPixmap>
#include <QPainter>
using namespace std;

typedef struct
{
    float x;
    float y;
    float z;
} point_t;

typedef struct
{
    vector<point_t> points;
    point_t basePoint;
    int Count()
    {
        return points.size();
    }
} figure_t;

typedef struct
{
    QPixmap *pix;
    QPainter *paint;
    void setData(float width, float height)
    {
        pix = new QPixmap(width, height);
        paint = new QPainter(pix);
        //paint->setRenderHint(QPainter::Antialiasing);
        paint->setRenderHint(QPainter::HighQualityAntialiasing);
    }
} canvas_t;

#endif // DATA_TYPES_H
