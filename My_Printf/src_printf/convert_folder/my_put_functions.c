/*
** EPITECH PROJECT, 2021
** my_put_functions
** File description:
** Functions to display integers, char, or string
*/

#include <stdio.h>
#include <unistd.h>
#include "../../include/tool.h"

char my_putchar(char c)
{
    return (write(1, &c, 1));
}

int my_put_nbr(int nb)
{
    int i = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (; (nb / i) >= 10;) {
        i *= 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return (0);
}

int my_putstr(char const *str)
{
    while (*str != 0) {
        my_putchar(*str);
        str++;
    }
    return (0);
}

int my_isdigit(char c)
{
    if ((c > 47) && (c < 58))
        return (1);
    else
        return (0);
}

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
