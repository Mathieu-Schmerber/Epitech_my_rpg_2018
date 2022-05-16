/*
** EPITECH PROJECT, 2019
** shoot
** File description:
** model
*/

#include "model.h"
#include "player.h"
#include "particles.h"
#include "my_rpg.h"

void calcul_bullet_dir(model_t * current, float offset)
{
    normalize_vector(&current->dir);
    current->stat->travel_range += offset * 1.5;
    current->dir.x *= (current->stat->bullet_speed * offset);
    current->dir.y *= (current->stat->bullet_speed * offset);
}

void check_bullet_lvl(model_t *model, game_t *game, map_t *map)
{
    sfColor terrain = sfColor_fromRGB(150, 100, 70);

    if (model->center.z <= 0)
        spawn_particle((sfVector3f){0, 0, 1}, sfBlue, model->center, game);
    else if (map_collision(map, model) == 0)
        spawn_particle((sfVector3f){0, 0, 1}, terrain, model->center, game);
}

void move_bullets(map_t *map, model_t *head, double offset, game_t *game)
{
    model_t *current = head;
    float x = 0;

    while (current != NULL) {
        if (current->is_bullet == 0) {
            current = current->next;
            continue;
        }
        x = current->stat->travel_range;
        calcul_bullet_dir(current, offset);
        if (current->center.z >= 0 && check_hit(map, current, game) == 1)
            current->dir.z = -0.01 * powf((x - 5), 2) + 1;
        else {
            check_bullet_lvl(current, game, map);
            current = destroy(current);
            continue;
        }
        move_model(current, current->dir);
        current = current->next;
    }
}

void instantiate_bullets(model_t *m, int nb, sfVector3f back, sfVector3f dir)
{
    char *file = "resources/models/bullet.legend";
    sfVector3f pos = back;
    model_t *instance;
    float interval = m->length / (nb + 1);

    for (int i = 0; i < nb; ++i) {
        pos.x += m->dir.x * interval;
        pos.y += m->dir.y * interval;
        pos.z = 10 * m->is_tower;
        instance = add_model(m, file, pos, m->stat->lvl);
        if (instance == NULL)
            return;
        instance->stat->bullet_speed = m->stat->bullet_speed;
        instance->is_bullet = 1;
        instance->dir = dir;
        instance->sender = m;
    }
}

void shoot(model_t *model, float shoot_angle, int nb_bullets, game_t *game)
{
    sfVector3f dir = model->dir;
    sfVector3f back = model->center;

    rotate_point(&dir, (sfVector3f) {0, 0, 0}, shoot_angle);
    normalize_vector(&dir);
    normalize_vector(&model->dir);
    back.x += model->dir.x * (model->length / 2) * -1;
    back.y += model->dir.y * (model->length / 2) * -1;
    back.x += dir.x * (model->width / 2) * -1;
    back.y += dir.y * (model->width / 2) * -1;
    instantiate_bullets(model, nb_bullets, back, dir);
    sfMusic_play(game->music[1]->sound);
}