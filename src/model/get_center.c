/*
** EPITECH PROJECT, 2019
** get_center
** File description:
** cube & model
*/

#include "model.h"
#include "map.h"

void get_points_extrems(cube_t *cube, float *bigger, float *smaller)
{
    float temp[2];

    for (int j = 0; j < 8; ++j) {
        temp[0] = cube->points_3d[j].x;
        temp[1] = cube->points_3d[j].y;
        for (int i = 0; i < 2; ++i) {
            bigger[i] = (bigger[i] < temp[i] ? temp[i] : bigger[i]);
            smaller[i] = (smaller[i] > temp[i] ? temp[i] : smaller[i]);
        }
    }
}

sfVector2f get_cam_offset(model_t *model)
{
    model_t *curr = get_model_head(model);

    while (curr != NULL && curr->is_player == 0)
        curr = curr->next;
    if (curr == NULL)
        return (sfVector2f){0, 0};
    return convert_3d_2d(curr->center, 0, 0);
}

sfVector3f get_cube_center(cube_t *cube)
{
    float x = cube->points_3d[0].x + cube->points_3d[6].x;
    float y = cube->points_3d[0].y + cube->points_3d[6].y;
    float z = cube->points_3d[0].z + cube->points_3d[6].z;
    return (sfVector3f){x / 2, y / 2, z / 2};
}

sfVector2f get_cube_center2d(cube_t *cube)
{
    float x = cube->points_2d[0].x + cube->points_2d[6].x;
    float y = cube->points_2d[0].y + cube->points_2d[6].y;
    return (sfVector2f){x / 2, y / 2};
}