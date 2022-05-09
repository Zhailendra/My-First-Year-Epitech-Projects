/*
** EPITECH PROJECT, 2021
** directive_functions
** File description:
** Functions which communicate with converting functions
*/

#include <stdarg.h>
#include "../../my_printf.h"
#include <stdio.h>

int flag_character_function(char *string, int i, va_list ap)
{
    switch (string[i]) {
        case 'o':
            my_putchar('0');
            return (convert_in_octal(va_arg(ap, unsigned int)));
        case 'x':
            my_putstr("0x");
            return (unsigned_function_smallhex(va_arg(ap, unsigned int)));
        case 'X':
            my_putstr("0X");
            return (unsigned_function_caphex(va_arg(ap, unsigned int)));
    }
    return (0);
}

int check_zero_flag(char *string, int *i, va_list ap, va_list aq)
{
    if (string[*i] == '0') {
        (*i)++;
        get_size(string, i, aq);
        for (; my_isdigit(string[*i]); (*i)++);
        int_function(string, i, ap);
    }
    if (my_isdigit(string[*i])) {
        get_size_space(string, i, aq);
        for (; my_isdigit(string[*i]); (*i)++);
        int_function(string, i, ap);
    }
    return (0);
}

int check_occur2(char *string, int *i, va_list ap)
{
    error_case(string, i);
    switch (string[*i]) {
        case 'd': case 'i':
            return (modifier_my_put_nbr2(va_arg(ap, unsigned int)));
        case 'o':
            return (modifier_convert_in_octal2(va_arg(ap, unsigned int)));
        case 'u':
            return (modifier_unsigned_function2(va_arg(ap, unsigned int)));
        case 'x':
            return (modifier_unsigned_function_smallhex2(va_arg(ap,
            unsigned int)));
        case 'X':
            return (modifier_unsigned_function_caphex2(va_arg(ap,
            unsigned int)));
    }
    return (0);
}

int check_occur3(char *string, int *i, va_list ap)
{
    error_case(string, i);
    switch (string[*i]) {
        case 'l':
            (*i)++;
            return (check_occur4(string, i, ap));
        case 'd': case 'i':
            return (modifier_my_put_nbr3(va_arg(ap, unsigned long)));
        case 'o':
            return (modifier_convert_in_octal3(va_arg(ap, unsigned long)));
        case 'u':
            return (modifier_unsigned_function3(va_arg(ap, unsigned long)));
        case 'x':
            return (modifier_unsigned_function_smallhex3(va_arg(ap,
            unsigned long)));
        case 'X':
            return (modifier_unsigned_function_caphex3(va_arg(ap,
            unsigned long)));
    }
    return (0);
}

int check_occur4(char *string, int *i, va_list ap)
{
    error_case(string, i);
    switch (string[*i]) {
        case 'd': case 'i':
            return (modifier_my_put_nbr4(va_arg(ap,
            unsigned long long)));
        case 'o':
            return (modifier_convert_in_octal4(va_arg(ap,
            unsigned long long)));
        case 'u':
            return (modifier_unsigned_function4(va_arg(ap,
            unsigned long long)));
        case 'x':
            return (modifier_unsigned_function_smallhex4(va_arg(ap,
            unsigned long long)));
        case 'X':
            return (modifier_unsigned_function_caphex4(va_arg(ap,
            unsigned long long)));
    }
    return (0);
}
