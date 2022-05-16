/*
** EPITECH PROJECT, 2019
** ai
** File description:
** spawn
*/

#include "player.h"
#include "model.h"
#include "my_rpg.h"
#include "map.h"

void spawn_ai(game_t *game, sfVector3f pos, int lvl)
{
    char *source[6] = {"resources/models/boat1.legend",
    "resources/models/boat2.legend", "resources/models/boat3.legend"};
    model_t *new;

    if (lvl > 3)
        lvl = 3;
    else if (lvl <= 0)
        lvl = 1;
    new = add_model(game->models, source[lvl - 1], pos, lvl);
    if (new == NULL)
        return;
    new->is_ai = 1;
    new->stat->life_bar = create_life_bar();
}

int count_ai(game_t *ref)
{
    model_t *cur = get_model_head(ref->models);
    int count = 0;

    while (cur != NULL) {
        count += cur->is_ai;
        cur = cur->next;
    }
    return count;
}

void ai_spawner(game_t *game)
{
    sfVector2i index;
    int to_spawn = 0;
    float delay = 5;
    float radius = 1200;
    model_t *player = get_model_head(game->models);
    sfVector3f center = get_player(game->models)->center;
    sfVector3f spawn = {center.x + radius, center.y + radius, center.z};

    if (is_ready(game->spawn_clock, delay) == 0)
        return;
    to_spawn = rand()%((3 + 1) - 1) + 1;
    for (int i = 0; i < to_spawn; ++i) {
        rotate_point(&spawn, center, rand()%((360 + 1) - 1) + 1);
        index.x = (int)MAP_INDEX(spawn.x);
        index.y = (int)MAP_INDEX(spawn.y);
        if (index.x < 100 && index.x > 0 && index.y < 100 && index.y > 0 &&
        game->map->points3d[index.y][index.x].z < 0 && count_ai(game) < 3)
        spawn_ai(game, spawn, player->stat->lvl);
    }
}