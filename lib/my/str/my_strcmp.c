/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** task05
*/

#include "lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int loop = 0;

    loop = my_strlen(s1);
    if (my_strlen(s2) != my_strlen(s1))
        return 0;
    for (int i = 0; i < loop; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

int my_strncmp(char const *s1, char const *s2, int nb)
{
    int loop = nb;

    for (int i = 0; i < loop; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}