/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_putchar
*/

#include "my.h"

char my_putchar(char c)
{
    return (write(1, &c, 1));
}
