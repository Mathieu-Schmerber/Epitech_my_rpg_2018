/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set position game
*/

#include "my_rpg.h"
#include "window.h"

void set_sprite_pos_inventory(images_t **image)
{
    image[0]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 302, WIN_Y - 130};
    image[1]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 198, WIN_Y - 122};
    image[2]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 80, WIN_Y - 125};
    image[3]->vector->set_position =
    (sfVector2f) {WIN_X / 2 + 30, WIN_Y - 123};
    image[4]->vector->set_position =
    (sfVector2f) {WIN_X / 2 + 240, WIN_Y - 123};
    for (int i = 0; i < NBR_INVENTORY; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_minimap(images_t **image)
{
    image[0]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 295, WIN_Y / 2 - 295};
    image[1]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 250, WIN_Y / 2 - 250};
    image[2]->vector->set_position =
    (sfVector2f) {WIN_X / 2, WIN_Y / 2 - 20};
    image[3]->vector->set_position =
    (sfVector2f) {WIN_X / 2 + 240, WIN_Y / 2 - 275};
    for (int i = 0; i < NBR_MINI_MAP; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_dock_menu(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 550, WIN_Y / 2 - 59};
    image[2]->vector->set_position =
    (sfVector2f) {WIN_X / 2 + 200, WIN_Y / 2 - 59};
    for (int i = 0; i < NBR_DOCK_MENU; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_quest_menu(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {WIN_X - 737, 35};
    image[1]->vector->set_position = (sfVector2f) {WIN_X - 65, 70};
    image[2]->vector->set_position = (sfVector2f) {WIN_X - 600, WIN_Y / 2 - 250};
    image[3]->vector->set_position = (sfVector2f) {WIN_X - 600, WIN_Y / 2};
    for (int i = 0; i < NBR_QUEST_MENU; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}

void set_sprite_pos_accept_quest(images_t **image)
{
    image[0]->vector->set_position = (sfVector2f) {0, 0};
    image[1]->vector->set_position = (sfVector2f) {WIN_X / 2 - 192, WIN_Y - 250};
    image[2]->vector->set_position =
    (sfVector2f) {WIN_X / 2 - 374, 10};
    for (int i = 0; i < NBR_ACCEPT_QUEST; i++) {
        sfSprite_setScale(image[i]->sprite, image[i]->vector->scale);
        sfSprite_setPosition(image[i]->sprite, image[i]->vector->set_position);
    }
}