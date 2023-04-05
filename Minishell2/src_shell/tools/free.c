/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** free
*/

#include "shell.h"

void free_my_tab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++)
            (tab[i] != EMPTY) ? free(tab[i]) : 0;
        free(tab);
    }
}
