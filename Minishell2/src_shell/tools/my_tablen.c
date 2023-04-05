/*
** EPITECH PROJECT, 2022
** New_minishell1
** File description:
** my_tablen
*/

#include "shell.h"

int my_tablen(char **tab)
{
    int length = 0;

    for (; tab && tab[length] != 0; length++);
    return (length);
}
