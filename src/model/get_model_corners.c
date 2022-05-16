/*
** EPITECH PROJECT, 2019
** model
** File description:
** corners
*/

#include "model.h"

sfVector3f get_model_corners(model_t *model, int corner)
{
    float len = model->length / 2;
    float width[2] = {model->width / 2, model->width / 2 * -1};
    sfVector3f corners[4];
    sfVector3f sides[2];
    sfVector3f dir = model->dir;

    normalize_vector(&dir);
    sides[0] = (sfVector3f) {dir.x * len, dir.y * len, model->center.z};
    sides[1] = (sfVector3f) {dir.x * -len, dir.y * -len, model->center.z};
    rotate_point(&dir, (sfVector3f) {0, 0, 0}, 90);
    for (int i = 0; i < 2; ++i) {
        corners[i].x = sides[0].x + width[i] * dir.x + model->center.x;
        corners[i].y = sides[0].y + width[i] * dir.y + model->center.y;
        corners[i].z = sides[0].z + model->center.z;
    }
    for (int i = 0; i < 2; ++i) {
        corners[i + 2].x = sides[1].x - width[i] * dir.x + model->center.x;
        corners[i + 2].y = sides[1].y - width[i] * dir.y + model->center.y;
        corners[i + 2].z = sides[1].z + model->center.z;
    }
    return corners[corner];
}