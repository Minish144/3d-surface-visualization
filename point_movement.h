#ifndef POINT_MOVEMENT_H
#define POINT_MOVEMENT_H

#include <array>
#include "math.h"
#include "data_types.h"
#include "logic.h"
#include "math.h"

#define SCALE_COEFFICIENT 1.05
#define MOVE_COEFFICIENT 30.0
#define ANGULAAR_COEFFICIENT 0.2
#define ZERO 0.0

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

void Move(figure_t &figure, float a, float b);

void Scale(figure_t &figure, float a);

void UnScale(figure_t &figure, float a);

#endif // POINT_MOVEMENT_H
