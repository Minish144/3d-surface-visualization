#include "point_movement.h"

Matrix3D xRotate(float a)
{
    array<array<float, MATRIX_SIZE>, MATRIX_SIZE> M =
     { {
         {1, 0, 0, 0},
         {0, cosf(a), -sinf(a), 0},
         {0, sinf(a), cosf(a), 0},
         {0, 0, 0, 1}
     } };

     Matrix3D tmp = { M };
     return tmp;
}

void Rotate(figure_t &figure, float a)
{
    if (a != 0.0)
    {
        Matrix3D mxa = xRotate(a);
        for (int i = 0; i < figure.Count(); i++)
        {
            figure.points[i] = Multiply(figure.points[i],
            mxa);
        }
    }
}

point_t Multiply(point_t &p, Matrix3D &m)
{
    point_t point;
    point.x = p.x * m.M[0][0] + p.y * m.M[0][1] + p.z * m.M[0][2];
    point.y = p.x * m.M[1][0] + p.y * m.M[1][1] + p.z * m.M[1][2];
    point.z = p.x * m.M[2][0] + p.y * m.M[2][1] + p.z * m.M[2][2];
    return point;
}
