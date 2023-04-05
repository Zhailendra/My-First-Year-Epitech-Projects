/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** main
*/

#include "shell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    if (env == EMPTY)
        return (FAILURE);
    return (my_shell(env));
}
