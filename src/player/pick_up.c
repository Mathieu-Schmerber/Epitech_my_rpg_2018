/*
** EPITECH PROJECT, 2019
** chest
** File description:
** rpg
*/

#include "model.h"
#include "particles.h"
#include "player.h"
#include "my_rpg.h"
#include "window.h"

void spawn_random_chests(game_t *game, int nb)
{
    char *file = "resources/models/chest.legend";
    int count = 0;
    int index = 0;
    int used[NBR_CHEST] = {0, 0, 0, 0, 0, 0, 0};
    model_t *chest;

    while (count != nb) {
        index = rand() % NBR_CHEST;
        if (used[index] == 0) {
            used[index] = 1;
            count++;
        }
    }
    for (int i = 0; i < NBR_CHEST; ++i) {
        if (used[i] == 1) {
            chest = add_model(game->models, file, game->chest_pos[i], 1);
            chest->is_chest = 1;
        }
    }
}

void pickup_chest(game_t *game)
{
    model_t *player = get_player(game->models);
    model_t *cur = get_model_head(game->models);
    float r = 150;

    while (cur != NULL) {
        if (cur->is_chest && get_distance(player->center, cur->center) < r)
            sfRenderWindow_drawSprite(game->win->window,
            game->win->chest_msg->sprite, NULL);
        if (cur->is_chest && get_distance(player->center, cur->center) < r
        && sfKeyboard_isKeyPressed(sfKeyF)) {
            player->stat->gold += 500;
            spawn_particle((sfVector3f){0, 0, 1}, sfYellow, cur->center, game);
            destroy(cur);
            sfMusic_play(game->music[3]->sound);
            game->chest_picked++;
            break;
        }
        cur = cur->next;
    }
}