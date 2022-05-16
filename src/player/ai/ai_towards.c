/*
** EPITECH PROJECT, 2019
** ai 
** File description:
** towards
*/

#include "model.h"
#include "player.h"
#include "map.h"

int get_side(model_t *ai)
{
    sfVector3f right = ai->center;
    sfVector3f left = ai->center;

    right.x += ai->dir.x * 2;
    right.y += ai->dir.y * 2;
    left.x += ai->dir.x * 2;
    left.y += ai->dir.y * 2;
    rotate_point(&right, ai->center, 90);
    rotate_point(&left, ai->center, -90);
    if (get_distance(ai->dest, left) < get_distance(ai->dest, right))
        return -1;
    return 1;
}

void smooth_rotation(game_t *game, model_t *ai) {
    float rot_angle = (float) game->win->offset * ai->stat->speed;
    sfVector3f pt = ai->center;
    float dist = get_distance(ai->center, ai->dest);

    normalize_vector(&ai->dir);
    pt.x += ai->dir.x * dist;
    pt.y += ai->dir.y * dist;
    if (get_distance(ai->dest, pt) <= 10)
        return;
    rotate_model(ai, rot_angle * get_side(ai));
}

void go_to_point(game_t *game, model_t *ai, sfVector3f point)
{
    float angle = get_angle(ai->center, point);
    sfVector3f *dir = &ai->dir;
    float dest_angle = angle - ai->rotation + 45;

    if ((ai->center.x - point.x) > 0)
        dest_angle = angle - ai->rotation - 135;
    ai->chase_angle = dest_angle;
    smooth_rotation(game, ai);
    if (check_collisions(game, ai) == 1) {
        normalize_vector(dir);
        dir->x *= (ai->stat->speed * game->win->offset);
        dir->y *= (ai->stat->speed * game->win->offset);
        move_model(ai, *dir);
    }
}

void chase_player(game_t *game, model_t *player, model_t *ai)
{
    float range = 200 + player->length / 2;
    float dist_player = get_distance(player->center, ai->center);

    if (dist_player > range && ai->dest_reached == 0) {
        ai->target_player = 1;
        ai->dest_reached = 0;
    } else if (dist_player <= range) {
        if (ai->dest_reached) {
            ai->dest_reached = 0;
            ai->dest = ai->center;
            rotate_point(&ai->dest, player->center, 45);
        }
    }
    if (ai->target_player == 1)
        ai->dest = player->center;
    go_to_point(game, ai, ai->dest);
    if (get_distance(ai->center, ai->dest) < 5 ||
        (dist_player <= range && ai->target_player == 1)) {
        ai->dest_reached = 1;
        ai->target_player = 0;
    }
}