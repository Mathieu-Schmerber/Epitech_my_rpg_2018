/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** PAQUES
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "window.h"

void set_sprite_pos_menu(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 192, WIN_Y / 2 - 130};
    image[2]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 192, WIN_Y / 2 + 20};
    image[3]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 192, WIN_Y / 2 + 170};
    image[4]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 192, WIN_Y / 2 + 320};
    image[5]->vector->set_position = (sfVector2f) {WIN_X / 2 - 480 * 0.7, 10};
    for (int i = 0; i < NBR_MENU; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_improve(images_t **images)
{
    images[0]->vector->set_position = (sfVector2f) {0, 0};
    images[1]->vector->set_position = (sfVector2f) {50, 50};
    images[2]->vector->set_position
    = (sfVector2f) {WIN_X / 2 + 315 , WIN_Y - 435};
    for (int i = 3; i < 8; i++)
        images[i]->vector->set_position
                = (sfVector2f) {560, 80 + (190 * (i - 3))};
    for (int i = 8; i < NBR_IMPROVE; i++)
        images[i]->vector->set_position = (sfVector2f) {WIN_X / 2 - 250, 200};
    for (int i = 0; i < NBR_IMPROVE; i++) {
        sfSprite_setScale(images[i]->sprite, images[i]->vector->scale);
        sfSprite_setPosition(images[i]->sprite, images[i]->vector->set_position);
    }
}

void set_sprite_pos_how(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position = (sfVector2f) {WIN_X - 320, WIN_Y - 170};
    image[2]->vector->set_position
    = (sfVector2f) {60, WIN_Y - 180};
    image[3]->vector->set_position
    = (sfVector2f) {WIN_X / 2 + 290, WIN_Y / 2 + 100};
    for (int i = 4; i < NBR_HOW; i++)
        image[i]->vector->set_position
        = (sfVector2f) {WIN_X / 2 - 420, WIN_Y / 2 - 380};
    for (int i = 0; i < NBR_HOW; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_option(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position = (sfVector2f) {WIN_X - 320, WIN_Y - 170};
    image[2]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 192, WIN_Y / 2};
    image[3]->vector->set_position
    = (sfVector2f) {WIN_X / 2 + 100, WIN_Y / 2};
    image[4]->vector->set_position
    = (sfVector2f) {WIN_X / 2 - 470, 10};
    for (int i = 0; i < NBR_OPTION; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_pause(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 154, WIN_Y / 2 + 150};
    image[2]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 154, WIN_Y / 2 - 150};
    image[3]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 154, WIN_Y / 2};
    image[4]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 394, 10};
    for (int i = 0; i < NBR_PAUSE; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}