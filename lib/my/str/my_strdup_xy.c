/*
** EPITECH PROJECT, 2019
** lib
** File description:
** copy and malloc str between x and y
*/

#include <stdlib.h>
#include "lib.h"

char *my_strdup_xy(const char *line, int start, int end)
{
    int len;
    char *res;

    if (!end)
        end = my_strlen(line);
    len = end - start;
    res = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        res[i] = line[i + start];
    res[len] = '\0';
    return (res);
}
