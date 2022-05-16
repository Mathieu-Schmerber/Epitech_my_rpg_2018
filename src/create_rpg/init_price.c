/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create images
*/

#include <stdlib.h>
#include "model.h"
#include "my_rpg.h"
#include "player.h"
#include "lib.h"
#include "window.h"
#include "quest.h"

void set_gold_nb(my_rpg_t *rpg, game_t *game)
{
    sfVector2f txt_pos = {690, 965};

    sfText_setScale(rpg->gold->text[0]->text, (sfVector2f) {1, 1});
    sfText_setString(rpg->gold->text[0]->text,
    my_itoa(game->models->stat->gold));
    sfText_setPosition(rpg->gold->text[0]->text, txt_pos);
    sfText_setColor(rpg->gold->text[0]->text, sfYellow);
}

my_rpg_t *init_val_stats(my_rpg_t *rpg)
{
    int stats[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
        rpg->stats_imp[i] = stats[i];
    return rpg;
}

my_rpg_t *init_price(my_rpg_t *rpg)
{
    int price[5] = {100, 100, 100, 100, 1000};

    for (int i = 0; i < 5; i++)
        rpg->price[i] = price[i];
    return rpg;
}