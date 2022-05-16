/*
** EPITECH PROJECT, 2019
** player
** File description:
** rpg
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.h>

typedef struct model model_t;
typedef struct map map_t;
typedef struct game game_t;
typedef struct path path_t;

#define TOWER_RNG 500

typedef struct caract {
    int lvl;
    int health;
    int gold;
    int bullet_damage;
    float bullet_speed;
    int in_menu;
    int shoot_nb;
    float speed;
    float shoot_cooldown;
    float travel_range;
    sfRectangleShape *life_bar;
    sfClock *right_shoot;
    sfClock *left_shoot;
} carac_t;

// A*
typedef struct node {
    struct node *prev;
    int pos[2];
    int g;
    float h;
    float f;
    struct node *p;
    struct node *next;
} node_t;

model_t *get_player(model_t *model);
int check_collisions(game_t *game, model_t *players);
int model_collision(model_t *model);
int collide(model_t *model, sfVector3f pts[2], sfVector3f mid);
int map_collision(map_t *map, model_t *model);
void hit_boat(model_t *boat, model_t *bullet, game_t *game);
int check_hit(map_t *map, model_t *model, game_t *game);
void call_dock_init(game_t *game, model_t *player);
int get_dock_trigger(game_t *game);
void manage_all_ai(game_t *game);
void chase_player(game_t *game, model_t *player, model_t *ai);
void go_to_point(game_t *game, model_t *ai, sfVector3f point);
void ai_spawner(game_t *game);
void pickup_chest(game_t *game);
void spawn_random_chests(game_t *game, int nb);
void tower_trigger(game_t *game);
void spawn_tower(game_t *game, sfVector3f pos, char *source);
void level_up(model_t *model);
void get_quest_state(game_t *game);

// A* algorithm

sfVector3f *astar(float *, int []);
void astar_alg(node_t **, node_t **, float *, int []);
node_t *create_node(int, int, node_t *, int []);
node_t *cut_node(node_t **, int);
node_t *find_least_f(node_t **);
path_t *init_path(void);

#endif