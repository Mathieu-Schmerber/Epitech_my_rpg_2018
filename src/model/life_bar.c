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

void print_life_bars(win_t *win, model_t *model)
{
    model_t *tmp = get_model_head(model);

    while (tmp != NULL) {
        if (tmp->is_player == 1 || tmp->is_ai == 1) {
            set_pos_and_size(tmp, tmp->stat->life_bar);
            sfRenderWindow_drawRectangleShape(win->window, tmp->stat->life_bar,
            NULL);
        }
        tmp = tmp->next;
    }
}

void set_pos_and_size(model_t *model, sfRectangleShape *tmp)
{
    sfVector2f center = get_cube_center2d(model->head);
    int mdl_h = 0;

    if (model->is_player == 1) {
    	mdl_h = model->stat->health;
        sfRectangleShape_setSize(tmp, (sfVector2f) {mdl_h * 20, 10});
        sfRectangleShape_setPosition(tmp,
        (sfVector2f) {WIN_X - mdl_h * 20 - 20, 10});
    } else if (model->is_ai == 1) {
    	mdl_h = model->stat->health;
        sfRectangleShape_setSize(tmp, (sfVector2f) {mdl_h * 5, 10});
        sfRectangleShape_setPosition(tmp,
        (sfVector2f) {center.x - mdl_h * 5 / 2, center.y - 40});
    }
}

sfRectangleShape *create_life_bar(void)
{
    sfRectangleShape *tmp = sfRectangleShape_create();

    if (!tmp)
        return NULL;
    sfRectangleShape_setFillColor(tmp, sfRed);
    return tmp;
}