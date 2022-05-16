/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** free all struct
*/

#include <stdlib.h>
#include "model.h"
#include "my_rpg.h"
#include "window.h"
#include "map.h"

void destroy_images(images_t **images, int nb_images)
{
    for (int i = 0; i != nb_images; i++) {
        sfSprite_destroy(images[i]->sprite);
        sfTexture_destroy(images[i]->texture);
        free(images[i]->vector);
        free(images[i]);
    }
    free(images);
}

void destroy_sounds(music_t **music, int nb_sound)
{
    for (int i = 0; i != nb_sound; i++) {
        sfMusic_destroy(music[i]->sound);
        free(music[i]);
    }
    free(music);
}

void destroy_game(game_t *game)
{
    sfClock_destroy(game->win->duck_clock);
    sfClock_destroy(game->win->button_clock);
    sfClock_destroy(game->win->global_clock);
    sfClock_destroy(game->spawn_clock);
    free(game->chest_pos);
    free(game->win->chest_msg);
    free(game->win->dock_msg);
    destroy(game->models);
    free_map(game->map->water);
    free_map(game->map);
}

void destroy_all(my_rpg_t *rpg)
{
    destroy_images(rpg->menu, NBR_MENU);
    destroy_images(rpg->option, NBR_OPTION);
    destroy_images(rpg->how, NBR_HOW);
    destroy_images(rpg->pause, NBR_PAUSE);
    destroy_images(rpg->inventory, NBR_INVENTORY);
    destroy_images(rpg->minimap, NBR_MINI_MAP);
    destroy_images(rpg->quest_menu, NBR_QUEST_MENU);
    destroy_images(rpg->accept_quest, NBR_ACCEPT_QUEST);
    destroy_images(rpg->dock_menu, NBR_DOCK_MENU);
    destroy_images(rpg->improve, NBR_IMPROVE);
    destroy_sounds(rpg->music, NBR_MUSIC);
}