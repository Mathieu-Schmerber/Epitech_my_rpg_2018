/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** create sound
*/

#include <stdlib.h>
#include "my_rpg.h"

void change_volume(my_rpg_t *rpg, float volume)
{
    for (int i = 0; i < NBR_MUSIC; i++) {
        sfMusic_setVolume(rpg->music[i]->sound, volume);
    }
}

int create_sound(my_rpg_t *rpg)
{
    rpg->music = malloc(sizeof(music_t *) * (NBR_MUSIC + 1));
    if (!rpg->music)
        return (84);
    for (int i = 0; i < NBR_MUSIC; i++) {
        rpg->music[i] = malloc(sizeof(music_t));
        if (!rpg->music[i])
            return (84);
    }
    rpg->music[0]->sound = sfMusic_createFromFile("resources/sound/menu.ogg");
    rpg->music[1]->sound = sfMusic_createFromFile("resources/sound/canon.ogg");
    rpg->music[2]->sound =
    sfMusic_createFromFile("resources/sound/construc.ogg");
    rpg->music[3]->sound = sfMusic_createFromFile("resources/sound/coin.ogg");
    sfMusic_setLoop(rpg->music[0]->sound, sfTrue);
    sfMusic_setVolume(rpg->music[0]->sound, 70);
    return (0);
}