/*
** EPITECH PROJECT, 2019
** lib
** File description:
** gnl
*/

#include "lib.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *readline(int fd)
{
    char *str = NULL;
    char *temp;
    char buff[100 + 1];
    int ret;

    do {
        ret = read(fd, buff, 100);
        buff[ret] = '\0';
        temp = str;
        str = my_strcat(temp, buff);
        free(temp);
        for (int i = 0; buff[i] && ret; i++)
            ret = (buff[i] == '\n') ? 0 : ret;
    } while (ret > 0);
    return (str);
}

char *get_next_line(int fd)
{
    static char *str = NULL;
    char *res = NULL;
    char *temp = NULL;
    int n;

    if (!str) str = readline(fd);
    if (fd == -1 || !my_strlen(str) || !str) return (NULL);
    for (n = 0 ; str[n] && str[n] != '\n'; n++);
    if (str[n] == '\n') {
        res = (n) ? my_strdup_xy(str, 0, n) : my_strdup("");
        temp = str;
        str = (str[++n]) ? my_strdup_xy(str, n, 0) : NULL;
        if (temp) free(temp);
    } else {
        res = my_strdup(str);
        if (str) free (str);
        str = NULL;
        res = my_strcat(res, get_next_line(fd));
    }
    return (res);
}

