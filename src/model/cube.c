/*
** EPITECH PROJECT, 2019
** cube
** File description:
** cube
*/

#include "model.h"

void get_3d_cube(sfVector3f *pts, sfVector3f pos, sfVector3f scale, int zoom)
{
    pts[0] = (sfVector3f){0, 0, 0};
    pts[1] = (sfVector3f){zoom, 0, 0};
    pts[2] = (sfVector3f){zoom, zoom, 0};
    pts[3] = (sfVector3f){0, zoom, 0};
    pts[4] = (sfVector3f){0, 0, zoom};
    pts[5] = (sfVector3f){zoom, 0, zoom};
    pts[6] = (sfVector3f){zoom, zoom, zoom};
    pts[7] = (sfVector3f){0, zoom, zoom};
    for (int i = 0; i < 8; ++i) {
        pts[i].x *= scale.x;
        pts[i].y *= scale.y;
        pts[i].z *= scale.z;
        pts[i].x += pos.x * zoom;
        pts[i].y += pos.y * zoom;
        pts[i].z += pos.z * zoom;
    }
}

void create_face(sfConvexShape *cs, int index, sfVector2f *pts, sfColor c[2])
{
    int faces[24] = {0, 1, 2, 3, 4, 5, 1, 0, 4, 0, 3, 7, 5, 1, 2,
    6, 7, 6, 2, 3, 4, 5, 6, 7};

    sfConvexShape_setPointCount(cs, 4);
    sfConvexShape_setPoint(cs, 0, pts[faces[4 * index]]);
    sfConvexShape_setPoint(cs, 1, pts[faces[4 * index + 1]]);
    sfConvexShape_setPoint(cs, 2, pts[faces[4 * index + 2]]);
    sfConvexShape_setPoint(cs, 3, pts[faces[4 * index + 3]]);
    sfConvexShape_setFillColor(cs, c[0]);
    if (index == 0 || index == 5)
        sfConvexShape_setFillColor(cs, c[1]);
}

void render_cube(sfRenderWindow *win, cube_t *cube)
{
    sfColor colors[2];
    sfColor side = cube->color;

    side.r = (cube->color.r <= 30 ? 0 : cube->color.r - 30);
    side.g = (cube->color.g <= 30 ? 0 : cube->color.g - 30);
    side.b = (cube->color.b <= 30 ? 0 : cube->color.b - 30);
    colors[0] = side;
    colors[1] = cube->color;
    for (int i = 0; i < 6; ++i) {
        create_face(cube->faces[i], i, cube->points_2d, colors);
        sfRenderWindow_drawConvexShape(win, cube->faces[i], NULL);
    }
}

cube_t *create_cube(sfVector3f pos, sfVector3f scale, sfColor c)
{
    cube_t *new = malloc(sizeof(cube_t));

    if (new == NULL)
        return NULL;
    new->pos = pos;
    new->color = c;
    new->points_3d = malloc(sizeof(sfVector3f) * 8);
    new->points_2d = malloc(sizeof(sfVector2f) * 8);
    if (new->points_3d == NULL || new->points_2d == NULL)
        return NULL;
    get_3d_cube(new->points_3d, pos, scale, MODEL_ZOOM);
    new->faces = malloc(sizeof(sfConvexShape *) * 6);
    if (new->faces == NULL)
        return NULL;
    for (int j = 0; j < 8; ++j)
        new->points_2d[j] = (sfVector2f){0, 0};
    for (int i = 0; i < 6; ++i)
        new->faces[i] = sfConvexShape_create();
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add_cube(model_t *model, sfVector3f pos, sfVector3f scale, sfColor c)
{
    cube_t *current = model->head;

    if (current == NULL) {
        model->head = create_cube(pos, scale, c);
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = create_cube(pos, scale, c);
    current->next->prev = current;
}