/*
** EPITECH PROJECT, 2019
** map
** File description:
** world
*/

#include "map.h"

sfVector3f **malloc_map(int size)
{
    sfVector3f **res = malloc(sizeof(sfVector3f *) * (size + 1));

    if (res == NULL)
        return NULL;
    for (int y = 0; y < size; y++) {
        res[y] = malloc(sizeof(sfVector3f) * (size + 1));
        if (res[y] == NULL)
            return NULL;
    }
    res[size] = NULL;
    return (res);
}

sfVector2f **malloc_map2d(int size)
{
    sfVector2f **res = malloc(sizeof(sfVector2f *) * (size + 1));

    if (res == NULL)
        return NULL;
    for (int y = 0; y < size; y++) {
        res[y] = malloc(sizeof(sfVector2f) * (size + 1));
        if (res[y] == NULL)
            return NULL;
    }
    res[size] = NULL;
    return (res);
}

map_t *create_map(int size, int zoom)
{
    map_t *res = malloc(sizeof(map_t));

    if (res == NULL)
        return NULL;
    res->size = size;
    res->draw = 1;
    res->display = sfQuads;
    res->zoom = zoom;
    res->rotation = 45;
    res->map_heights = malloc(sizeof(float) * (size * size));
    if (res->map_heights == NULL)
        return NULL;
    res->points3d = malloc_map(size);
    res->points2d = malloc_map2d(size);
    if (!res->points3d || !res->points2d)
        return NULL;
    get_map_points(res->points3d, res->map_heights, size, zoom);
    res->water_clock = NULL;
    return (res);
}

void free_map(map_t *map)
{
    for (int i = 0; i < map->size; i++) {
        free(map->points2d[i]);
        free(map->points3d[i]);
    }
    free(map->points2d);
    free(map->points3d);
    free(map->map_heights);
    if (map->water_clock != NULL)
        sfClock_destroy(map->water_clock);
}