/*
** EPITECH PROJECT, 2019
** models
** File description:
** lib
*/

#ifndef MODEL_H_
#define MODEL_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

#define MODEL_ZOOM 8
#define NBR_CHEST 7

typedef struct part_sys particle_t;
typedef struct map map_t;
typedef struct win win_t;
typedef struct caract stat_t;
typedef struct images_s images_t;
typedef struct music_s music_t;
typedef struct texts_s texts_t;

static const sfVector2f SIZES[3] = {{56, 40}, {96, 56}, {100, 60}};

struct init {
    int nb_cubes;
    sfVector3f *pos;
    sfVector3f *scale;
    sfColor *color;
}; typedef struct init init_t;

struct cube {
    sfVector3f pos;
    sfVector2f *points_2d;
    sfVector3f *points_3d;
    sfConvexShape **faces;
    sfColor color;
    struct cube *next;
    struct cube *prev;
}; typedef struct cube cube_t;

typedef struct path {
    sfVector3f *path_points;
    int point;
} path_t;

struct model {
    sfVector3f dir;
    float rotation;
    int zoom;
    float length;
    float width;
    sfVector3f prev_pos;
    sfVector3f center;
    sfVector3f dest;
    float chase_angle;
    int dest_reached;
    int target_player;
    int is_player;
    int is_dock;
    int is_bullet;
    int is_ai;
    int is_chest;
    int is_tower;
    cube_t *head;
    struct model *sender;
    struct model *next;
    struct model *prev;
    path_t *path;
    stat_t *stat;
}; typedef struct model model_t;

typedef struct game {
    win_t *win;
    model_t *models;
    map_t *map;
    particle_t *particles;
    music_t **music;
    sfVector3f *chest_pos;
    sfClock *spawn_clock;
    int boat_killed;
    int chest_picked;
    int quest_nb;
    int no_kill;
    int buy_nb;
} game_t;

// life_bar

void print_life_bars(win_t *win, model_t *model);
void set_pos_and_size(model_t *model, sfRectangleShape *tmp);
sfRectangleShape *create_life_bar(void);

void get_center(model_t *model);
sfVector3f get_cube_center(cube_t *cube);
sfVector2f get_cube_center2d(cube_t *cube);
void rotate_model(model_t *model, float angle);
void add_cube(model_t *model, sfVector3f pos, sfVector3f scale, sfColor c);
void create_face(sfConvexShape *cs, int index, sfVector2f *pts, sfColor c[2]);
void render_cube(sfRenderWindow *win, cube_t *cube);
void convert_2d_cube(sfVector2f *res, sfVector3f *pt, int x, int y);
cube_t *sort_cubes(cube_t *head);
void render_model(sfRenderWindow *win, model_t *model);
cube_t *create_cube_list(char *file, model_t *model);
model_t *create_model(char *file, sfVector3f pos, int lvl);
model_t *add_model(model_t *head, char *file, sfVector3f pos, int lvl);
cube_t *create_cube(sfVector3f pos, sfVector3f scale, sfColor c);
void define_model_pos(model_t *model, sfVector3f pos);
void move_model(model_t *model, sfVector3f dir);
void shoot(model_t *model, float shoot_angle, int nb_bullets, game_t *game);
void normalize_vector(sfVector3f *v);
void move_bullets(map_t *map, model_t *head, double offset, game_t *game);
model_t *destroy(model_t *model);
sfVector3f get_model_pos(map_t *map, model_t *model);
model_t *get_model_head(model_t *model);
void refresh_positions(map_t *map, model_t *model);
void rotate_point(sfVector3f *pt, sfVector3f center, float angle);
model_t *sort_models(model_t *head);
model_t *try_render(model_t *current, float y, sfRenderWindow *win);
sfVector2f get_cam_offset(model_t *model);
sfVector3f get_model_corners(model_t *model, int corner);
init_t *open_model(char *path);
int check_error(char *path);
void destroy_cube(cube_t *cube);
float get_angle(sfVector3f res, sfVector3f point);
float get_distance(sfVector3f p1, sfVector3f p2);
void render_chests(sfRenderWindow *win, game_t *game);
void destroy_game(game_t *game);

#endif
