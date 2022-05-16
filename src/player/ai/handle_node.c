/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** create pop and push nodes
*/

#include <stdlib.h>
#include <math.h>
#include "player.h"

node_t *create_node(int x, int y, node_t *parent, int p[])
{
    node_t *r = malloc(sizeof(node_t));
    int d = 0;

    if (!r)
        return NULL;
    r->p = parent;
    r->next = NULL;
    r->prev = NULL;
    r->pos[0] = x;
    r->pos[1] = y;
    if (parent)
        d = r->p->g + (r->p->pos[0] == x || r->p->pos[1] == y) ? 17 : 24;
    r->g = d;
    r->h = sqrt(pow(x - p[2], 2) + pow(y - p[3], 2));
    r->f = d + r->h;
    return (r);
}

node_t *cut_node(node_t **start, int n)
{
    node_t *ret = (*start);

    for (int i = 0; i < n && ret; i++)
        ret = ret->next;
    if (ret->prev) {
        ret->prev->next = ret->next;
	ret->prev = NULL;
    } else
        *start = ret->next;
    if (ret->next) {
	ret->next->prev = ret->prev;
	ret->next = NULL;
    }
    return (ret);
}

node_t *find_least_f(node_t **ol)
{
    int next_node = 0;
    node_t *tmp = (*ol);
    float least = tmp->f;

    for (int i = 0; tmp; i++) {
        if (tmp->f < least) {
            next_node = i;
            least = tmp->f;
	}
        tmp = tmp->next;
    }
    tmp = (least >= 0) ? cut_node(ol, next_node) : NULL;
    return (tmp);
}
