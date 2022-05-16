/*
** EPITECH PROJECT, 2019
** quest
** File description:
** rpg
*/

#include "player.h"
#include "model.h"

int count_chests(model_t *model)
{
    model_t *cur = get_model_head(model);
    int count = 0;

    while (cur != NULL) {
        count += cur->is_chest;
        cur = cur->next;
    }
    return count;
}

void get_quest_state(game_t *game)
{
    int obj[2] = {-1, -1};
    static int need_chest = 1;

    if (game->quest_nb == 4)
        return;
    obj[game->quest_nb % 2] = 3;
    if (game->quest_nb % 2 == 1 && need_chest == 0) {
        spawn_random_chests(game, obj[1]);
        game->no_kill = 0;
        need_chest = 1;
    }
    if (obj[0] == game->boat_killed || obj[1] == game->chest_picked) {
        need_chest = 0;
        game->no_kill = 1;
        game->chest_picked = 0;
        game->boat_killed = 0;
        game->quest_nb++;
    }
}