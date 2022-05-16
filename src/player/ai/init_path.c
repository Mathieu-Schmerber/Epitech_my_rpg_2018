/*
** EPITECH PROJECT, 2019
** init path
** File description:
** rpg
*/

#include "model.h"
#include "player.h"

path_t *init_path(void)
{
    path_t *res = malloc(sizeof(path_t));

    if (!res)
        return NULL;
    res->path_points = NULL;
    res->point = 0;
    return res;
}