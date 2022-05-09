/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_int_len
*/

#include "my.h"

int my_int_len(int nb)
{
    int count = 1;

    if (nb < 0)
        my_putchar('-');
    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    return (count);
}
