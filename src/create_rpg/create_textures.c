/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create textures
*/

#include "my_rpg.h"

void menu_creation(images_t **images)
{
    images[0]->texture = sfTexture_createFromFile("resources/images/bk.jpg",
    NULL);
    images[1]->texture = sfTexture_createFromFile("resources/images/play.png",
    NULL);
    images[2]->texture = sfTexture_createFromFile("resources/images/how.png",
    NULL);
    images[3]->texture = sfTexture_createFromFile("resources/images/option.png",
    NULL);
    images[4]->texture = sfTexture_createFromFile("resources/images/exit.png",
    NULL);
    images[5]->texture = sfTexture_createFromFile("resources/images/title.png",
    NULL);
}

void option_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/bk.jpg", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/back.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/button.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/slider.png", NULL);
    images[4]->texture
    = sfTexture_createFromFile("resources/images/title_op.png", NULL);
}

void improve_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/dock1.png", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/improve_menu.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/carpenter.png", NULL);
    for (int i = 3; i < 8; i++)
        images[i]->texture
        = sfTexture_createFromFile("resources/images/+.png", NULL);
    images[8]->texture
    = sfTexture_createFromFile("resources/images/carp_speech1.png", NULL);
    images[9]->texture
    = sfTexture_createFromFile("resources/images/cant_improve.png", NULL);
    images[10]->texture
    = sfTexture_createFromFile("resources/images/not_enough_cash.png", NULL);
    images[11]->texture
    = sfTexture_createFromFile("resources/images/speed_improve.png", NULL);
    images[12]->texture
    = sfTexture_createFromFile("resources/images/dmg_speech.png", NULL);
    images[13]->texture
    = sfTexture_createFromFile("resources/images/reload_speech.png", NULL);
    images[14]->texture
    = sfTexture_createFromFile("resources/images/range_speech.png", NULL);
    images[15]->texture
    = sfTexture_createFromFile("resources/images/nb_cannons_speech.png", NULL);
}

void how_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/bk.jpg", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/next.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/skip.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/old_pirate.png", NULL);
    images[4]->texture
    = sfTexture_createFromFile("resources/images/how_speech1.png", NULL);
    images[5]->texture
    = sfTexture_createFromFile("resources/images/how_speech2.png", NULL);
    images[6]->texture
    = sfTexture_createFromFile("resources/images/how_speech3.png", NULL);
    images[7]->texture
    = sfTexture_createFromFile("resources/images/how_speech4.png", NULL);
    images[8]->texture
    = sfTexture_createFromFile("resources/images/how_speech5.png", NULL);
}

void pause_creation(images_t **images)
{
    images[0]->texture
    = sfTexture_createFromFile("resources/images/bk.jpg", NULL);
    images[1]->texture
    = sfTexture_createFromFile("resources/images/exit.png", NULL);
    images[2]->texture
    = sfTexture_createFromFile("resources/images/resume.png", NULL);
    images[3]->texture
    = sfTexture_createFromFile("resources/images/how.png", NULL);
    images[4]->texture
    = sfTexture_createFromFile("resources/images/pause.png", NULL);
}