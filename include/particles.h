/*
** EPITECH PROJECT, 2019
** include
** File description:
** particles
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

typedef struct cube cube_t;
typedef struct win win_t;
typedef struct game game_t;
typedef struct model model_t;

typedef struct part_sys {
    int nb_cube;
    float velocity;
    float lifetime;
    sfVector3f dir;
    sfVector3f pos;
    sfColor color;
    cube_t *cubes;
    sfVector3f cube_dir[5];
    sfClock *life;
    struct part_sys *next;
    struct part_sys *prev;
} particle_t;

void render_particles(win_t *win, particle_t *particles, model_t *m, float off);
void spawn_particle(sfVector3f dir, sfColor color, sfVector3f pos, game_t *g);
particle_t *behave_particle(particle_t *particle, float offset);
particle_t *get_particle_head(particle_t *p);
particle_t *clean_particle_list(particle_t *head);