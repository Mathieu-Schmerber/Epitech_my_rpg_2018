/*
** EPITECH PROJECT, 2019
** lib
** File description:
** str to int
*/

#include "lib.h"

int my_atoi(const char *str)
{
    int n = 0;
    int compt = 0;
    int sign = 1;

    if (*str == '-') {
        str++;
        sign = -1;
    }
    while (is_int(str[compt]) == 1)
        compt++;
    if (compt == my_strlen(str)) {
        for (int i = 0; i < compt; i++)
            n += ((str[compt - i - 1] - '0')) * (my_pow(10, i));
    }
    return (n * sign);
}

float my_atof(const char *str)
{
    float res = 0;
    int num;
    float sign = (*str == '-') ? -1 : 1;

    if (*str == '-')
        str++;
    for (int p = 0; *str; str++) {
        if (*str == '.' || *str == ',') {
            p++;
            str++;
        }
        num = *str - '0';
        if (num >= 0 && num <= 9 && p < 2) {
            sign = (p) ? sign / 10 : sign;
            res = res * 10 + (float) num;
        } else
            return (-1000);
    }
    return (res * sign);
}

int nb_digit(long int nb)
{
    int count = 0;

    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}

char *my_itoa(int nb)
{
    char *str;
    int temp = nb;
    int i;

    if (nb == 0)
        return ("0");
    for (i = 0; temp; i++)
        temp /= 10;
    str = malloc(sizeof(char) * (i + 1));
    for (int j = 1; nb; j++) {
        temp = nb % 10;
        str[i - j] = temp + '0';
        nb /= 10;
    }
    str[i] = '\0';
    return (str);
}

char *my_ftoa(float nb)
{
    char *res;
    int e = (int) nb;
    float d = nb - e;

    while (d - (int) d != 0)
        d *= 10;
    res = concat(my_itoa(e), ".", 1);
    res = concat(res, my_itoa((int) d), 3);
    return (res);
}

