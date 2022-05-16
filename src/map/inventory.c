/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** display minimap
*/

#include "my_rpg.h"
#include "window.h"
#include "map.h"

void display_minimap(win_t *win, images_t **image, sfVector2f position,
float angle)
{
    sfFloatRect rect;
    sfVector2f rotation;
    float mini_size = 500;

    image[2]->vector->set_position = position;
    rect = sfSprite_getLocalBounds(image[2]->sprite);
    rotation =
    (sfVector2f) {(rect.left + rect.width) / 2, (rect.top + rect.height) / 2};
    sfSprite_setOrigin(image[2]->sprite, rotation);
    sfSprite_setRotation(image[2]->sprite, angle);
    position.x /= 10;
    position.y /= 10;
    position.x += image[1]->vector->set_position.x + mini_size / 2;
    position.y += image[1]->vector->set_position.y + mini_size / 2;
    sfSprite_setPosition(image[2]->sprite, position);
    for (int j = 0; j < NBR_MINI_MAP; j++)
        sfRenderWindow_drawSprite(win->window, image[j]->sprite, NULL);
}

int quest(int which_object, win_t *win, my_rpg_t *rpg, int quest_index)
{
    int tmp[3] = {NBR_QUEST_MENU, which_object, NBR_QUEST_MENU};

    if (which_object == 3 ||
    (sfKeyboard_isKeyPressed(sfKeyG) && is_ready(win->button_clock, 1))) {
        for (int i = 0; i < 2; i++)
            sfRenderWindow_drawSprite(
            win->window, rpg->quest_menu[i]->sprite, NULL);
        quest_index == 0 ? sfRenderWindow_drawSprite(win->window,
        rpg->quest_menu[2]->sprite, NULL) :
        sfRenderWindow_drawSprite(win->window,
        rpg->quest_menu[3]->sprite, NULL);
        which_object = button_onclick(rpg->quest_menu, win, win->event, tmp);
        if (which_object == 1 ||
        (sfKeyboard_isKeyPressed(sfKeyG) && is_ready(win->button_clock, 1)))
            which_object = 0;
        else
            which_object = 3;
    }
    return (which_object);
}

void inventory(win_t *win, my_rpg_t *rpg, sfVector2f position, float angle)
{
    static int which_object = 0;
    int tmp[3] = {NBR_MINI_MAP, which_object, NBR_MINI_MAP};

    for (int i = 0; i < NBR_INVENTORY; i++)
        sfRenderWindow_drawSprite(win->window, rpg->inventory[i]->sprite, NULL);
    if (which_object == 2 ||
    (sfKeyboard_isKeyPressed(sfKeyM) && is_ready(win->button_clock, 1))) {
        display_minimap(win, rpg->minimap, position, angle);
        which_object = button_onclick(rpg->minimap, win, win->event, tmp);
        if (which_object == 3 ||
        (sfKeyboard_isKeyPressed(sfKeyM) && is_ready(win->button_clock, 1)))
            which_object = 0;
        else
            which_object = 2;
    } else if (which_object == 0)
        which_object = button_onclick(rpg->inventory, win, win->event, tmp);
    which_object = quest(which_object, win, rpg, rpg->quest_index);
}