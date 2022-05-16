/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** find a path between two points
*/

#include <stdio.h>
#include "lib.h"
#include "player.h"

node_t *is_valid(node_t *cl, float *a, node_t *parent, int p[])
{
    node_t *res = NULL;
    node_t *tmp = cl;
    int x = p[0];
    int y = p[1];

    while (tmp) {
	if ((tmp->pos[0] == x && tmp->pos[1] == y) || a[y * p[4] + x] >= 100)
            return (res);
        tmp = tmp->next;
    }
    res = create_node(p[0], p[1], parent, p);
    return (res);
}

void add_to_l(node_t **start, node_t *n)
{
    node_t *tmp = (*start);

    if (!n)
	return;
    if (tmp) {
        while (tmp->next)
            tmp = tmp->next;
	tmp->next = n;
        n->prev = tmp;
    } else
        *(start) = n;
}

void free_ol(node_t **ol, node_t **cl, node_t *last)
{
    node_t *tmp = *ol;

    add_to_l(cl, last);
    while (tmp->next) {
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
    *ol = NULL;
}

void astar_alg(node_t **ol, node_t **cl, float *a, int p[])
{
    node_t *c = find_least_f(ol);
    node_t *tmp = NULL;
    int t = 0;

    add_to_l(cl, c);
    for (int i = -1; !t && i < 2 && (c->pos[1] + i) < p[4]; i++) {
        i += ((c->pos[1] + i) >= 0) ? 0 : 1;
        for (int j = -1; !t && j < 2 && (c->pos[0] + j) < p[4]; j++) {
            j += ((c->pos[0] + j) >= 0) ? 0 : 1;
            p[0] = c->pos[0] + j;
            p[1] = c->pos[1] + i;
            tmp = is_valid(*cl, a, c, p);
            t = (p[0] == p[2] && p[1] == p[3]) ? 1 : 0;
            (t) ? free_ol(ol, cl, tmp) : add_to_l(ol, tmp);
        }
    }
}
