/*
** EPITECH PROJECT, 2018
** lib_one
** File description:
** lib
*/

#include <unistd.h>

int my_strlen(char const *s)
{
    int i = 0;

    if (s == NULL)
        return 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void my_putstr(char *str, int output)
{
    write(output, str, my_strlen(str));
}
