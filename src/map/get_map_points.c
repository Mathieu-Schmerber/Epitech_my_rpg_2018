/*
** EPITECH PROJECT, 2019
** world
** File description:
** points
*/

#include "map.h"

void refresh_heights(map_t *water)
{
    int size = water->size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            water->points3d[y][x].z = water->map_heights[x + y * size]
            * water->zoom;
        }
    }
}

void get_map_points(sfVector3f **res, float *map_height, int size, int zoom)
{
    int k = 0;

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            res[y][x].x = x * zoom - MID;
            res[y][x].y = y * zoom - MID;
            res[y][x].z = map_height[k] * zoom;
            k++;
        }
    }
}
