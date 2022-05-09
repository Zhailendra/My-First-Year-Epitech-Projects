/*
** EPITECH PROJECT, 2021
** error_display
** File description:
** Functions which fix several errors
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../my_printf.h"

void error_case(char *string, int *i)
{
    if (string[*i] == ' ')
        (*i)++;
    if (!(string[*i] > 32 && string[*i] < 127))
        my_putstr("% ");
}

int check_sign(char *string, int *i, va_list ap, va_list aq)
{
    int j = *i;
    switch (string[*i]) {
        case '+':
            (*i)++;
            return (manage_sign(string, i, ap, aq));
        case '-':
            (*i)++;
            j++;
            for (; my_isdigit(string[*i]); (*i)++);
            int_function(string, i, ap);
            get_size_space(string, &j, aq);
    }
    return (0);
}

int manage_sign(char *string, int *i, va_list ap, va_list aq)
{
    if (va_arg(aq, int) < 0 || string[*i] != 'd')
        int_function(string, i, ap);
    else if (string[*i] == 'd') {
        my_putchar('+');
        int_function(string, i, ap);
    }
    if (string[*i] == 'p') {
        my_putchar('+');
        conversion_special_function(string, i, ap);
    }
    return (0);
}

void cheat_function(char *string, int *i)
{
    if (string[*i] == 'X' || string[*i] == 'x')
        my_putchar('0');
}

void cheat_function2(char *string, int *i)
{
    if (string[*i] == 'X' || string[*i] == 'x')
        my_putchar(' ');
}
