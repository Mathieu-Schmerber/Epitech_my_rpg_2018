/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** pause menu
*/

#include <stdio.h>
#include "window.h"
#include "my_rpg.h"

int draw_pause(int scene, win_t *win, my_rpg_t *rpg, int *scene_before)
{
    int tmp[3] = {NBR_PAUSE - 1, scene, 4};

    draw_sprite(rpg->pause, win, NBR_PAUSE, -1);
    transparency(rpg->pause, win, tmp);
    scene = button_onclick(rpg->pause, win, win->event, tmp);
    if (scene == 2 || (sfKeyboard_isKeyPressed(sfKeyP) &&
    is_ready(win->button_clock, 1))) {
        return (1);
    }
    else if (scene == 3) {
        *scene_before = 5;
        return (2);
    }
    return (scene == 1 ? 4 : scene);
}