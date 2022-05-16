/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create game texture
*/

#include "my_rpg.h"

void inventory_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/inventory.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/gold.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/map.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/quest.png", NULL);
    images[4]->texture
    = sfTexture_createFromFile("resources/images/cannonballs.png", NULL);
}

void minimap_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/parchment.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/saved_minimap.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/row.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/red_cross.png", NULL);
}

void dock_menu_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/dock1.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/improve.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/button_quest.png", NULL);
}

void quest_menu_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/parchment.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/red_cross.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/destroy.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/collect.png", NULL);
}

void accept_quest_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/dock1.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/accept.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/primary_quest.png", NULL);
}