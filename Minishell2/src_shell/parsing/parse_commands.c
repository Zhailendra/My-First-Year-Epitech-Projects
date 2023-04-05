/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** parse_commands
*/

#include "shell.h"

int help_parsing(char **commands)
{
    if (!my_strcomp(commands[0], "\n")) {
        free_my_tab(commands);
        return (1);
    }
    return (SUCCESS);
}

int parse_commands(char **commands, shell_t *shell)
{
    int error_output = 1;
    int builtins = get_builtins(commands);
    static int (*tab[])(char **, shell_t *) = {
        my_cd,
        my_env,
        my_setenv,
        my_unsetenv,
        my_exit,
        get_execve
    };

    if (!commands) {
        free_my_tab(commands);
        return (tab[builtins](commands, shell));
    }
    if (help_parsing(commands))
        return (1);
    error_output = tab[builtins](commands, shell);
    free_my_tab(commands);
    return (error_output);
}

int handle_commands(char *cmd, shell_t *shell)
{
    char **commands = my_str_to_word_array(cmd, " \t");

    if (commands == EMPTY)
        return (FAILURE);
    shell->output = parse_commands(commands, shell);
    return (SUCCESS);
}

int parse_commands_path(char *cmd, shell_t *shell)
{
    int result = SUCCESS;
    int pipe = get_pipe(cmd);
    int redirection = get_redirection(cmd);

    if (redirection == 1)
        (handle_redirection(cmd, shell) == FAILURE) ? result = FAILURE : 0;
    else if (pipe == 1)
        (handle_pipe(cmd, shell) == FAILURE) ? result = FAILURE : 0;
    else
        (handle_commands(cmd, shell) == FAILURE) ? result = FAILURE : 0;
    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
