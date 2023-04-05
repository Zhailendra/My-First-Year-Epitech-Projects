/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MY_H_
    #define MY_H_

char my_putchar(char c);

char my_putstr(char const *str);

int my_put_nbr(int nb);

int my_isdigit(char c);

int my_strlen(char const *str);

int my_int_len(int nb);

char **my_swap_elements(char **my_tab, int i, int j);

char *my_strcat(char const *dest, char const *src);

int my_strcomp(char *string1, char *string2);

int my_strncomp(char *string1, char *string2, int occu);

char *my_strdup(char const *src);

char *my_strndup(char const *src, int detail);

char **my_str_to_word_array(char *string, char *delim);

void my_show_word_array(char * const *tab);

int my_str_isalpha(char c);

int my_atoi(char *string);

int my_isneg(int n);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int detail);

void my_swap(int *a, int *b);

char *my_get_next_line(int fp);

#endif
