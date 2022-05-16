/*
** EPITECH PROJECT, 2019
** my
** File description:
** lib
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>
#include "window.h"

#define MAP_SIZE 100
#define MAP_ZOOM 50
#define MID MAP_ZOOM * MAP_SIZE / 2.0
#define MAP_INDEX(pos) ((pos + MID) / MAP_ZOOM)
#define INDEX_MAP(index) ((index - MAP_ZOOM) * MAP_SIZE)

typedef struct map map_t;
typedef struct game game_t;
typedef struct model model_t;
typedef struct my_rpg_s my_rpg_t;

struct map {
    int size;
    int zoom;
    float rotation;
    int draw;
    float *map_heights;
    sfPrimitiveType display;
    sfVector2f **points2d;
    sfVector3f **points3d;
    sfClock *water_clock;
    map_t *water;
};

void gen_map(float *, int, float, int);
sfVector2f **convert3d_points(map_t *map, sfRenderWindow *win);
void render_map(map_t *map, sfRenderWindow *window, model_t *models);
void get_map_points(sfVector3f **, float *, int, int);
map_t *create_map(int size, int zoom);
void free_map(map_t *map);
void wave(map_t *, float);
void refresh_heights(map_t *);
sfColor get_color(map_t *map, int args[4]);
sfColor get_color_water(map_t *map, int args[4]);
sfVector3f **malloc_map(int);
sfVector3f convert_2d_3d(sfVector2f pt);
int mainloop(game_t *game, my_rpg_t *rpg);
map_t *open_map(char *);
void move_map(map_t *map, sfVector3f dir);
sfVector3f map_point(sfVector3f pts);
sfVector2f convert_3d_2d(sfVector3f pt, int x, int y);
void move_map2d(map_t *map, sfVector3f dir, model_t *models);
int map_index(float pt);
void tower_color(map_t *map, sfColor *map_c, sfColor *water_c, int args[4]);

#endif
