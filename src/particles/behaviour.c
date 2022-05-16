/*
** EPITECH PROJECT, 2019
** particle behaviour
** File description:
** rpg
*/

#include "window.h"
#include "my_rpg.h"
#include "model.h"
#include "particles.h"

void move_part(particle_t *particle, int index, sfVector3f real_dir)
{
    cube_t *current = particle->cubes;
    int i = 0;

    while (current != NULL) {
        if (i > index)
            break;
        else if (i < index) {
            current = current->next;
            i++;
            continue;
        }
        for (int j = 0; j < 8; ++j) {
            current->points_3d[j].x += real_dir.x;
            current->points_3d[j].y += real_dir.y;
            current->points_3d[j].z += real_dir.z;
        }
        current = current->next;
        i++;
    }
}

particle_t *remove_particle(particle_t *particle)
{
    particle_t *head = get_particle_head(particle);

    if (head == NULL)
        return NULL;
    if (particle->prev == NULL) {
        head = particle->next;
        if (head)
            head->prev = NULL;
    }
    if (particle->next != NULL)
        particle->next->prev = particle->prev;
    if (particle->prev != NULL)
        particle->prev->next = particle->next;
    destroy_cube(particle->cubes);
    sfClock_destroy(particle->life);
    free(particle);
    return head;
}

particle_t *behave_particle(particle_t *particle, float offset)
{
    sfVector3f real;

    for (int i = 0; i < particle->nb_cube; ++i) {
        real.x = particle->cube_dir[i].x * (particle->velocity * offset);
        real.y = particle->cube_dir[i].y * (particle->velocity * offset);
        real.z = particle->cube_dir[i].z * (particle->velocity * offset);
        move_part(particle, i, real);
    }
    return particle;
}

particle_t *clean_particle_list(particle_t *head)
{
    particle_t *cur = head;
    particle_t *new_head = head;

    while (cur != NULL) {
        if (is_ready(cur->life, cur->lifetime)) {
            cur = remove_particle(cur);
            new_head = cur;
            continue;
        }
        cur = cur->next;
    }
    return new_head;
}