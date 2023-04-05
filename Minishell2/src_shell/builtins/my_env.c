/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_env
*/

#include "shell.h"

int my_env_tool(shell_t *shell)
{
    int status = 0;
    pid_t my_pid = fork();

    if (my_pid == -1)
        return (write_error(PROCESS_ERROR), 1);
    (my_pid == 0) ? (shell->pipe_out == true) ?
    dup2(shell->tmp_file, 1) : 0, my_show_word_array(shell->env), exit(1)
    : wait(&status);
    return (shell->output);
}

int my_env(char **prompt, shell_t *shell)
{
    char *f_directory = "error";

    if (!shell->env)
        return (FAILURE);
    if (prompt[1]) {
        if (!my_strcomp("*", prompt[1])) {
            my_printf("env: '%s'", f_directory);
            write_error(ENV_FILE_ERROR);
            shell->output = 1;
            return (shell->output);
        }
        my_printf("env: '%s'", prompt[1]);
        write_error(ENV_FILE_ERROR);
        shell->output = 127;
        return (shell->output);
    }
    if (my_env_tool(shell) == FAILURE)
        return (1);
    shell->output = 0;
    return (shell->output);
}
