/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main header
*/

#ifndef MUL_MY_DEFENDER_2018_MY_RPG_H
#define MUL_MY_DEFENDER_2018_MY_RPG_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define NBR_MENU 6
#define NBR_HOW 9
#define NBR_IMPROVE 16
#define NBR_OPTION 5
#define NBR_PAUSE 5
#define NBR_INVENTORY 5
#define NBR_MINI_MAP 4
#define NBR_DOCK_MENU 3
#define NBR_QUEST_MENU 4
#define NBR_ACCEPT_QUEST 3
#define NBR_MUSIC 4

typedef struct map map_t;
typedef struct win win_t;
typedef struct quest_s quest_t;
typedef struct game game_t;

typedef struct text_s {
    sfText *text;
} text_t;

typedef struct texts_s {
    sfFont *font;
    text_t **text;
} texts_t;

typedef struct music_s {
    sfMusic *sound;
} music_t;

typedef struct vector_s {
    sfVector2f set_position;
    sfVector2f scale;
} vector_t;

typedef struct images_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    vector_t *vector;
} images_t;

typedef struct images_config {
    sfVector2f pos;
    sfVector2f scale;
    int scene;
    char *address;
    struct images_config *next;
} images_config_t;

typedef struct my_rpg_s {
    images_t **menu;
    images_t **option;
    images_t **how;
    images_t **pause;
    images_t **inventory;
    images_t **minimap;
    images_t **quest_menu;
    images_t **accept_quest;
    images_t **dock_menu;
    images_t **improve;
    texts_t *imp_texts;
    texts_t *gold;
    int text_imp;
    int quest_index;
    int price[5];
    int stats_imp[5];
    music_t **music;
    quest_t **quest;
} my_rpg_t;

// sprite and music creation
images_config_t *parse_image(void);
my_rpg_t *create_rpg(void);
int create_sound(my_rpg_t *rpp);
void menu_creation(images_t **);
void how_creation(images_t **images);
void option_creation(images_t **images);
void pause_creation(images_t **images);
void inventory_creation(images_t **images);
void minimap_creation(images_t **images);
void dock_menu_creation(images_t **images);
void quest_menu_creation(images_t **images);
void improve_creation(images_t **images);
void accept_quest_creation(images_t **images);
images_t *create_msg(char *file);
images_t **create_inventory(void);
images_t **create_minimap(void);
images_t **create_dock_menu(void);
images_t **create_quest_menu(void);
images_t **create_improve(void);
images_t **create_accept_quest(void);

// set sprite scale
int set_images_scale_improve(images_t **images);
int set_images_scale_option(images_t **image);
int set_images_scale_menu(images_t **);
int set_images_scale_how(images_t **images);
int set_images_scale_pause(images_t **images);
int set_images_scale_inventory(images_t **image);
int set_images_scale_minimap(images_t **image);
int set_images_scale_dock_menu(images_t **image);
int set_images_scale_quest_menu(images_t **image);
int set_images_scale_accept_quest(images_t **image);

// set sprite position
void set_sprite_pos_improve(images_t **images);
void set_sprite_pos_menu(images_t **image);
void set_sprite_pos_how(images_t **image);
void set_sprite_pos_option(images_t **image);
void set_sprite_pos_pause(images_t **image);
void set_sprite_pos_inventory(images_t **image);
void set_sprite_pos_minimap(images_t **image);
void set_sprite_pos_dock_menu(images_t **image);
void set_sprite_pos_quest_menu(images_t **image);
void set_sprite_pos_accept_quest(images_t **image);

// font

texts_t *text_gold(void);
void reset_text_imp(my_rpg_t *rpg);
void print_text_improve(my_rpg_t *rpg, game_t *game);
texts_t *text_improve(my_rpg_t *rpg);

// open window
int open_window(map_t *map, my_rpg_t *rpg);

// menu
void draw_sprite(images_t **images, win_t *win, int nb_images, int print);
int menu(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);

// option
void change_resolution(my_rpg_t *rpg, images_t **images, win_t *win, int button);
void change_volume(my_rpg_t *rpg, float volume);

// draw scene
//void draw(images_t **images, win_t *win, int nb_images);
int draw_menu(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);
int draw_game(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);
int draw_how(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);
int draw_option(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);
int draw_pause(int scene, win_t *win, my_rpg_t *rpg, int *scene_before);
int quit_rpg(int __attribute__((unused))scene, win_t *win, my_rpg_t __attribute__((unused))*rpg, int *scene_before);

// init_price

void set_gold_nb(my_rpg_t *rpg, game_t *game);
my_rpg_t *init_val_stats(my_rpg_t *rpg);
my_rpg_t *init_price(my_rpg_t *rpg);

// ua
void inventory(win_t *win, my_rpg_t *rpg, sfVector2f position, float angle);
void dock_menu(my_rpg_t *rpg, win_t *win, game_t *game);

// hitbox classic

int clicked_button(images_t **images, win_t *win, int start, int end);

// hitbox button
void mouse_hover(images_t *image, int i);
int move_slider(my_rpg_t *rpg, images_t **image, win_t *win);
int button_onclick(images_t **image, win_t *win, sfEvent event, int *tmp);
void transparency(images_t **image, win_t *win, int const *tmp);

// free struct and destroy sprite
void destroy_images(images_t **images, int nb_images);
void destroy_sounds(music_t **music, int nb_sound);
void destroy_all(my_rpg_t *rpg);

// clock
int is_ready(sfClock *clock, float delay);

//
void down_map(map_t *map, float offset);

#endif //MUL_MY_DEFENDER_2018_MY_RPG_H
