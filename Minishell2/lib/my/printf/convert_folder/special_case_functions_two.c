/*
** EPITECH PROJECT, 2021
** special_case_functions2
** File description:
** Functions for length modifier "%l..."
*/

#include "../../my_printf.h"

unsigned long modifier_my_put_nbr3(unsigned long nb)
{
    unsigned long i = 1;

    if (nb > 9223372036854775807) {
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

unsigned long modifier_unsigned_function3(unsigned long nb)
{
    unsigned long i = 1;

    for (; (nb / i) >= 10;) {
        i *= 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return (0);
}

unsigned long modifier_convert_in_octal3(unsigned long nb)
{
    unsigned long i = 1;

    for (; (nb / i) >= 8;) {
        i *= 8;
    }
    while (i > 0) {
        my_putchar((nb / i) % 8 + '0');
        i /= 8;
    }
    return (0);
}

unsigned long modifier_unsigned_function_smallhex3(unsigned long nb)
{
    unsigned long i = 1;
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

unsigned long modifier_unsigned_function_caphex3(unsigned long nb)
{
    unsigned long i = 1;
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
