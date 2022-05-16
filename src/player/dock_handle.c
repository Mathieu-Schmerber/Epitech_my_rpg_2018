/*
** EPITECH PROJECT, 2019
** dock
** File description:
** rpg
*/

#include <stdlib.h>
#include "model.h"
#include "window.h"
#include "my_rpg.h"
#include "player.h"

void call_dock_init(game_t *game, model_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && is_ready(game->win->button_clock, 1))
        player->stat->in_menu = 1;
}

int get_dock_trigger(game_t *game)
{
    model_t *dock = get_model_head(game->models);
    model_t *player = get_player(game->models);
    int range = 200;

    while (dock != NULL) {
        if (dock->is_dock == 1)
            break;
        dock = dock->next;
    }
    if (dock == NULL || get_distance(dock->center, player->center) > range)
        return 0;
    return 1;
}