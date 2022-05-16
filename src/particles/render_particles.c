/*
** EPITECH PROJECT, 2019
** render
** File description:
** particles
*/

#include "window.h"
#include "my_rpg.h"
#include "model.h"
#include "particles.h" 

particle_t *get_particle_head(particle_t *p)
{
    particle_t *cur = p;

    if (p == NULL)
        return NULL;
    while (cur->prev != NULL)
        cur = cur->prev;
    return cur;
}

particle_t *render_particle(win_t *win, particle_t *part, model_t *m, float off)
{
    model_t *model = get_model_head(m);
    particle_t *head = get_particle_head(part);
    sfVector2u s = sfRenderWindow_getSize(win->window);
    cube_t *current;
    sfVector2f cam = get_cam_offset(model);

    if (head == NULL)
        return NULL;
    current = part->cubes;
    s = (sfVector2u){s.x / 2 - cam.x, s.y / 2 - cam.y};
    while (current != NULL) {
        convert_2d_cube(current->points_2d, current->points_3d, s.x, s.y);
        render_cube(win->window, current);
        current = current->next;
    }
    return behave_particle(part, off);
}
void render_particles(win_t *win, particle_t *particles, model_t *m, float off)
{
    particle_t *head = get_particle_head(particles);
    particle_t *cur = head;

    while (cur != NULL) {
        render_particle(win, head, m, off);
        cur = cur->next;
    }
}
