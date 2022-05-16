/*
** EPITECH PROJECT, 2019
** lvl
** File description:
** rpg
*/

#include "player.h"
#include "model.h"

void refresh_stats(model_t *model)
{
    model->stat->speed = 5 + model->stat->lvl;
    model->stat->lvl = model->stat->lvl;
    model->stat->bullet_damage = model->stat->lvl * 2;
    model->stat->health = model->stat->lvl * 10;
    model->length = SIZES[model->stat->lvl - 1].x;
    model->width = SIZES[model->stat->lvl - 1].y;
    model->center = (sfVector3f) {model->length / 2, model->width / 2, 0};
}

void level_up(model_t *model)
{
    char *source[3] = {"resources/models/boat1.legend",
    "resources/models/boat2.legend", "resources/models/boat3.legend"};
    init_t *init;
    sfVector3f save = model->center;

    if (model->stat->lvl == 3)
        return;
    model->stat->lvl += 1;
    destroy_cube(model->head);
    model->head = NULL;
    init = open_model(source[model->stat->lvl - 1]);
    if (init == NULL)
        return;
    for (int i = 0; i < init->nb_cubes; ++i)
        add_cube(model, init->pos[i], init->scale[i], init->color[i]);
    refresh_stats(model);
    define_model_pos(model, save);
    model->dir = (sfVector3f) {1, 0, 0};
    free(init);
}