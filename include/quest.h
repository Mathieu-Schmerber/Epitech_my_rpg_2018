/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** quest struct
*/

#ifndef MUL_MY_DEFENDER_2018_QUEST_H
#define MUL_MY_DEFENDER_2018_QUEST_H

typedef struct quest_s {
    char *gold;
    int nb_speech;
    char **speech;
} quest_t;

quest_t **create_quest(void);

#endif //MUL_MY_DEFENDER_2018_QUEST_H
