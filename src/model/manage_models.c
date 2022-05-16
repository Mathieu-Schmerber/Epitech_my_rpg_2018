/*
** EPITECH PROJECT, 2019
** manage
** File description:
** models
*/

#include <player.h>
#include "lib.h"
#include "model.h"
#include "map.h"

void init_ai_var(model_t *model)
{
    model->target_player = 0;
    model->chase_angle = 0;
    model->dest_reached = 0;
    model->dest = (sfVector3f){5000, 5000, 0};
    model->path = init_path();
}

cube_t *create_cube_list(char *f, model_t *model)
{
    init_t *init = open_model(f);

    if (init == NULL)
        return NULL;
    for (int i = 0; i < init->nb_cubes; ++i)
        add_cube(model, init->pos[i], init->scale[i], init->color[i]);
    model->is_dock = 0;
    if (my_strcmp(f, "resources/models/dock.legend") == 0)
        model->is_dock = 1;
    model->is_chest = (my_strcmp(f, "resources/models/chest.legend") ? 0 : 1);
    model->is_tower = (my_strcmp(f, "resources/models/tower.legend") ? 0 : 1);
    model->is_bullet = (my_strcmp(f, "resources/models/bullet.legend") ? 0 : 1);
    model->is_ai = 0;
    model->is_player = 0;
    model->is_chest = 0;
    free(init);
    return model->head;
}

carac_t *init_stats(model_t *model, int lvl)
{
    carac_t *res = malloc(sizeof(carac_t));

    if (!res) return (NULL);
    res->speed = 5 + lvl;
    res->lvl = lvl;
    res->bullet_damage = lvl * 2;
    res->health = lvl * 10;
    res->travel_range = 0;
    res->gold = 5000;
    res->right_shoot = sfClock_create();
    res->left_shoot = sfClock_create();
    res->shoot_cooldown = 1;
    res->shoot_nb = 2;
    res->bullet_speed = 20;
    model->length = SIZES[lvl - 1].x;
    model->width = SIZES[lvl - 1].y;
    model->center.x = model->length / 2;
    model->center.y = model->width / 2;
    model->center.z = 0;
    return (res);
}

model_t *create_model(char *file, sfVector3f pos, int lvl)
{
    model_t *model = malloc(sizeof(model_t));

    if (model == NULL)
        return NULL;
    model->rotation = 45;
    model->dir = (sfVector3f) {1, 0, 0};
    model->zoom = 2;
    model->next = NULL;
    model->prev = NULL;
    model->head = NULL;
    model->head = create_cube_list(file, model);
    model->is_bullet = 0;
    model->stat = init_stats(model, lvl);
    init_ai_var(model);
    if (model->stat == NULL || model->path == NULL)
        return NULL;
    model->stat->life_bar = create_life_bar();
    define_model_pos(model, pos);
    model->head = sort_cubes(model->head);
    return model;
}

model_t *add_model(model_t *head, char *file, sfVector3f pos, int lvl)
{
    model_t *current = head->next;

    if (current == NULL) {
        head->next = create_model(file, pos, lvl);
        if (head->next == NULL)
            return NULL;
        head->next->prev = head;
        return head->next;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = create_model(file, pos, lvl);
    if (current->next == NULL)
        return NULL;
    current->next->prev = current;
    return current->next;
}