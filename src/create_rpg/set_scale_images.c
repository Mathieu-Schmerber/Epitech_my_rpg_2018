/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set scale
*/

#include <stdlib.h>
#include "my_rpg.h"

int set_images_scale_menu(images_t **images)
{
    for (int i = 0; i < NBR_MENU; i++) {
        images[i]->vector = malloc(sizeof(vector_t));
        if (!images[i]->vector)
            return (84);
    }
    images[0]->vector->scale = (sfVector2f) {1.485, 1.5};
    for (int i = 1; i < 5; i++)
        images[i]->vector->scale = (sfVector2f) {1, 0.8};
    images[5]->vector->scale = (sfVector2f) {0.7, 0.6};
    set_sprite_pos_menu(images);
    return (0);
}

int set_images_scale_improve(images_t **images)
{
    for (int i = 0; i < NBR_IMPROVE; i++) {
        images[i]->vector = malloc(sizeof(vector_t));
        if (!images[i]->vector)
            return (84);
    }
    images[0]->vector->scale = (sfVector2f) {1, 1};
    images[1]->vector->scale = (sfVector2f) {1.2, 1.2};
    images[2]->vector->scale = (sfVector2f) {1.3, 1.4};
    for (int i = 3; i < 8; i++)
        images[i]->vector->scale = (sfVector2f) {1, 1};
    for (int i = 8; i < NBR_IMPROVE; i++)
        images[i]->vector->scale = (sfVector2f) {0.7, 0.7};
    set_sprite_pos_improve(images);
    return (0);
}

int set_images_scale_how(images_t **images)
{
    for (int i = 0; i < NBR_HOW; i++) {
        images[i]->vector = malloc(sizeof(vector_t));
        if (!images[i]->vector)
            return (84);
    }
    images[0]->vector->scale = (sfVector2f) {1.485, 1.5};
    images[1]->vector->scale = (sfVector2f) {0.7, 0.6};
    images[2]->vector->scale = (sfVector2f) {0.7, 0.6};
    images[3]->vector->scale = (sfVector2f) {0.6, 0.6};
    for (int i = 4; i < NBR_HOW; i++)
        images[i]->vector->scale = (sfVector2f) {0.8, 0.8};
    set_sprite_pos_how(images);
    return (0);
}

int set_images_scale_option(images_t **image)
{
    for (int i = 0; i < NBR_OPTION; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {1.485, 1.5};
    image[1]->vector->scale = (sfVector2f) {0.7, 0.6};
    for (int i = 2; i < 4; i++)
        image[i]->vector->scale = (sfVector2f) {1, 0.6};
    image[4]->vector->scale = (sfVector2f) {1, 1};
    set_sprite_pos_option(image);
    return (0);
}

int set_images_scale_pause(images_t **image)
{
    for (int i = 0; i < NBR_PAUSE; i++) {
        image[i]->vector = malloc(sizeof(vector_t));
        if (!image[i]->vector)
            return (84);
    }
    image[0]->vector->scale = (sfVector2f) {1.485, 1.5};
    image[1]->vector->scale = (sfVector2f) {0.8, 0.8};
    image[2]->vector->scale = (sfVector2f) {0.8, 0.8};
    image[3]->vector->scale = (sfVector2f) {0.8, 0.8};
    image[4]->vector->scale = (sfVector2f) {1, 1};
    set_sprite_pos_pause(image);
    return (0);
}