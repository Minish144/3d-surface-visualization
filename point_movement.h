#ifndef POINT_MOVEMENT_H
#define POINT_MOVEMENT_H

#include <array>
#include "math.h"
#include "data_types.h"
#include "logic.h"
#define MATRIX_SIZE 4

using namespace std;

struct Matrix3D
{
    array<array<float, MATRIX_SIZE>, MATRIX_SIZE> M;
};

Matrix3D xRotate(float a);

void Rotate(figure_t &figure, float a);

point_t Multiply(point_t &p, Matrix3D &m);

#endif // POINT_MOVEMENT_H
