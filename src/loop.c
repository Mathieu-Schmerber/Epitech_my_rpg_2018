/*
** EPITECH PROJECT, 2019
** loop
** File description:
** world
*/

#include "map.h"
#include "model.h"
#include "player.h"

void down_map(map_t *map, float offset)
{
    int size = map->size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            map->map_heights[y * size + x] -= offset;
    }
    refresh_heights(map);
}

void wave(map_t *water, float w_height)
{
    int size = water->size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            water->map_heights[y * size + x] = w_height;
    }
    refresh_heights(water);
}

int mainloop(game_t *game, my_rpg_t *rpg)
{
    int scene = 1;

    get_player(game->models)->stat->in_menu = 0;
    while (sfRenderWindow_isOpen(game->win->window)) {
        get_quest_state(game);
        if (sfKeyboard_isKeyPressed(sfKeyT))
            level_up(get_player(game->models));
        game->map->water->display = game->map->display;
        scene = display_window(game, rpg);
        manage_event(game);
        if (get_player(game->models)->stat->health <= 0) {
            sfRenderWindow_close(game->win->window);
            break;
        }
        if (scene == 5) {
            get_player(game->models)->stat->in_menu = 1;
            return (5);
        }
    }
    return (0);
}
