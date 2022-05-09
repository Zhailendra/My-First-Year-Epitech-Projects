/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_putstr
*/

#include "my.h"

char my_putstr(char const *str)
{
    while (*str != 0) {
        my_putchar(*str);
        str++;
    }
    return (0);
}
