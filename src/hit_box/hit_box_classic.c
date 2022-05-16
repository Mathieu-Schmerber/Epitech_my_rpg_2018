/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** button hitbox
*/

#include "window.h"
#include "my_rpg.h"

int clicked_button(images_t **images, win_t *win, int start, int end)
{
    sfVector2i mouse_pos;
    sfFloatRect rect_verif;

    for (int i = start; i < end; i++) {
        rect_verif = sfSprite_getGlobalBounds(images[i]->sprite);
        mouse_pos = sfMouse_getPositionRenderWindow(win->window);
        if (mouse_pos.x > rect_verif.left &&
        mouse_pos.x < rect_verif.left + rect_verif.width &&
        mouse_pos.y > rect_verif.top &&
        mouse_pos.y < rect_verif.top + rect_verif.height &&
        win->event.type == sfEvtMouseButtonPressed &&
        is_ready(win->button_clock, 1) == 1) {
            mouse_hover(images[i], 1);
            return i;
        }
    }
    return -1;
}