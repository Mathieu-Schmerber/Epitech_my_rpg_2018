/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** model
*/

#include "model.h"

model_t *get_model_head(model_t *model)
{
    model_t *cur = model;

    while (cur->prev != NULL)
        cur = cur->prev;
    return cur;
}

void destroy_cube(cube_t *cube)
{
    cube_t *c = cube;
    cube_t *c_tmp;

    while (c != NULL) {
        c_tmp = c;
        c = c->next;
        free(c_tmp->points_2d);
        free(c_tmp->points_3d);
        for (int i = 0; i < 6; ++i)
            sfConvexShape_destroy(c_tmp->faces[i]);
        free(c_tmp->faces);
        free(c_tmp);
    }
}

model_t *destroy(model_t *model)
{
    model_t *head = get_model_head(model);
    model_t *tmp;

    tmp = model->next;
    if (model->prev == NULL)
        head->next = model->next;
    else
        model->prev->next = model->next;
    if (model->next != NULL)
        model->next->prev = model->prev;
    destroy_cube(model->head);
    free(model);
    return tmp;
}