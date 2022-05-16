/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main loop
*/

#include "my_rpg.h"
#include "map.h"
#include "window.h"
#include "player.h"
#include "model.h"

game_t *init_var_game(game_t *game, char **source, map_t *map, my_rpg_t *rpg)
{
    game->win = create_window("My RPG");
    game->models = create_model(source[0], (sfVector3f) {0, 0, 0}, 1);
    game->map = map;
    game->particles = NULL;
    game->spawn_clock = sfClock_create();
    game->quest_nb = 0;
    game->boat_killed = 0;
    game->chest_picked = 0;
    game->no_kill = 1;
    game->buy_nb = 0;
    if (!game->win || !game->models)
        return NULL;
    game->chest_pos = malloc(sizeof(sfVector3f) * NBR_CHEST);
    if (!game->chest_pos)
        return NULL;
    game->models->is_player = 1;
    game->models->stat->in_menu = 1;
    game->music = rpg->music;
    return (game);
}

int handle_map(map_t *map, game_t *game, char *source[6])
{
    model_t *dock;

    wave(map->water, 5);
    down_map(map, 5);
    down_map(map->water, 5);
    map->points2d = convert3d_points(map, game->win->window);
    map->water->points2d = convert3d_points(map->water, game->win->window);
    get_map_points(map->water->points3d, map->water->map_heights,
    MAP_SIZE, MAP_ZOOM);
    dock = add_model(game->models, source[3], (sfVector3f){-80, -235, 0}, 1);
    if (dock == NULL)
        return 84;
    spawn_tower(game, (sfVector3f){1830, -1925, 0}, source[5]);
    return 0;
}

game_t *init_game(map_t *map, my_rpg_t *rpg)
{
    game_t *game = malloc(sizeof(game_t));
    char *source[6] = {"resources/models/boat1.legend",
    "resources/models/boat2.legend", "resources/models/boat3.legend",
    "resources/models/dock.legend", "resources/models/chest.legend",
    "resources/models/tower.legend"};
    sfVector3f chest_spawns[7] = {{1770, 1972, 0}, {1101, 1333, 0},
    {-940, 1121, 0}, {-1760, 1529, 0}, {-1740, 0, 0}, {-2220, -1867, 0},
    {1925, -1872, 0}};

    if (!game)
        return NULL;
    game = init_var_game(game, source, map, rpg);
    if (!game)
        return (NULL);
    for (int i = 0; i < NBR_CHEST; ++i)
        game->chest_pos[i] = chest_spawns[i];
    if (handle_map(map, game, source) == 84)
        return NULL;
    return game;
}

void tmp(int *scene, int *before_scene, game_t *game, my_rpg_t *rpg)
{
    if (*before_scene == 5 && *scene == 0) {
        *scene = 5;
        *before_scene = 0;
    } else if (*scene == 1) {
        get_player(game->models)->stat->in_menu = 0;
        *scene = mainloop(game, rpg);
    }
}

int open_window(map_t *map, my_rpg_t *rpg)
{
    int scene = 0;
    int before_scene = 0;
    game_t *game = init_game(map, rpg);
    sfVector3f vector = {0, 1, 0};

    if (game == NULL || get_player(game->models) == NULL)
        return 84;
    sfMusic_play(rpg->music[0]->sound);
    while (sfRenderWindow_isOpen(game->win->window)) {
        sfListener_setUpVector(vector);
        sfRenderWindow_clear(game->win->window, sfGreen);
        scene = menu(scene, game->win, rpg, &before_scene);
        manage_event(game);
        tmp(&scene, &before_scene, game, rpg);
    }
    destroy_all(rpg);
    destroy_game(game);
    return (0);
}