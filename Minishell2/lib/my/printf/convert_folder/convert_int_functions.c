/*
** EPITECH PROJECT, 2021
** convert int functions
** File description:
** Functions that convert my integer in a specific base
*/

#include "../../my_printf.h"
#include <stdio.h>

unsigned int convert_in_octal(unsigned int nb)
{
    unsigned int i = 1;

    for (; (nb / i) >= 8;) {
        i *= 8;
    }
    while (i > 0) {
        my_putchar((nb / i) % 8 + '0');
        i /= 8;
    }
    return (0);
}

unsigned int convert_in_unsigned_bin(unsigned int nb)
{
    unsigned int i = 1;

    for (; (nb / i) >= 2;) {
        i *= 2;
    }
    while (i > 0) {
        my_putchar((nb / i) % 2 + '0');
        i /= 2;
    }
    return (0);
}

unsigned int unsigned_function(unsigned int nb)
{
    unsigned int i = 1;

    for (; (nb / i) >= 10;) {
        i *= 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return (0);
}

unsigned int unsigned_function_smallhex(unsigned int nb)
{
    unsigned int i = 1;
    char *base = "0123456789abcdef";

    for (; (nb / i) >= 16;) {
        i *= 16;
    }
    while (i > 0) {
        my_putchar(base[(nb / i) % 16]);
        i /= 16;
    }
    return (0);
}

unsigned int unsigned_function_caphex(unsigned int nb)
{
    unsigned int i = 1;
    char *base = "0123456789ABCDEF";

    for (; (nb / i) >= 16;) {
        i *= 16;
    }
    while (i > 0) {
        my_putchar(base[(nb / i) % 16]);
        i /= 16;
    }
    return (0);
}
