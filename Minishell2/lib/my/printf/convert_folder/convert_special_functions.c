/*
** EPITECH PROJECT, 2021
** convert special case
** File description:
** Functions that convert my special output
*/

#include "../../my_printf.h"
#include <stdio.h>
#include <stdarg.h>

int non_printable_char_function(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] > 32 && str[i] < 127)) {
            convert_in_octal(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
    return (0);
}

long hexa_function(long nb)
{
    int i = 1;
    char *base = "0123456789abcdef";

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    } else {
        for (; (nb / i) >= 16;) {
            i *= 16;
        }
        while (i > 0) {
            my_putchar(base[(nb / i) % 16]);
            i /= 16;
        }
    }
    return (0);
}

void get_size(char *string, int *i, va_list aq)
{
    int j = 0;

    while (my_isdigit(string[*i])) {
        j *= 10;
        j += string[*i] - '0';
        (*i)++;
    }
    if (string[*i] == 'd' || string[*i] == 'i') {
        j -= my_int_len(va_arg(aq, int));
    }
    if (string[*i] == 'o' || string[*i] == 'x' || string[*i] == 'X' ||
    string[*i] == 'u') {
        help_function(string, i, aq);
        cheat_function(string, i);
        j -= my_int_len2(va_arg(aq, unsigned int));
    }
    for (; j > 0; j--) {
        my_putchar('0');
    }
}

void get_size_space(char *string, int *i, va_list aq)
{
    int j = 0;

    while (my_isdigit(string[*i])) {
        j *= 10;
        j += string[*i] - '0';
        (*i)++;
    }
    if (string[*i] == 'd' || string[*i] == 'i')
        j -= my_int_len(va_arg(aq, int));
    if (string[*i] == 'o' || string[*i] == 'x' || string[*i] == 'X' ||
    string[*i] == 'u') {
        help_function2(string, i, aq);
        cheat_function2(string, i);
        j -= my_int_len2(va_arg(aq, unsigned int));
    }
    for (; j > 0; j--) {
        my_putchar(' ');
    }
}

unsigned int my_int_len2(unsigned int nb)
{
    unsigned int count = 1;

    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    return (count);
}
