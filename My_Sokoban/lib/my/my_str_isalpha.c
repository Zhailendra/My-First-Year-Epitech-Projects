/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_str_isalpha
*/

#include "my.h"

int my_str_isalpha(char c)
{
    if (!(c >= '0' && c <= '9'))
        return (1);
    return (0);
}
