/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** shell
*/

#include "shell.h"

int start_shell(char **commands, shell_t *shell)
{
    if (commands == EMPTY)
        return (FAILURE);
    for (int tmp = 0; commands[tmp]; tmp++) {
        shell->pipe_out = false;
        shell->pipe_in = false;
        if (parse_commands_path(commands[tmp], shell) == FAILURE) {
            (commands) ? free_my_tab(commands) : 0;
            return (FAILURE);
        }
    }
    if (commands)
        free_my_tab(commands);
    return (SUCCESS);
}

int get_shell(shell_t *shell)
{
    char **commands = EMPTY;
    write_prompt(shell->env);
    signal(SIGINT, signal_handler);
    shell->output = 0;
    shell->clear = 0;
    shell->command_line = EMPTY;

    while ((shell->command_line = my_get_next_line(0))) {
        commands = my_str_to_word_array(shell->command_line, ";");
        start_shell(commands, shell);
        free(shell->command_line);
        if (shell->clear == 1 || shell->output == 84)
            break;
        write_prompt(shell->env);
    }
    if (shell->clear == 0)
        write(1, "exit\n", 5);
    return (shell->output);
}

int my_shell(char **env)
{
    shell_t shell;
    int result = 0;
    shell.env = EMPTY;

    if (env[0] == EMPTY)
        shell.env = initialize_empty_env(shell.env);
    else
        shell.env = initialize_env(env);
    if (shell.env == EMPTY)
        return (FAILURE);
    signal(SIGINT, signal_handler);
    result = get_shell(&shell);
    signal(SIGINT, SIG_DFL);
    free_my_tab(shell.env);
    return (result);
}
