/*
** EPITECH PROJECT, 2018
** lib
** File description:
** count nb line of array
*/

int my_size_array(char **array)
{
    int i = 0;

    while (array[i])
        i++;
    return (i);
}