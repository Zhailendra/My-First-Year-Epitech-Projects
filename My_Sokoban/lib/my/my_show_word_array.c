/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_show_word_array
*/

#include "my.h"

void my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
    }
}
