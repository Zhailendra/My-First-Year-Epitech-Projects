/*
** EPITECH PROJECT, 2021
** my_prinft
** File description:
** Function that remake prinft function from the C library
*/

#include <stdarg.h>
#include "../my_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int int_function(char *string, int *i, va_list ap)
{
    switch (string[*i]) {
        case 'd': case 'i':
            return (my_put_nbr(va_arg(ap, int)));
        case 'b':
            return (convert_in_unsigned_bin(va_arg(ap, unsigned int)));
        case 'o':
            return (convert_in_octal(va_arg(ap, unsigned int)));
        case 'u':
            return (unsigned_function(va_arg(ap, unsigned int)));
        case 'x':
            return (unsigned_function_smallhex(va_arg(ap, unsigned int)));
        case 'X':
            return (unsigned_function_caphex(va_arg(ap, unsigned int)));
    }
    return (0);
}

int conversion_special_function(char *string, int *i, va_list ap)
{
    switch (string[*i]) {
        case 'c':
            return (my_putchar(va_arg(ap, int)));
        case 's':
            return (my_putstr(va_arg(ap, char *)));
        case 'S':
            return (non_printable_char_function(va_arg(ap, char *)));
        case 'p':
            my_putstr("0x");
            return (hexa_function(va_arg(ap, long)));
        case '%':
            return (my_putchar('%'));
        case 'm':
            return (my_putstr("Success"));
    }
    return (0);
}

int check_occur(char *string, int *i, va_list ap)
{
    error_case(string, i);
    switch (string[*i]) {
        case 'h':
            (*i)++;
            return (check_occur2(string, i, ap));
        case 'd': case 'i':
            return (modifier_my_put_nbr(va_arg(ap, unsigned int)));
        case 'o':
            return (modifier_convert_in_octal(va_arg(ap, unsigned int)));
        case 'u':
            return (modifier_unsigned_function(va_arg(ap, unsigned int)));
        case 'x':
            return (modifier_unsigned_function_smallhex(va_arg(ap,
            unsigned int)));
        case 'X':
            return (modifier_unsigned_function_caphex(va_arg(ap,
            unsigned int)));
    }
    return (0);
}

int check_resemblances(char *string, int *i, va_list ap)
{
    switch (string[*i]) {
        case '#':
            (*i)++;
            return (flag_character_function(string, *i, ap));
        case 'h':
            (*i)++;
            return (check_occur(string, i, ap));
        case 'l': case 'z': case 'Z':
            (*i)++;
            return (check_occur3(string, i, ap));
        case 'q': case 'j':
            (*i)++;
            return (check_occur4(string, i, ap));
    }
    return (0);
}

void my_printf(char *string, ...)
{
    va_list ap;
    va_start(ap, string);
    va_list aq;
    va_copy(aq, ap);

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != '%')
            my_putchar(string[i]);
        else {
            i++;
            error_case(string, &i);
            int_function(string, &i, ap);
            conversion_special_function(string, &i, ap);
            check_resemblances(string, &i, ap);
            check_zero_flag(string, &i, ap, aq);
            check_sign(string, &i, ap, aq);
        }
    }
    va_end(aq);
    va_end(ap);
}
