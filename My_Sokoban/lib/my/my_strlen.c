/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int count = 0;

    if (!str)
        return (0);
    for (; *str != '\0'; str++)
        count++;
    return (count);
}
