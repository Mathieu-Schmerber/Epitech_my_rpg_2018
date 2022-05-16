/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** parsing config file for quest
*/

#include <fcntl.h>
#include <stdio.h>
#include "lib.h"
#include "quest.h"

char *my_realloc_str(char *str, char *buffer)
{
    char *res;

    res = malloc(sizeof(char) * (my_strlen(str) + my_strlen(buffer) + 1));
    res = my_strcpy(res, str);
    free(str);
    return (res);
}

static quest_t *fill_struct(char **tmp)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int j = 0;

    quest->gold = my_strdup(tmp[0]);
    quest->nb_speech = my_atoi(tmp[1]);
    quest->speech = malloc(sizeof(char *) * (quest->nb_speech + 1));
    if (!quest->gold || !quest->speech) {
        free_array(tmp);
        return (NULL);
    }
    for (int i = 2; tmp[i]; i++, j++) {
        quest->speech[j] = my_strdup(tmp[i]);
    }
    quest->speech[j] = NULL;
    if (j != quest->nb_speech)
        return (NULL);
    free_array(tmp);
    return (quest);
}

quest_t **error(char *str, char **array)
{
    free(str);
    free_array(array);
    return (NULL);
}

quest_t **parse_config(char *str)
{
    char **array = str_to_arr(str, '\n');
    quest_t **quest;
    char **tmp;
    int i = 0;

    if (!array || my_size_array(array) < 1)
        return (NULL);
    quest = malloc(sizeof(quest_t *) * (my_size_array(array) + 1));
    if (!quest)
        return (NULL);
    for (; array[i]; i++) {
        tmp = str_to_arr(array[i], '/');
        if (my_size_array(tmp) < 3 || my_str_isnum(tmp[0]) != 1
        || my_str_isnum(tmp[1]) != 1)
            return (error(str, array));
        quest[i] = fill_struct(tmp);
        if (!quest[i])
            return (error(str, array));
    }
    quest[i] = NULL;
    free(str);
    free_array(array);
    return (quest);
}

quest_t **create_quest(void)
{
    quest_t **quest = NULL;
    FILE *fd = fopen("src/player/parse/.quest_config", "r");
    int ret;
    char *buffer = NULL;
    char *str = my_strdup("");
    size_t size = 0;
    int i = 0;

    if (!fd)
        return (NULL);
    do {
        ret = getline(&buffer, &size, fd);
        if (buffer == NULL)
            return (NULL);
        else if (ret < 0) {
            quest = parse_config(str);
            fclose(fd);
            return (quest);
        }
        i++;
        str = my_strcat(my_realloc_str(str, buffer), buffer);
    } while (ret > 0);
    fclose(fd);
    return (quest);
}