/*
** EPITECH PROJECT, 2019
** world
** File description:
** vertex
*/

#include "model.h"
#include "map.h"

#define RAD(angleDegrees) ((angleDegrees) * M_PI / 180.0)

sfVector2f convert_3d_2d(sfVector3f pt, int x, int y)
{
    sfVector2f instance;

    instance.x = cos(RAD(45)) * pt.x - cos(RAD(45)) * pt.y + x;
    instance.y = sin(RAD(35)) * pt.y + sin(RAD(35)) * pt.x - pt.z + y;
    return instance;
}

sfVector3f convert_2d_3d(sfVector2f pt)
{
    sfVector3f r;

    r.y = pt.x / (cos(RAD(45)) * ((pt.y - sin(RAD(35)))/sin(RAD(35)) - 1));
    r.x = (pt.y - sin(RAD(35)) * r.y) / sin(RAD(35));
    r.z = 0;
    return r;
}

sfVector2f **convert3d_points(map_t *map, sfRenderWindow *win)
{
    sfVector2u size = sfRenderWindow_getSize(win);
    sfVector2f **res = map->points2d;
    int dx = size.x / 2;
    int dy = size.y / 2;

    for (int y = 0; y < map->size; ++y) {
        for (int x = 0; x < map->size; ++x)
            res[y][x] = convert_3d_2d(map->points3d[y][x], dx, dy);
    }
    res[map->size] = NULL;
    return res;
}