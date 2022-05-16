/*
** EPITECH PROJECT, 2019
** ai
** File description:
** rpg
*/

#include "map.h"
#include "model.h"
#include "player.h"
#include "my_rpg.h"
#include "map.h"

void try_shoot(model_t *ai, model_t *player, game_t *game)
{
    sfVector3f right = ai->center;
    sfVector3f left = ai->center;
    float dist = 250 + player->length / 2;

    normalize_vector(&ai->dir);
    if (get_distance(ai->center, player->center) < dist)
        dist = get_distance(ai->center, player->center);
    right.x += ai->dir.x * dist;
    right.y += ai->dir.y * dist;
    left.x += ai->dir.x * dist;
    left.y += ai->dir.y * dist;
    rotate_point(&right, ai->center, 90);
    rotate_point(&left, ai->center, -90);
    if (get_distance(left, player->center) < player->width * 2) {
        if (is_ready(ai->stat->left_shoot, ai->stat->shoot_cooldown))
            shoot(ai, -90, ai->stat->shoot_nb, game);
    } else if (get_distance(right, player->center) < player->width * 2) {
        if (is_ready(ai->stat->right_shoot, ai->stat->shoot_cooldown))
            shoot(ai, 90, ai->stat->shoot_nb, game);
    }
}

void manage_all_ai(game_t *game)
{
    model_t *cur = get_model_head(game->models);
    model_t *player = get_player(cur);

    ai_spawner(game);
    tower_trigger(game);
    while (cur != NULL) {
        if (cur->is_ai == 1) {
            try_shoot(cur, player, game);
            chase_player(game, player, cur);
        }
        cur = cur->next;
    }
}