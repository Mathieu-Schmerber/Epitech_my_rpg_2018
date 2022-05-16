/*
** EPITECH PROJECT, 2019
** lib
** File description:
** lib
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_H
#define MY_H

void free_array(char **);
char **char_arr_dup(char **);
char **str_to_arr(const char *, char);
char *clean_str(char *);
char **arr_add(char **, char *, int);
char **arr_rem(char **, int);
int find_arr_line(char **, const char *);
int my_strlen(const char *);
int is_int(char);
int is_alphanum(const char *);
int my_pow(int, int);
char *my_int_to_str(int nb);
int my_atoi(const char *);
float my_atof(const char *);
char *my_itoa(int);
float my_atof(const char *);
char *my_ftoa(float);
char *get_next_line(int);
int my_strcmp(const char *, const char *);
int my_strncmp(const char *, const char *, int);
char *concat(char *, char *, int);
char *my_strcat(char *, char *);
char *my_strcpy(const char *, char *);
char *my_strdup(const char *);
char *my_strdup_xy(const char *, int, int);
char *my_strdupline(char *, int, char);
char *my_revstr(char *);
char *my_strdupline(char *, int, char);
int my_size_array(char **array);
int my_str_isnum(char const *str);
void my_putstr(char const *str, int output);

#endif