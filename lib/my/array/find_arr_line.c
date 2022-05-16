/*
** EPITECH PROJECT, 2019
** lib
** File description:
** find str pos in an array
*/

#include "lib.h"

int find_arr_line(char **arr, const char *s)
{
    int len = my_strlen(s);
    int n = 0;

    while (arr[n] && my_strncmp(arr[n], s, len))
        n++;
    if (!arr[n])
        n = -1;
    return (n);
}
