/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create images
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "window.h"
#include "quest.h"

images_t **create_menu(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_MENU + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_MENU; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    menu_creation(images);
    for (int j = 0; j < NBR_MENU; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_menu(images) == 84 ? NULL : images);
}

images_t **create_how_to_play(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_HOW + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_HOW; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    how_creation(images);
    for (int j = 0; j < NBR_HOW; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_how(images) == 84 ? NULL : images);
}

images_t **create_option(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_OPTION + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_OPTION; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    option_creation(images);
    for (int j = 0; j < NBR_OPTION; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_option(images) == 84 ? NULL : images);
}

images_t **create_pause(void)
{
    images_t **images = malloc(sizeof(images_t *) * (NBR_PAUSE + 1));

    if (!images)
        return (NULL);
    for (int i = 0; i < NBR_PAUSE; i++) {
        images[i] = malloc(sizeof(images_t));
        if (images[i] == NULL)
            return (NULL);
    }
    pause_creation(images);
    for (int j = 0; j < NBR_PAUSE; j++) {
        images[j]->sprite = sfSprite_create();
        if (!images[j]->sprite || !images[j]->texture)
            return (NULL);
        sfSprite_setTexture(images[j]->sprite, images[j]->texture, sfTrue);
    }
    return (set_images_scale_pause(images) == 84 ? NULL : images);
}

my_rpg_t *create_rpg(void)
{
    my_rpg_t *rpg = malloc(sizeof(my_rpg_t));

    if (!rpg)
        return (NULL);
    rpg->menu = create_menu();
    rpg->how = create_how_to_play();
    rpg->option = create_option();
    rpg->inventory = create_inventory();
    rpg->quest = create_quest();
    rpg->minimap = create_minimap();
    rpg->pause = create_pause();
    rpg->improve = create_improve();
    rpg->dock_menu = create_dock_menu();
    rpg->quest_menu = create_quest_menu();
    rpg->accept_quest = create_accept_quest();
    rpg = init_price(rpg);
    rpg = init_val_stats(rpg);
    rpg->gold = text_gold();
    rpg->imp_texts = text_improve(rpg);
    rpg->text_imp = 8;
    if (!rpg->menu || !rpg->how || !rpg->option || !rpg->pause ||
    !rpg->inventory || !rpg->quest || !rpg->minimap || !rpg->improve ||
    !rpg->quest_menu || !rpg->dock_menu || !rpg->accept_quest ||
    create_sound(rpg) == 84)
        return (NULL);
    return (rpg);
}