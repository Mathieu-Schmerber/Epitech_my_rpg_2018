/*
** EPITECH PROJECT, 2019
** world
** File description:
** main
*/

#include "my_rpg.h"
#include "map.h"
#include "quest.h"
#include "lib.h"

int main(int __attribute__((unused))ac, char __attribute__((unused))**av,
char **env)
{
    my_rpg_t *rpg = create_rpg();
    map_t *map = open_map("resources/map.legend");

    if (!env || !rpg || map == NULL) {
        if (!map && rpg)
            destroy_all(rpg);
        return 84;
    }
    map->water = create_map(map->size, map->zoom);
    map->water->water_clock = sfClock_create();
    return (open_window(map, rpg));
}