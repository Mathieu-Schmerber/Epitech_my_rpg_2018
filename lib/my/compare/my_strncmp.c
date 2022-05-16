/*
** EPITECH PROJECT, 2018
** lib
** File description:
** compares n first character of two strings
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    for (i = 0; s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
