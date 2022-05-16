/*
** EPITECH PROJECT, 2019
** convert
** File description:
** model
*/

#include "model.h"

#define RAD(angle_degrees) ((angle_degrees) * M_PI / 180.0)
#define DEG(angle_radians) (angle_radians * (180 / M_PI))

void normalize_vector(sfVector3f *v)
{
    float length = 0;

    length = sqrtf(powf(v->x, 2) + powf(v->y, 2) + powf(v->z, 2));
    *v = (sfVector3f){v->x / length, v->y / length, v->z / length};
}

float get_distance(sfVector3f p1, sfVector3f p2)
{
    float a = powf((p2.x - p1.x), 2);
    float b = powf((p2.y - p1.y), 2);

    return sqrtf(a + b);
}

float get_angle(sfVector3f res, sfVector3f point)
{
    float thales = (point.y - res.y) / (point.x - res.x);
    float theta = atanf(thales);

    if (theta < 0.0)
        theta += M_PI * 2;
    return (float)(theta * (180 / M_PI));
}

void convert_2d_cube(sfVector2f *res, sfVector3f *pt, int x, int y)
{
    for (int i = 0; i < 8; ++i) {
        res[i].x = (float)(cos(RAD(45)) * pt[i].x - cos(RAD(45)) * pt[i].y + x);
        res[i].y = (float)(sin(RAD(35)) * pt[i].y + sin(RAD(35)) * pt[i].x -
                pt[i].z + y);
    }
}
