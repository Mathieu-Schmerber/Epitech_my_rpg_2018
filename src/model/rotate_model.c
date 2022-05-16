/*
** EPITECH PROJECT, 2019
** rotate 
** File description:
** model
*/

#include "model.h"
#include "map.h"

#define RAD(angleDegrees) ((angleDegrees) * M_PI / 180.0)

void rotate_point(sfVector3f *pt, sfVector3f center, float angle)
{
    float x1 = pt->x - center.x;
    float y1 = pt->y - center.y;
    float x2 = x1 * cos(RAD(angle)) - y1 * sin(RAD(angle));
    float y2 = x1 * sin(RAD(angle)) + y1 * cos(RAD(angle));

    pt->x = x2 + center.x;
    pt->y = y2 + center.y;
}

void rotate_model(model_t *model, float angle)
{
    cube_t *current = model->head;

    model->rotation += angle;
    while (current != NULL) {
        for (int i = 0; i < 8; ++i)
            rotate_point(&current->points_3d[i], model->center, angle);
        current = current->next;
    }
    rotate_point(&model->dir, (sfVector3f){0, 0, 0}, angle);
    model->head = sort_cubes(model->head);
}