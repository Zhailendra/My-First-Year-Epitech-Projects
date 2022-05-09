/*
** EPITECH PROJECT, 2021
** new_special_case_functions
** File description:
** Functions for length modifier "%hh..."
*/

#include "../../my_printf.h"

unsigned char modifier_my_put_nbr2(unsigned char nb)
{
    int i = 1;

    if (nb > 127) {
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

unsigned char modifier_unsigned_function2(unsigned char nb)
{
    unsigned char i = 1;

    for (; (nb / i) >= 10;) {
        i *= 10;
    }
    while (i > 0) {
        my_putchar((nb / i) % 10 + '0');
        i /= 10;
    }
    return (0);
}

unsigned char modifier_convert_in_octal2(unsigned char nb)
{
    unsigned char i = 1;

    for (; (nb / i) >= 8;) {
        i *= 8;
    }
    while (i > 0) {
        my_putchar((nb / i) % 8 + '0');
        i /= 8;
    }
    return (0);
}

unsigned char modifier_unsigned_function_smallhex2(unsigned char nb)
{
    unsigned char i = 1;
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

unsigned char modifier_unsigned_function_caphex2(unsigned char nb)
{
    unsigned char i = 1;
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
