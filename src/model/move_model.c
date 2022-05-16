/*
** EPITECH PROJECT, 2019
** model
** File description:
** move
*/

#include "map.h"
#include "model.h"

void define_model_pos(model_t *model, sfVector3f pos)
{
    sfVector3f center = model->center;
    sfVector3f diff = {pos.x - center.x, pos.y - center.y, pos.z - center.z};
    cube_t *current = model->head;

    while (current != NULL) {
        for (int i = 0; i < 8; ++i) {
            current->points_3d[i].x += diff.x;
            current->points_3d[i].y += diff.y;
            current->points_3d[i].z += diff.z;
        }
        current = current->next;
    }
    model->center.x += diff.x;
    model->center.y += diff.y;
    model->center.z += diff.z;
}

void move_model(model_t *model, sfVector3f dir)
{
    sfVector3f pos;

    pos.x = model->center.x + dir.x;
    pos.y = model->center.y + dir.y;
    pos.z = model->center.z + dir.z;
    define_model_pos(model, pos);
}

void move_map(map_t *map, sfVector3f dir)
{
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->points3d[i][j].x -= dir.x;
            map->points3d[i][j].y -= dir.y;
            map->points3d[i][j].z -= dir.z;
            map->water->points3d[i][j].x -= dir.x;
            map->water->points3d[i][j].y -= dir.y;
            map->water->points3d[i][j].z -= dir.z;
        }
    }
}

void move_map2d(map_t *map, sfVector3f dir, model_t *model)
{
    sfVector2f dir_2d = convert_3d_2d(dir, 0, 0);
    model_t *head = get_model_head(model);

    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->points2d[i][j].x -= dir_2d.x;
            map->points2d[i][j].y -= dir_2d.y;
            map->water->points2d[i][j].x -= dir_2d.x;
            map->water->points2d[i][j].y -= dir_2d.y;
        }
    }
    while (head->next !=  NULL) {
        for (int i = 0; i < 8; ++i) {
            head->head->points_2d[i].x += dir_2d.x;
            head->head->points_2d[i].y += dir_2d.y;
        }
        head = head->next;
    }
}