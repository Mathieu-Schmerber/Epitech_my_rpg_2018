/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** open model file parse it and store it
*/

#include "model.h"
#include "lib.h"

int check_line(char **nb, int res, int i)
{
    int j;
    int c = (i == 2) ? 4 : 3;
    float current;

    for (j = 0; j < c && nb[j]; j++) {
        current = my_atof(nb[j]);
        if (current < -255 || current > 255)
            return (-1);
        if (((current - (int)current) || current < 0) && i == 2)
            return (-1);
    }
    res = (j == c && !nb[j]) ? res : -1;
    return (res);
}

int check_args(char *line, int res)
{
    char **args;
    char **nb;
    int i;

    args = str_to_arr(line, '/');
    for (i = 0; i < 3 && args[i] && res >= 0; i++) {
        nb = str_to_arr(args[i], ',');
        res = check_line(nb, res, i);
        free_array(nb);
    }
    res = (i != 3 || res < 0 || args[i]) ? 0 : res + 1;
    free_array(args);
    return (res);
}

int check_error(char *path)
{
    int fd = open(path, O_RDONLY);
    char *line = NULL;
    int res = 0;
    int ret = 1;

    if (fd <= 0)
        return (-1);
    do {
        line = get_next_line(fd);
        if (!line) {
            ret--;
        } else {
            res = check_args(line, res);
            free(line);
        }
    } while (res && ret);
    close(fd);
    return (res);
}

