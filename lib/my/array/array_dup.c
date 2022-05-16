/*
** EPITECH PROJECT, 2019
** lib
** File description:
** copy array
*/

#include "lib.h"

char **char_arr_dup(char **src)
{
    char **res = NULL;
    int arr_size = 0;

    while (src[arr_size])
        arr_size++;
    res = malloc(sizeof(char *) * (arr_size + 1));
    for (int i = 0; i < arr_size; i++)
        res[i] = my_strdup(src[i]);
    res[arr_size] = NULL;
    return (res);
}
