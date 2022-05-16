/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** lib
*/

char *my_revstr(char *str)
{
    int i = 0;
    char temp;
    int size;

    while (str[i] != '\0') {
        i++;
    }
    size = i;
    i = 0;
    while (i < size / 2) {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
        i++;
    }
    str[size] = '\0';
    return str;
}