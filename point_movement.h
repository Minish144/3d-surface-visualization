#ifndef POINT_MOVEMENT_H
#define POINT_MOVEMENT_H

#include <array>
#include "math.h"
#include "data_types.h"
#include "logic.h"
#include "math.h"

#define SCALE_CONST 1.05

#define SIN_10 sinf(10 * 3.14 / 180)
#define COS_10 cosf(10 * 3.14 / 180)

#define SIN_NEG10 sin(-10 * 3.14 / 180)
#define COS_NEG10 cos(-10 * 3.14 / 180)

#define MATRIX_SIZE 4

using namespace std;

struct Matrix3D
{
    array<array<float, MATRIX_SIZE>, MATRIX_SIZE> M;
};

Matrix3D Mx(float a);

Matrix3D My(float b);

Matrix3D Mz(float c);

point_t Multiply(point_t &p, Matrix3D &m);

void Rotate(figure_t &figure, float a, float b, float c);

#endif // POINT_MOVEMENT_H
