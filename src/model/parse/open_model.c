/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** open model file parse it and store it
*/

#include "model.h"
#include "lib.h"

void fill_sfv(sfVector3f *res, int j, float value)
{
    if (!j)
        res->x = value;
    else if (j == 1)
        res->y = value;
    else
        res->z = value;
}

void fill_sfc(sfColor *res, int j, int value)
{
    if (!j)
        res->r = value;
    else {
        if (j == 1)
            res->g = value;
        else if (j == 2)
            res->b = value;
        else
            res->a = value;
    }
}

void fill_struct(char **nb, init_t *res, int i, int x)
{
    int c = (i == 2) ? 4 : 3;
    float value;

    for (int j = 0; j < c; j++) {
        value = my_atof(nb[j]);
        if (!i)
            fill_sfv((&res->pos[x]), j, value);
        else if (i == 1)
            fill_sfv(&(res->scale[x]), j, value);
        else
            fill_sfc(&(res->color[x]), j, (int)value);
    }
}

void read_model(init_t *res, char *path, int size)
{
    int fd = open(path, O_RDONLY);
    char *line = NULL;
    char **args;
    char **nb;

    for (int x = 0; x < size; x++) {
        line = get_next_line(fd);
        args = str_to_arr(line, '/');
        free(line);
        for (int i = 0; i < 3; i++) {
            nb = str_to_arr(args[i], ',');
            fill_struct(nb, res, i, x);
            free_array(nb);
        }
        free_array(args);
    }
    close(fd);
}

init_t *open_model(char *path)
{
    int lines = check_error(path);
    init_t *res = (lines <= 0) ? NULL : malloc(sizeof(init_t));

    if (lines <= 0)
        return (res);
    else if (res == NULL)
        return NULL;
    res->nb_cubes = lines;
    res->pos = malloc(sizeof(sfVector3f) * (lines + 1));
    res->scale = malloc(sizeof(sfVector3f) * (lines + 1));
    res->color = malloc(sizeof(sfColor) * (lines + 1));
    if (!res->color || !res->nb_cubes || !res->pos)
        return NULL;
    read_model(res, path, lines);
    return (res);
}
