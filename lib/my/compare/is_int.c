/*
** EPITECH PROJECT, 2019
** lib
** File description:
** check if char is int
*/

int is_int(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_min(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int is_maj(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int is_alphanum(const char *s)
{
    char c;

    for (int i = 0; s[i]; i++) {
        c = s[i];
        if (!is_int(c) && !is_min(c) && !is_maj(c))
            return (0);
    }
    return (1);
}

