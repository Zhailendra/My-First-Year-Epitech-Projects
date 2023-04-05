/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** signal
*/

#include "shell.h"

void write_prompt(char **env)
{
    prompt_t pr;
    static char user[4096 + 1];
    char *color_1 = "\e[0m";
    char *color_2 = "\e[0;95m";
    char *color_3 = "\033[1;33m";
    char *tmp = EMPTY;

    if (isatty(SUCCESS)) {
        getcwd(pr.os, 4096);
        if ((tmp = get_my_path(tmp, pr.os)) == EMPTY)
            return;
        if (env)
            (pr.path = get_env("USER=", env)) != -1 ?
            place_prompt(env[pr.path] + 5, user) : 0;
        if (my_strlen(user) > 0)
            my_printf("[%s%s%s]", color_2, user, color_1);
        my_printf("[%s%s%s]$ ", color_3, tmp, color_1);
        signal(SIGINT, signal_handler);
        free(tmp);
    }
}

void place_prompt(char *env, char *user)
{
    int tmp = 0;

    for (tmp = 0; tmp < 4096 && env[tmp]; tmp++)
        user[tmp] = env[tmp];
    user[tmp] = '\0';
}

void signal_handler(int sigl)
{
    if (!sigl)
        return;
    write(1, "\n", 1);
    write_prompt(EMPTY);
    signal(SIGINT, signal_handler);
}

void till_end(char **cmd_pipe, int status)
{
    for (int tmp = 0; cmd_pipe[tmp]; tmp++)
        wait(&status);
}
