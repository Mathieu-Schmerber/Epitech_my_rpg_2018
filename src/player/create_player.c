/*
** EPITECH PROJECT, 2019
** player
** File description:
** create
*/

#include "player.h"
#include "model.h"

model_t *get_player(model_t *model)
{
    model_t *res = get_model_head(model);

    while (res != NULL) {
        if (res->is_player == 1)
            return res;
        res = res->next;
    }
    return NULL;
}