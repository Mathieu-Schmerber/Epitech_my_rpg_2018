/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** parsing config file for images
*/

#include <fcntl.h>
#include <stdio.h>
#include "lib.h"
#include "quest.h"
#include "my_rpg.h"

images_config_t *parse_info(char *str, images_config_t *config)
{
    images_config_t *tmp = config;
    char **array = str_to_arr(str, ' ');
    int size = my_size_array(array);

    if (array[5][my_strlen(array[5]) - 1] == '\n')
        array[5][my_strlen(array[5]) - 1] = '\0';
    if (size < 6)
        return NULL;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(images_config_t));
    if (!tmp->next)
        return NULL;
    tmp->next->next = NULL;
    tmp->scene = my_atoi(array[0]);
    tmp->address = my_strdup(array[1]);
    tmp->pos.x = my_atof(array[2]);
    tmp->pos.y = my_atof(array[3]);
    tmp->scale.x = my_atof(array[4]);
    tmp->pos.y = my_atof(array[5]);
    return config;
}

images_config_t *parse_image(void)
{
    images_config_t *config = malloc(sizeof(images_config_t));
    FILE *fd = fopen("src/create_rpg/config_img.txt", "r");
    int ret;
    char *buffer = NULL;
    size_t size = 0;

    if (!config || !fd)
        return NULL;
    config->next = NULL;
    do {
        ret = getline(&buffer, &size, fd);
        if (buffer == NULL)
            return (NULL);
        config = parse_info(buffer, config);
    } while (ret > 0);
    return config;
}