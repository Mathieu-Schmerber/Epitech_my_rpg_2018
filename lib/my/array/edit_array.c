/*
** EPITECH PROJECT, 2019
** lib
** File description:
** re alloc array
*/

#include "lib.h"

char **arr_add(char **arr, char *add, int x)
{
    int size = 0;
    char **res = NULL;
    int i;

    while (arr[size])
        size++;
    size++;
    res = malloc(sizeof(char *) * (size + 1));
    x = (x < 0) ? size - 1 : x;
    for (i = 0; i < x || x >= size; i++)
        res[i] = my_strdup(arr[i]);
    res[i++] = (add) ? my_strdup(add) : NULL;
    for ( ; i < size; i++)
        res[i] = my_strdup(arr[i - 1]);
    res[size] = NULL;
    return (res);
}

char **arr_rem(char **arr, int x)
{
    int size = 0;
    char **res = NULL;
    int i;

    while (arr[size])
        size++;
    res = malloc(sizeof(char *) * (size));
    x = (x < 0 || x >= size) ? size - 1 : x;
    for (i = 0; i < x; i++)
        res[i] = my_strdup(arr[i]);
    i++;
    for ( ; i < size; i++)
        res[i - 1] = my_strdup(arr[i]);
    res[size - 1] = NULL;
    return (res);
}
