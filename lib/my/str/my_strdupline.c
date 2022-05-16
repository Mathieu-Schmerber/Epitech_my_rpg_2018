/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** task01
*/

#include <stdlib.h>

int count_char_line(char const *map, int line, int *begin, char separator)
{
    int count_line = 0;
    int count = 0;
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == separator)
            count_line++;
        if (count_line == line) {
            count++;
        } else if (count_line > line)
            return count;
        if (count == 1)
            (*begin) = i;
        i++;
    }
    return count;
}

char *my_strdupline(char *str, int line, char separator)
{
    int index = 0;
    int begin = 0;
    int nb = 0;
    int nb_char = count_char_line(str, line, &begin, separator);
    char *dup;

    if (nb_char > 0)
        dup  = malloc(sizeof(char) * (nb_char + 1));
    else
        return NULL;
    if (line > 0)
        nb = 1;
    for (int j = begin + nb; j < nb_char + begin; ++j) {
        dup[index] = str[j];
        index++;
    }
    dup[index] = '\0';
    return dup;
}
