/*
** EPITECH PROJECT, 2019
** lib
** File description:
** free char array
*/

#include "lib.h"

void free_array(char **array)
{
    if (array) {
        for (int i = 0; array[i]; i++)
            free(array[i]);
        free(array);
    }
}
