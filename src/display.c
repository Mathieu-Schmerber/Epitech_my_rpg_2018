/*
** EPITECH PROJECT, 2019
** disp
** File description:
** world
*/

#include <model.h>
#include "map.h"
#include "model.h"
#include "particles.h"
#include "my_rpg.h"
#include "player.h"

void render_obj(game_t *game, my_rpg_t *rpg)
{
    model_t *models = game->models;
    win_t *win = game->win;
    map_t *map = game->map;

    sfRenderWindow_clear(win->window, sfColor_fromRGB(0, 0, 50));
    rpg->quest_index = game->quest_nb % 2;
    render_map(map, win->window, models);
    render_chests(game->win->window, game);
    render_particles(win, game->particles, game->models, win->offset);
    print_life_bars(win, game->models);
}

int display_window(game_t *game, my_rpg_t *rpg)
{
    int scene = 1;
    model_t *models = game->models;
    win_t *win = game->win;
    model_t *player = get_player(models);
    sfVector2f pos = {player->center.x, player->center.y};

    render_obj(game, rpg);
    if (sfKeyboard_isKeyPressed(sfKeyP) && is_ready(win->button_clock, 1))
        scene = 5;
    if (get_dock_trigger(game) == 1 && game->models->stat->in_menu == 0) {
        call_dock_init(game, get_player(game->models));
        sfRenderWindow_drawSprite(game->win->window,
        game->win->dock_msg->sprite, NULL);
    } else if (get_dock_trigger(game) == 1 && game->models->stat->in_menu == 1)
        dock_menu(rpg, win, game);
    if (player->stat->in_menu != 1) {
        inventory(win, rpg, pos, player->rotation + 45);
        sfRenderWindow_drawText(win->window, rpg->gold->text[0]->text, NULL);
        pickup_chest(game);
    }
    set_gold_nb(rpg, game);
    sfRenderWindow_display(win->window);
    return (scene);
}