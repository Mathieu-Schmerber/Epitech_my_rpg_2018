/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set game scale
*/

#include <stdlib.h>
#include "my_rpg.h"

int set_images_scale_inventory(images_t **image)
{
    for (int i = 0; i < NBR_INVENTORY; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {2, 1.2};
    image[1]->vector->scale = (sfVector2f) {0.08, 0.075};
    image[2]->vector->scale = (sfVector2f) {0.25, 0.19};
    image[3]->vector->scale = (sfVector2f) {0.25, 0.19};
    image[4]->vector->scale = (sfVector2f) {0.4, 0.4};
    set_sprite_pos_inventory(image);
    return (0);
}

int set_images_scale_minimap(images_t **image)
{
    for (int i = 0; i < NBR_MINI_MAP; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {0.8, 0.8};
    image[1]->vector->scale = (sfVector2f) {1, 1};
    image[2]->vector->scale = (sfVector2f) {0.1, 0.1};
    image[3]->vector->scale = (sfVector2f) {0.05, 0.05};
    set_sprite_pos_minimap(image);
    return (0);
}

int set_images_scale_dock_menu(images_t **image)
{
    for (int i = 0; i < NBR_DOCK_MENU; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {1, 1.2};
    image[1]->vector->scale = (sfVector2f) {1, 1};
    image[2]->vector->scale = (sfVector2f) {1, 1};
    set_sprite_pos_dock_menu(image);
    return (0);
}

int set_images_scale_quest_menu(images_t **image)
{
    for (int i = 0; i < NBR_QUEST_MENU; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {1, 1.2};
    image[1]->vector->scale = (sfVector2f) {0.05, 0.05};
    image[2]->vector->scale = (sfVector2f) {0.5, 0.5};
    image[3]->vector->scale = (sfVector2f) {0.5, 0.5};
    set_sprite_pos_quest_menu(image);
    return (0);
}

int set_images_scale_accept_quest(images_t **image)
{
    for (int i = 0; i < NBR_ACCEPT_QUEST; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {1, 1};
    image[1]->vector->scale = (sfVector2f) {1, 1};
    image[2]->vector->scale = (sfVector2f) {0.8, 0.8};
    set_sprite_pos_accept_quest(image);
    return (0);
}