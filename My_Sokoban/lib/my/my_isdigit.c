/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_isdigit
*/

#include "my.h"

int my_isdigit(char c)
{
    if ((c > 47) && (c < 58))
        return (1);
    else
        return (0);
}
