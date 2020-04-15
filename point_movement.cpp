#include "point_movement.h"

Matrix3D Mx(float a)
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

Matrix3D My(float b)
{
    array<array<float, MATRIX_SIZE>, MATRIX_SIZE> M =
    { {
        {cosf(b), 0, sinf(b), 0},
        {0, 1, 0, 0},
        {-sinf(b), 0, cosf(b), 0},
        {0, 0, 0, 1}
    } };

    Matrix3D tmp = { M };
    return tmp;
}

Matrix3D Mz(float c)
{
    array<array<float, MATRIX_SIZE>, MATRIX_SIZE> M =
    { {
        {cosf(c), -sinf(c), 0, 0},
        {sinf(c), cosf(c), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    } };

    Matrix3D tmp = { M };
    return tmp;
}

point_t Multiply(point_t &p, Matrix3D &m)
{
    point_t point;
    point.x = p.x * m.M[0][0] + p.y * m.M[0][1] + p.z * m.M[0][2];
    point.y = p.x * m.M[1][0] + p.y * m.M[1][1] + p.z * m.M[1][2];
    point.z = p.x * m.M[2][0] + p.y * m.M[2][1] + p.z * m.M[2][2];
    return point;
}

void Rotate(figure_t &figure, float a, float b, float c)
{
    if (a != 0.0)
    {
        Matrix3D mxa = Mx(a);
        for (int i = 0; i < figure.Count(); i++)
            figure.points[i] = Multiply(figure.points[i], mxa);
    }

    if (b != 0.0)
    {
        Matrix3D myb = My(b);
        for (int i = 0; i < figure.Count(); i++)
            figure.points[i] = Multiply(figure.points[i], myb);
    }

    if (c != 0.0)
    {
        Matrix3D mzc = Mz(c);
        for (int i = 0; i < figure.Count(); i++)
            figure.points[i] = Multiply(figure.points[i], mzc);
    }
}

void Move(figure_t &figure, float a, float b)
{
    if (a != 0.0)
        for (int i = 0; i < figure.Count(); i++)
            surface.points[i].x += a;

    if (b != 0.0)
        for (int i = 0; i < figure.Count(); i++)
            surface.points[i].y += b;
}

void Scale(figure_t &surface, float a)
{
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x *= a;
        surface.points[i].y *= a;
        surface.points[i].z *= a;
    }
}

void UnScale(figure_t &surface, float a)
{
    for (int i = 0; i < surface.Count(); i++)
    {
        surface.points[i].x /= a;
        surface.points[i].y /= a;
        surface.points[i].z /= a;
    }
}
