/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** menu
*/

#include <window.h>
#include "my_rpg.h"
#include "map.h"

void draw_sprite(images_t **images, win_t *win, int nb_images, int print)
{
    sfRenderWindow_clear(win->window, sfGreen);
    for (int i = 0; i < nb_images; i++)
        sfRenderWindow_drawSprite(win->window, images[i]->sprite, NULL);
    if (print != -1)
        sfRenderWindow_drawSprite(win->window, images[print]->sprite, NULL);
    sfRenderWindow_display(win->window);
}

int menu(int scene, win_t *win, my_rpg_t *rpg, int *scene_before)
{
    int (*function[6])() =
    {draw_menu, draw_game, draw_how, draw_option, quit_rpg, draw_pause};

    return (function[scene](scene, win, rpg, &(*scene_before)));
}