/*
** EPITECH PROJECT, 2019
** disp
** File description:
** world
*/

#include "model.h"
#include "map.h"

void render_model(sfRenderWindow *win, model_t *model) {
    cube_t *current = model->head;
    model_t *head = get_model_head(model);
    sfVector2u s = sfRenderWindow_getSize(win);
    sfVector2f off = get_cam_offset(head);

    s = (sfVector2u) {s.x / 2 - off.x, s.y / 2 - off.y};
    while (current != NULL) {
        convert_2d_cube(current->points_2d, current->points_3d, s.x, s.y);
        render_cube(win, current);
        current = current->next;
    }
}

void render_chests(sfRenderWindow *win, game_t *game)
{
    model_t *current = get_model_head(game->models);

    while (current != NULL) {
        if (current->is_chest == 1)
            render_model(win, current);
        current = current->next;
    }
}

model_t *try_render(model_t *current, float y, sfRenderWindow *win)
{
    sfVector3f ref;

    if (current == NULL)
        return NULL;
    for (int i = 0; i < 4; ++i) {
        ref = get_model_corners(current, i);
        if (ref.y < y - MAP_ZOOM) {
            render_model(win, current);
            return current->next;
        }
    }
    return current;
}