/*
** EPITECH PROJECT, 2019
** create
** File description:
** rpg
*/

#include <stdlib.h>
#include "window.h"
#include "my_rpg.h"

images_t **create_accept_quest(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_ACCEPT_QUEST + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_ACCEPT_QUEST; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    accept_quest_creation(images);
    for (int j = 0; j < NBR_ACCEPT_QUEST; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_accept_quest(images) == 84 ? NULL : images);
}

images_t **create_quest_menu(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_QUEST_MENU + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_QUEST_MENU; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    quest_menu_creation(images);
    for (int i = 0; i < NBR_QUEST_MENU; i++) {
        images[i]->sprite = sfSprite_create();
        if (!images[i]->sprite || !images[i]->texture)
            return (NULL);
        sfSprite_setTexture(images[i]->sprite, images[i]->texture, sfTrue);
    }
    return (set_images_scale_quest_menu(images) == 84 ? NULL : images);
}