/*
** EPITECH PROJECT, 2021
** special_case_functions
** File description:
** Functions for length modifier "%h..."
*/

#include "../../my_printf.h"

unsigned short modifier_my_put_nbr(unsigned short nb)
{
    int i = 1;

    if (nb > 32767) {
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

unsigned short modifier_unsigned_function(unsigned short nb)
{
    unsigned short i = 1;

    for (; (nb / i) >= 10;) {
        i *= 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return (0);
}

unsigned short modifier_convert_in_octal(unsigned short nb)
{
    unsigned short i = 1;

    for (; (nb / i) >= 8;) {
        i *= 8;
    }
    while (i > 0) {
        my_putchar((nb / i) % 8 + '0');
        i /= 8;
    }
    return (0);
}

unsigned short modifier_unsigned_function_smallhex(unsigned short nb)
{
    unsigned short i = 1;
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

unsigned short modifier_unsigned_function_caphex(unsigned short nb)
{
    unsigned short i = 1;
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
