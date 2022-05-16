/*
** EPITECH PROJECT, 2019
** world
** File description:
** open map file check for errors and gen map
*/

#include <unistd.h>
#include "map.h"
#include "lib.h"

map_t *find_args(char *line)
{
    float a[3] = {0, 0, 0};
    char *temp = NULL;

    for (int i = 0; i < 3; i++) {
        temp = my_strdupline(line, i, ';');
        if (temp && !i) {
            a[i] = my_atof(temp);
            a[i] = (a[i] > 15 && a[i] < 201) ? a[i] : 0;
            free(temp);
        } else if (temp) {
            a[i] = my_atof(temp);
            a[0] = (a[i] >= 0 && a[i] < 26) ? a[0] : 0;
            free(temp);
        } else
            a[0] = 0;
    }
    free(line);
    if (a[0] && a[0] == 100)
        return (create_map(a[0], MAP_ZOOM));
    return (NULL);
}

int fill_map_heights(map_t *map, char *line, int s, int i)
{
    char *temp = NULL;
    float f = 0;
    int factor = 20;

    for (int j = 0; j < s; j++) {
        temp = my_strdupline(line, j, ' ');
        if (temp) {
            f = my_atof(temp);
            map->map_heights[i * s + j] = f / factor;
        } else
            f = -1;
        free(temp);
        if (f < 0 || f > 200)
            return (-1);
    }
    return (0);
}

char *fill_map(map_t *map, int fd)
{
    char *line;

    for (int i = 0; i < map->size; i++) {
        line = get_next_line(fd);
        if (fill_map_heights(map, line, map->size, i) == -1) {
            free_map(map);
            free(line);
            return NULL;
        }
        free(line);
    }
    return "ok";
}

map_t *open_map(char *path)
{
    int fd = open(path, O_RDONLY);
    map_t *map;
    char *line;

    if (fd < 0)
        return NULL;
    line = get_next_line(fd);
    map = find_args(line);
    if (!map) {
        close(fd);
        return (map);
    } else if (fill_map(map, fd) == NULL) {
        close(fd);
        return NULL;
    }
    close (fd);
    return (map);
}
