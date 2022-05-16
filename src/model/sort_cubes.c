/*
** EPITECH PROJECT, 2019
** sort
** File description:
** cubes
*/

#include "model.h"

void switch_cube(cube_t *left, cube_t *right)
{
    if (left->prev)
        left->prev->next = right;
    if (right->next)
        right->next->prev = left;
    left->next  = right->next;
    right->prev = left->prev;
    right->next = left;
    left->prev = right;
}

cube_t *get_head(cube_t *cube)
{
    cube_t *current = cube;

    while (current->prev != NULL)
        current = current->prev;
    return current;
}

void sort_by_x(cube_t *head)
{
    cube_t *current = head;
    cube_t *tmp = NULL;

    while (current) {
        tmp = current->prev;
        if (tmp && get_cube_center2d(tmp).x > get_cube_center2d(current).x
            && get_cube_center(tmp).z == get_cube_center(current).z
            && get_cube_center2d(tmp).y == get_cube_center2d(current).y) {
            switch_cube(tmp, current);
            current = get_head(current);
            continue;
        }
        current = current->next;
    }
}

void sort_by_y(cube_t *head)
{
    cube_t *current = head;
    cube_t *tmp = NULL;

    while (current) {
        tmp = current->prev;
        if (tmp && get_cube_center2d(tmp).y > get_cube_center2d(current).y
        && get_cube_center(tmp).z == get_cube_center(current).z) {
            switch_cube(tmp, current);
            current = get_head(current);
            continue;
        }
        current = current->next;
    }
}

cube_t *sort_cubes(cube_t *head)
{
    cube_t *current = head;
    cube_t *tmp = NULL;

    while (current) {
        tmp = current->prev;
        if (tmp && get_cube_center(tmp).z > get_cube_center(current).z) {
            switch_cube(tmp, current);
            current = get_head(current);
            continue;
        }
        current = current->next;
    }
    current = get_head(head);
    sort_by_y(current);
    sort_by_x(get_head(current));
    return get_head(current);
}