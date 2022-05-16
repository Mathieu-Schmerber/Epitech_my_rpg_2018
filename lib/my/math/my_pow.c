/*
** EPITECH PROJECT, 2018
** CPool
** File description:
** my_compute_power_rec
*/

int my_pow(int nb, int p)
{
    int res = 0;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    res = nb * my_pow(nb, p - 1);
    if (res < 0)
        return (0);
    return (res);
}
