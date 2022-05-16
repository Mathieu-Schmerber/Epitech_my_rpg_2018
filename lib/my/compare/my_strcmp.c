/*
** EPITECH PROJECT, 2018
** lib
** File description:
** compares two strings
*/

int my_strcmp(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
