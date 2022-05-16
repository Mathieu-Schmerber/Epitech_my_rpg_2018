/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** dock
*/

#include <window.h>
#include "model.h"
#include "player.h"
#include "my_rpg.h"

void improve_stats(game_t *game, int nb)
{
    game->buy_nb++;
    if (game->buy_nb / 3 && game->buy_nb % 3)
        level_up(get_player(game->models));
    switch (nb) {
        case 0: game->models->stat->speed += game->models->stat->speed / 10;
            break;
        case 1: game->models->stat->bullet_damage +=
                game->models->stat->bullet_damage / 10;
            break;
        case 2: game->models->stat->shoot_cooldown -=
                game->models->stat->shoot_cooldown / 10;
            break;
        case 3: game->models->stat->bullet_speed +=
                game->models->stat->bullet_speed / 10;
            break;
        case 4: game->models->stat->shoot_nb++;
            break;
    }
}

int can_buy(my_rpg_t *rpg, int button_clicked, game_t *game)
{
    if (rpg->price[button_clicked] > game->models->stat->gold) {
        return 10;
    } else if (rpg->stats_imp[button_clicked] > 4) {
        return 9;
    } else {
        game->models->stat->gold -= rpg->price[button_clicked];
        rpg->price[button_clicked] *= 2;
        sfMusic_play(game->music[2]->sound);
        improve_stats(game, button_clicked);
        rpg->stats_imp[button_clicked]++;
        reset_text_imp(rpg);
        return button_clicked + 11;
    }
}

int improve(win_t *win, my_rpg_t *rpg, game_t *game)
{
    static int which_improve = -1;

    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawSprite(win->window, rpg->improve[i]->sprite, NULL);
    which_improve = clicked_button(rpg->improve, win, 3, 8);
    if (which_improve != -1) {
        which_improve = can_buy(rpg, which_improve - 3, game);
        rpg->text_imp = which_improve;
    }
    print_text_improve(rpg, game);
    sfRenderWindow_drawSprite(win->window,
    rpg->improve[rpg->text_imp]->sprite, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyH) && is_ready(win->button_clock, 1))
        return (0);
    return (1);
}

int quest_menu(win_t *win, my_rpg_t *rpg)
{
    int tmp[3] = {NBR_ACCEPT_QUEST, 0, NBR_ACCEPT_QUEST};

    for (int i = 0; i < NBR_ACCEPT_QUEST; i++)
        sfRenderWindow_drawSprite(win->window,
        rpg->accept_quest[i]->sprite, NULL);
    if ((sfKeyboard_isKeyPressed(sfKeyH) && is_ready(win->button_clock, 1)) ||
    button_onclick(rpg->accept_quest, win, win->event, tmp) == 1)
        return (0);
    return 2;
}

void dock_menu(my_rpg_t *rpg, win_t *win, game_t *game)
{
    static int which_scene = 0;
    int tmp[3] = {NBR_DOCK_MENU, which_scene, NBR_DOCK_MENU};

    for (int i = 0; i < NBR_DOCK_MENU; i++)
        sfRenderWindow_drawSprite(win->window, rpg->dock_menu[i]->sprite, NULL);
    which_scene = button_onclick(rpg->dock_menu, win, win->event, tmp);
    if (which_scene == 1) {
        which_scene = improve(win, rpg, game);
        if (which_scene != 1)
            which_scene = 0;
    } else if (which_scene == 2) {
        which_scene = quest_menu(win, rpg);
    }
    if (sfKeyboard_isKeyPressed(sfKeyH) && is_ready(win->button_clock, 1))
        game->models->stat->in_menu = 0;
}