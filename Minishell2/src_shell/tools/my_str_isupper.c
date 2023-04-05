/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** my_str_isupper
*/

#include "shell.h"

int my_str_isalpha_setenv(char c)
{
    if ((c >= 97 && c <= 122) || (c == '(' || c == ')'))
        return (1);
    return (0);
}

int my_str_isupper(char c)
{
    if (c >= 65 && c <= 90)
        return (1);
    return (0);
}
