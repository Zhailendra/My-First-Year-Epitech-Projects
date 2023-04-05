/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** check_if_digit
*/

#include "shell.h"

unsigned char check_if_digit(char const *string)
{
    unsigned char a = 0;

    if (string[a] == '-')
        a = 1;
    while (string[a] != '\0') {
        if (string[a] < '0' || string[a] > '9')
            return (0);
        a++;
    }
    return (string ? 1 : 0);
}
