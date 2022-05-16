/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** path finding algorithm
*/

#include <stdio.h>
#include "lib.h"
#include "map.h"
#include "player.h"

sfVector3f *path_to_list(node_t *dst)
{
    sfVector3f *res = NULL;
    node_t *tmp = dst;
    int c = 0;

    for (c = 0; tmp; c++)
        tmp = tmp->p;
    res = malloc(sizeof(sfVector3f) * (c + 2));
    if (!res)
        return NULL;
    for (int i = 0; i < c; i++) {
        res[c - i - 1].x = INDEX_MAP(dst->pos[0]);
        res[c - i - 1].y = INDEX_MAP(dst->pos[1]);
        res[c - i - 1].z = 0;
        dst = dst->p;
    }
    res[c].x = -1;
    res[c].y = -1;
    res[c].z = -1;
    return (res);
}

void free_cl(node_t **cl)
{
    node_t *tmp = *cl;

    while (tmp->next) {
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
    *cl = NULL;
}

sfVector3f *astar(float *a, int pos[])
{
    node_t *open_list = NULL;
    node_t *closed_list = NULL;
    sfVector3f *res = NULL;

    open_list = create_node(pos[0], pos[1], NULL, pos);
    while (open_list)
        astar_alg(&open_list, &closed_list, a, pos);
    open_list = closed_list;
    while (open_list->next)
        open_list = open_list->next;
    res = path_to_list(open_list);
    free_cl(&closed_list);
    return (res);
}
