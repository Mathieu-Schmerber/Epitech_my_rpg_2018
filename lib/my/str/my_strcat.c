/*
** EPITECH PROJECT, 2019
** lib
** File description:
** concatenate two string
*/

#include <stdlib.h>
#include "lib.h"

char *concat(char *s1, char *s2, int i)
{
    char *res = my_strcat(s1, s2);

    if (i == 1)
        free(s1);
    else if (i == 2)
        free(s2);
    else {
        free(s1);
        free(s2);
    }
    return (res);
}

char *my_strcat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(s1) + my_strlen(s2);
    char *res = NULL;

    if (len)
        res = malloc(sizeof(char) * (len + 1));
    else
        return (NULL);
    if (s1) {
        for ( ; s1[i] != '\0'; i++)
            res[i] = s1[i];
        res[i] = '\0';
    }
    if (s2) {
        for ( ; s2[j] != '\0'; j++)
            res[j + i] = s2[j];
        res[i + j] = '\0';
    }
    return (res);
}
