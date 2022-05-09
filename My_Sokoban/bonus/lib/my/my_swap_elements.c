/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_swap_elements
*/

#include "my.h"

char **my_swap_elements(char **my_tab, int i, int j)
{
    char *value = my_strdup(my_tab[i]);
    my_tab[i] = my_strdup(my_tab[j]);
    my_tab[j] = my_strdup(value);
    free(value);
    return (my_tab);
}
