/*
** EPITECH PROJECT, 2019
** lib
** File description:
** str to array
*/

#include "lib.h"

int nb_args(const char *s, char c)
{
    int res = 0;
    int len = my_strlen(s);
    int i = 0;

    while (i < len) {
        while (s[i] == c && i < len)
            i++;
        res += (i < len) ? 1 : 0;
        while (s[i] != c && i < len)
            i++;
    }
    return (res);
}

char **str_to_arr(const char *s, char c)
{
    int nb_arg = nb_args(s, c);
    char **res = malloc(sizeof(char *) * (nb_arg + 1));
    int len = my_strlen(s);
    int arg = 0;
    int j = 0;

    for (int i = 0; i < len && arg < nb_arg; arg++) {
        while (s[i] == c && i < len)
            i++;
        for (j = 0; s[i + j] != c && i + j < len; j++);
        res[arg] = my_strdup_xy(s, i, i + j);
        i += j;
    }
    res[nb_arg] = NULL;
    return (res);
}
