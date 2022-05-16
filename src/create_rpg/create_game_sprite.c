/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create texture inventory
*/

#include <stdlib.h>
#include "window.h"
#include "my_rpg.h"

images_t **create_inventory(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_INVENTORY + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_INVENTORY; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    inventory_creation(images);
    for (int j = 0; j < NBR_INVENTORY; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_inventory(images) == 84 ? NULL : images);
}

images_t **create_minimap(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_MINI_MAP + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_MINI_MAP; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    minimap_creation(images);
    for (int j = 0; j < NBR_MINI_MAP; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_minimap(images) == 84 ? NULL : images);
}

images_t **create_improve(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_IMPROVE + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_IMPROVE; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    improve_creation(images);
    for (int i = 0; i < NBR_IMPROVE; i++) {
        images[i]->sprite = sfSprite_create();
        if (!images[i]->sprite)
            return (NULL);
        if (!images[i]->texture)
            return (NULL);
        sfSprite_setTexture(images[i]->sprite, images[i]->texture, sfTrue);
    }
    return (set_images_scale_improve(images) == 84 ? NULL : images);
}

images_t *create_msg(char *file)
{
    images_t *msg = malloc(sizeof(images_t));

    msg->vector = malloc(sizeof(vector_t));
    msg->texture
            = sfTexture_createFromFile(file, NULL);
    msg->sprite = sfSprite_create();
    sfSprite_setTexture(msg->sprite, msg->texture, sfTrue);
    msg->vector->set_position = (sfVector2f) {WIN_X / 2 - 170, WIN_Y - 200};
    msg->vector->scale = (sfVector2f) {.4, .4};
    sfSprite_setScale(msg->sprite, msg->vector->scale);
    sfSprite_setPosition(msg->sprite, msg->vector->set_position);
    return msg;
}

images_t **create_dock_menu(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_DOCK_MENU + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_DOCK_MENU; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    dock_menu_creation(images);
    for (int i = 0; i < NBR_DOCK_MENU; i++) {
        images[i]->sprite = sfSprite_create();
        if (!images[i]->sprite || !images[i]->texture)
            return (NULL);
        sfSprite_setTexture(images[i]->sprite, images[i]->texture, sfTrue);
    }
    return (set_images_scale_dock_menu(images) == 84 ? NULL : images);
}