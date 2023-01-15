/*
** EPITECH PROJECT, 2019
** win
** File description:
** world
*/

#include "my_rpg.h"
#include "map.h"

sfRenderWindow *new_window(int width, int height, int bpp, char *t)
{
    sfRenderWindow *w;

    sfVideoMode video = {width, height, bpp};
    w = sfRenderWindow_create(video, t, sfResize, NULL);
    if (!w)
        return (NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    sfRenderWindow_setVerticalSyncEnabled(w, sfTrue);
    return (w);
}

int set_resolution(win_t *win)
{
    win->resolution = malloc(sizeof(sfVector2u) * 4);
    if (!win->resolution)
        return (84);
    win->resolution[0] = (sfVector2u){1920, 1080};
    win->resolution[1] = (sfVector2u){960, 800};
    win->resolution[2] = (sfVector2u){800, 600};
    return (0);
}

win_t *create_window(char *title)
{
    win_t *win = malloc(sizeof(win_t));

    if (!win)
        return (NULL);
    win->window = new_window(WIN_X, WIN_Y, BPP, title);
    win->dock_msg = create_msg("resources/images/dock_msg.png");
    win->chest_msg = create_msg("resources/images/treasure_claim.png");
    if (!win->window || set_resolution(win) == 84)
        return (NULL);
    win->prev_frame = 0;
    win->global_clock = sfClock_create();
    win->button_clock = sfClock_create();
    win->duck_clock = sfClock_create();
    return (win);
}
