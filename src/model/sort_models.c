/*
** EPITECH PROJECT, 2019
** sort
** File description:
** model
*/

#include "model.h"

void switch_model(model_t *left, model_t *right)
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

model_t *sort_models(model_t *head)
{
    model_t *current = head;
    model_t *tmp = NULL;

    while (current) {
        tmp = current->prev;
        if (tmp && tmp->center.x > current->center.x) {
            switch_model(tmp, current);
            current = get_model_head(current);
            continue;
        }
        current = current->next;
    }
    current = get_model_head(head);
    return current;
}