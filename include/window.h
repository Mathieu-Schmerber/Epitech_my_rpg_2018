/*
** EPITECH PROJECT, 2019
** window
** File description:
** win
*/

#ifndef WIN_H_
#define WIN_H_

#include <SFML/Graphics.h>

#define WIN_X 1920
#define WIN_Y 1080
#define BPP 32

typedef struct win win_t;
typedef struct game game_t;
typedef struct my_rpg_s my_rpg_t;
typedef struct images_s images_t;

struct win {
    double prev_frame;
    double offset;
    images_t *dock_msg;
    images_t *chest_msg;
    sfEvent event;
    sfClock *global_clock;
    sfClock *button_clock;
    sfClock *duck_clock;
    sfVector2u *resolution;
    sfRenderWindow *window;
};

sfRenderWindow *new_window(int width, int height, int bpp, char *t);
win_t *create_window(char *title);
int display_window(game_t *game, my_rpg_t *rpg);
void manage_event(game_t *game);

#endif /* !WIN_H_ */
