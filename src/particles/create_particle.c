/*
** EPITECH PROJECT, 2019
** particles
** File description:
** create
*/

#include "particles.h"
#include "model.h"

void add_part(particle_t *p, sfVector3f pos, sfVector3f scale, sfColor c)
{
    cube_t *current = p->cubes;

    if (current == NULL) {
        p->cubes = create_cube(pos, scale, c);
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = create_cube(pos, scale, c);
    current->next->prev = current;
}

particle_t *create_particles(sfVector3f dir, sfColor color)
{
    particle_t *res = malloc(sizeof(particle_t));
    float off[3] = {0, 0, 0};

    if (!res)
        return NULL;
    res->next = NULL;
    res->prev = NULL;
    res->nb_cube = 5;
    res->cubes = NULL;
    res->velocity = 12;
    res->life = sfClock_create();
    for (int i = 0; i < res->nb_cube; ++i) {
        for (int j = 0; j < 3; ++j)
            off[j] = (float)(rand() % 100 / 100.0);
        add_part(res, (sfVector3f){0, 0, 0}, (sfVector3f){.5, .5, .5}, color);
        res->cube_dir[i] =
        (sfVector3f){dir.x + off[0], dir.y + off[1], dir.z + off[2]};
    }
    res->lifetime = (float)(rand() % (3 - 1) + 1) / 10.0;
    res->dir = dir;
    return res;
}

void move_particle(particle_t *particle, sfVector3f pos)
{
    sfVector3f center = {0, 0, 0};
    sfVector3f diff = {pos.x - center.x, pos.y - center.y, pos.z - center.z};
    cube_t *current = particle->cubes;

    while (current != NULL) {
        for (int i = 0; i < 8; ++i) {
            current->points_3d[i].x += diff.x;
            current->points_3d[i].y += diff.y;
            current->points_3d[i].z += diff.z;
        }
        current = current->next;
    }
    particle->pos.x += diff.x;
    particle->pos.y += diff.y;
    particle->pos.z += diff.z;
}

void spawn_particle(sfVector3f dir, sfColor color, sfVector3f pos, game_t *g)
{
    particle_t *current = g->particles;
    if (current == NULL) {
        g->particles = create_particles(dir, color);
        move_particle(g->particles, pos);
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = create_particles(dir, color);
    current->next->prev = current;
    move_particle(current->next, pos);
}