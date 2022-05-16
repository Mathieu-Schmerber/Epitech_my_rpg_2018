/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** button hitbox
*/

#include "window.h"
#include "my_rpg.h"

void mouse_hover(images_t *image, int i)
{
    sfColor color = sfSprite_getColor(image->sprite);

    if (i == 0) {
        color.a = 200;
        sfSprite_setColor(image->sprite, color);
    } else {
        color.a = 255;
        sfSprite_setColor(image->sprite, color);
    }
}

void transparency(images_t **image, win_t *win, int const *tmp)
{
    sfVector2i mouse_pos;
    sfFloatRect rect_verif;

    for (int i = 1; i < tmp[0]; i++) {
        rect_verif = sfSprite_getGlobalBounds(image[i]->sprite);
        mouse_pos = sfMouse_getPositionRenderWindow(win->window);
        if (mouse_pos.x > rect_verif.left &&
        mouse_pos.x < rect_verif.left + rect_verif.width &&
        mouse_pos.y > rect_verif.top &&
        mouse_pos.y < rect_verif.top + rect_verif.height && i < 5)
            mouse_hover(image[i], 0);
        else
            mouse_hover(image[i], 1);
    }
}

int move_slider(my_rpg_t *rpg, images_t **image, win_t *win)
{
    float vol;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect rect_verif = sfSprite_getGlobalBounds(image[2]->sprite);

    if (mouse_pos.x > rect_verif.left &&
    mouse_pos.x < rect_verif.left + rect_verif.width &&
    mouse_pos.y > rect_verif.top &&
    mouse_pos.y < rect_verif.top + rect_verif.height &&
    mouse_pos.x >= WIN_X / 2 - 140 && mouse_pos.x <= WIN_X / 2 + 100)
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            image[3]->vector->set_position.x = mouse_pos.x;
            sfSprite_setPosition(image[3]->sprite,
            image[3]->vector->set_position);
            draw_sprite(rpg->option, win, NBR_OPTION, -1);
            vol = (sfRenderWindow_getSize(win->window).x / 2 - 140 -
            image[3]->vector->set_position.x) * -100 / 240;
            change_volume(rpg, vol);
        }
    return (3);
}

int button_onclick(images_t **image, win_t *win, sfEvent event, int *tmp)
{
    sfVector2i mouse_pos;
    sfFloatRect rect_verif;

    for (int i = 1; i < tmp[0]; i++) {
        rect_verif = sfSprite_getGlobalBounds(image[i]->sprite);
        mouse_pos = sfMouse_getPositionRenderWindow(win->window);
        if (mouse_pos.x > rect_verif.left &&
        mouse_pos.x < rect_verif.left + rect_verif.width &&
        mouse_pos.y > rect_verif.top &&
        mouse_pos.y < rect_verif.top + rect_verif.height &&
        event.type == sfEvtMouseButtonPressed &&
        is_ready(win->button_clock, 1) == 1) {
            mouse_hover(image[i], 1);
            return (i >= tmp[2] ? 0 : i);
        }
    }
    return (tmp[1]);
}