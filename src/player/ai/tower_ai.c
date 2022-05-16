/*
** EPITECH PROJECT, 2019
** tower
** File description:
** rpg
*/

#include "player.h"
#include "model.h"
#include "my_rpg.h"

void spawn_tower(game_t *game, sfVector3f pos, char *source)
{
    model_t *res = add_model(game->models, source, pos, 3);

    if (res == NULL)
        return;
    res->stat->bullet_speed = 25;
    res->stat->shoot_cooldown = 3;
    res->is_tower = 1;
    res->stat->health = 60;
}

model_t *get_tower(model_t *ref)
{
    model_t *tower = get_model_head(ref);

    while (tower != NULL) {
        if (tower->is_tower)
            break;
        tower = tower->next;
    }
    return tower;
}

void tower_trigger(game_t *game)
{
    model_t *p = get_player(game->models);
    float range = TOWER_RNG;
    float angle = 0;
    model_t *tower = get_tower(game->models);

    if (tower == NULL)
        return;
    tower->stat->bullet_damage = 1;
    if (p->stat->lvl != 3)
        tower->stat->bullet_damage = 1000000;
    angle = angle - tower->rotation + 45;
    if ((tower->center.x - p->center.x) > 0)
        angle = get_angle(tower->center, p->center) - tower->rotation - 135;
    if (get_distance(p->center, tower->center) < range &&
    is_ready(tower->stat->right_shoot, tower->stat->shoot_cooldown))
        shoot(tower, angle, 2, game);
}