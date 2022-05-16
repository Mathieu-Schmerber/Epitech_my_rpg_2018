/*
** EPITECH PROJECT, 2019
** collisions
** File description:
** rpg
*/

#include "map.h"
#include "player.h"
#include "model.h"

int map_index(float pt)
{
    return ((int)(pt + MID) / MAP_ZOOM);
}

int map_collision(map_t *map, model_t *model)
{
    sfVector3f pred = model->center;

    for (int i = 0; i < 2; ++i) {
        pred = get_model_corners(model, i);
        pred.x += model->dir.x * 2;
        pred.y += model->dir.y * 2;
        if (map_index(pred.y) > 99 || map_index(pred.x) > 99 ||
        map_index(pred.x) < 0 || map_index(pred.y) < 0)
            return 0;
        if (map->points3d[map_index(pred.y)][map_index(pred.x)].z >= 0)
            return 0;
    }
    return 1;
}

int collide(model_t *model, sfVector3f pts[2], sfVector3f mid)
{
    float pow_x;
    float pow_y;
    float radius = (model->length + model->width) / 2;

    for (int i = 0; i < 2; ++i) {
        pow_x = (float)pow(fabs(pts[i].x - mid.x), 2);
        pow_y = (float)pow(fabs(pts[i].y - mid.y), 2);
        if (sqrt(pow_x + pow_y) < radius)
            return 1;
    }
    return 0;
}

int model_collision(model_t *model)
{
    model_t *current = get_model_head(model);
    sfVector3f pred[2];

    for (int i = 0; i < 2; ++i) {
        pred[i] = get_model_corners(model, i);
        pred[i].x += model->dir.x * 2;
        pred[i].y += model->dir.y * 2;
    }
    while (current != NULL) {
        if (current == model || current->is_bullet == 1) {
            current = current->next;
            continue;
        }
        if (collide(current, pred, current->center) == 1)
            return 0;
        current = current->next;
    }
    return 1;
}

int check_collisions(game_t *game, model_t *player)
{
    if (map_collision(game->map, player) == 0)
        return 0;
    else if (model_collision(player) == 0)
        return 0;
    return 1;
}