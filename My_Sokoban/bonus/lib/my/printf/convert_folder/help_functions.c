/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-shailendra.blondel
** File description:
** help_functions
*/

#include <stdarg.h>
#include "../../my_printf.h"

void help_function(char *string, int *i, va_list aq)
{
    va_list tmp;
    va_copy(tmp, aq);

    if (string[*i] == 'x' || string[*i] == 'X') {
        if (va_arg(tmp, int) < 0)
            my_putchar('0');
    }
}

void help_function2(char *string, int *i, va_list aq)
{
    va_list tmp;
    va_copy(tmp, aq);

    if (string[*i] == 'x' || string[*i] == 'X') {
        if (va_arg(tmp, int) < 0)
            my_putchar(' ');
    }
}
