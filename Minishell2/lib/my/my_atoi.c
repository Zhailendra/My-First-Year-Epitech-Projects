/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *string)
{
    int result = 0;
    int negative = 0;

    if (*string == '-') {
        negative = 1;
        string++;
    }
    for (; *string; string++) {
        if (*string >= '0' && *string <= '9') {
            result *= 10;
            result += *string - '0';
        } else
            return (result);
    }
    if (negative == 0)
        return (result);
    else
        return (-result);
}
