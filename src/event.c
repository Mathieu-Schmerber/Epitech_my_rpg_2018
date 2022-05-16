/*
** EPITECH PROJECT, 2018
** event
** File description:
** runner
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <player.h>
#include "map.h"
#include "model.h"
#include "particles.h"
#include "my_rpg.h"

int is_ready(sfClock *clock, float delay)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (time.microseconds / 1000000.0 >= delay) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

double get_frame_time(sfClock *clock, double *prev_frame)
{
    sfTime time = sfClock_getElapsedTime(clock);
    double offset = fabs(time.microseconds - *prev_frame) / 50000.0;

    *prev_frame = time.microseconds;
    return offset;
}

void move_player(game_t *game, double offset)
{
    model_t *p = get_player(game->models);
    sfVector3f *dir = &p->dir;

    if (sfKeyboard_isKeyPressed(sfKeyD))
        rotate_model(p, (float)offset * p->stat->speed);
    else if (sfKeyboard_isKeyPressed(sfKeyQ))
        rotate_model(p, (float)offset * -p->stat->speed);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && check_collisions(game, p) == 1) {
        normalize_vector(dir);
        dir->x *= (p->stat->speed * offset);
        dir->y *= (p->stat->speed * offset);
        move_map2d(game->map, p->dir, p);
        move_model(p, p->dir);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
    is_ready(p->stat->right_shoot, p->stat->shoot_cooldown) == 1) {
        shoot(p, 90, p->stat->shoot_nb, game);
    } else if (sfKeyboard_isKeyPressed(sfKeyA) &&
    is_ready(p->stat->left_shoot, p->stat->shoot_cooldown) == 1)
        shoot(p, -90, p->stat->shoot_nb, game);
}

void manage_event(game_t *game)
{
    win_t *win = game->win;
    model_t *models = game->models;
    map_t *map = game->map;
    double offset = get_frame_time(win->global_clock, &win->prev_frame);

    win->offset = offset;
    if (get_player(models)->stat->in_menu == 0 &&
    get_player(models)->stat->health > 0) {
        move_player(game, offset);
        manage_all_ai(game);
        move_bullets(map, get_model_head(models), offset, game);
        game->particles = clean_particle_list(game->particles);
    }
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(win->window);
    }
}