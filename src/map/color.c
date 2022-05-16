/*
** EPITECH PROJECT, 2019
** world
** File description:
** color
*/

#include "map.h"

float get_average_height(map_t *map, int args[4])
{
    float res = 0;
    int a = args[2];
    int b = args[3];

    res += map->points3d[args[0]][args[1]].z;
    res += map->points3d[args[0] + a][args[1]].z;
    res += map->points3d[args[0] + a][args[1] + b].z;
    res += map->points3d[args[0]][args[1] + b].z;
    return res/4;
}

void tower_color(map_t *map, sfColor *map_c, sfColor *water_c, int args[4])
{
    float i = get_average_height(map, args)/(map->zoom * 10) + 0.5;

    map_c->r = 35 + (i * 60);
    map_c->g = 0;
    map_c->b = 0;
    water_c->r = 100 * i + 80;
    water_c->g = 0;
    water_c->b = 0;
}

sfColor get_color(map_t *map, int args[4])
{
    float i = get_average_height(map, args)/(map->zoom * 10) + 0.5;

    if (i > 0.4 && i < 0.7)
        return sfColor_fromRGB(83 * i, 255 - (189 * i), 40 * i);
    else if (i >= 0.7)
        return sfColor_fromRGB(250 * i, 255 * i, 255 * i);
    else
        return sfColor_fromRGB(250 * i + 140, 250 * i + 140, 100 * i);
}

sfColor get_color_water(map_t *map, int args[4])
{
    float i = get_average_height(map, args)/(map->zoom * 10) + 0.5;

    return sfColor_fromRGBA(150 * i, 150 * i, 255 * i + 100, 180);
}
