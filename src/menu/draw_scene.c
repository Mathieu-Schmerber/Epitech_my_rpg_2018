/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** PAQUES
*/

#include "window.h"
#include "my_rpg.h"

int draw_menu(int scene, win_t *win, my_rpg_t *rpg,
int __attribute__((unused)) *scene_before)
{
    int tmp[3] = {NBR_MENU, scene, 5};

    draw_sprite(rpg->menu, win, NBR_MENU, -1);
    transparency(rpg->menu, win, tmp);
    scene = button_onclick(rpg->menu, win, win->event, tmp);
    return (scene);
}

int draw_option(int scene, win_t *win, my_rpg_t *rpg,
int __attribute__((unused)) *scene_before)
{
    int tmp[3] = {2, scene, 8};

    draw_sprite(rpg->option, win, NBR_OPTION, -1);
    transparency(rpg->option, win, tmp);
    tmp[0] = NBR_OPTION;
    scene = button_onclick(rpg->option, win, win->event, tmp);
    if (scene == 1)
        return (0);
    return (move_slider(rpg, rpg->option, win));
}

int quit_rpg(int __attribute__((unused))scene, win_t *win,
my_rpg_t __attribute__((unused))*rpg, int __attribute__((unused)) *scene_before)
{
    sfRenderWindow_close(win->window);
    return (3);
}

int draw_game(int scene, win_t __attribute__((unused))*win,
my_rpg_t __attribute__((unused))*rpg, int __attribute__((unused)) *scene_before)
{
    return (scene);
}

int draw_how(int scene, win_t *win, my_rpg_t *rpg, int *scene_before)
{
    int tmp[3] = {3, scene, 5};
    static int i = 3;

    if (i > 8) {
        i = 4;
        return (0);
    }
    draw_sprite(rpg->how, win, 5, i);
    transparency(rpg->how, win, tmp);
    tmp[0] = NBR_HOW;
    tmp[1] = 0;
    scene = button_onclick(rpg->how, win, win->event, tmp);
    if (scene == 1)
        i++;
    else if (scene == 2)
        return (*scene_before == 1 ? 5 : 0);
    return (2);
}