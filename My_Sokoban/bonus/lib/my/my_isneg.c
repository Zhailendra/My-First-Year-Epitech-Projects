/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if ( n > 0)
        write(1, "P", 1);
    else if ( n < 0 )
        write(1, "N", 1);
    else
        write(1, "P", 1);
    my_putchar('\n');
    return (0);
}
