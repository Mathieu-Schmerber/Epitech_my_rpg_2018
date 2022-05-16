/*
** EPITECH PROJECT, 2019
** hit
** File description:
** boat
*/

#include "model.h"
#include "player.h"
#include "particles.h"

void hit_boat(model_t *boat, model_t *bullet, game_t *game)
{
    sfVector3f inverse_dir = bullet->dir;
    if (boat->is_dock == 1)
        return;
    boat->stat->health -= bullet->stat->bullet_damage;
    normalize_vector(&inverse_dir);
    inverse_dir.x *= -1;
    inverse_dir.y *= -1;
    inverse_dir.z *= -1;
    spawn_particle(inverse_dir, sfRed, boat->center, game);
    if (boat->stat->health <= 0) {
        if (boat->is_ai == 1)
            get_player(game->models)->stat->gold += 100;
        if (boat->is_player == 1)
            return;
        game->boat_killed += game->no_kill;
        destroy(boat);
    }
}

int check_hit(map_t *map, model_t *model, game_t *game)
{
    model_t *current = get_model_head(model);
    sfVector3f pred[2];

    for (int i = 0; i < 2; ++i) {
        pred[i] = model->center;
        pred[i].x += model->dir.x * 2;
        pred[i].y += model->dir.y * 2;
    }
    while (current != NULL) {
        if (current->is_bullet == 1) {
            current = current->next;
            continue;
        } else if (collide(current, pred, current->center) == 1 &&
            current != model->sender) {
            hit_boat(current, model, game);
            return 0;
        }
        current = current->next;
    }
    return map_collision(map, model);
}