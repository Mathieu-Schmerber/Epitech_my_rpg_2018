/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** display the nb send to this fct
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

void to_the_right(char *nb)
{
    int i = 0;
    int len = my_strlen(nb);

    while (i < len) {
        nb[i + 1] = nb[i];
        i++;
    }
    nb[i + 1] = '\0';
}

char *my_put_nbr(int nb)
{
    char *nb_str = malloc(sizeof(char) * 12);

    nb_str[0] = '\0';
    if (nb == -2147483648) {
        my_put_nbr(-2);
        my_put_nbr(147483648);
        return (0);
    }
    if (nb < 0) {
        to_the_right(nb_str);
        nb_str[0] = '-';
        nb = nb * -1;
    }
    if (nb >= 10) {
        nb_str = my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else if (nb < 10) {
        to_the_right(nb_str);
        nb_str[0] = nb + 48;
    }
    return nb_str;
}

void one_more_space(char **str)
{
    for (int i = my_strlen(*str); i >= 0; i--) {
        (*str)[i + 1] = (*str)[i];
    }
}

void my_nb_to_array(unsigned int nb, char **array)
{
    (*array)[0] = '\0';
    if (nb == 0) {
        one_more_space(array);
        (*array)[0] = '0';
    }
    while (nb > 0) {
        one_more_space(array);
        (*array)[0] = nb % 10 + '0';
        nb = (nb - nb % 10) / 10;
    }
}
