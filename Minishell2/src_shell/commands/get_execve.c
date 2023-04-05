/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** get_execve
*/

#include "shell.h"

int start_command(char **cmd, char *command, shell_t *shell)
{
    pid_t pid = fork();
    int status = 0;
    int error = 0;

    if (pid == -1)
        write_error(PROCESS_ERROR);
    else if (pid == 0) {
        (shell->pipe_out == true) ? dup2(shell->tmp_file, 1) : 0;
        execve(command, cmd, shell->env) == -1 ? my_printf("%s", cmd[0]),
        write_error(COMMAND_NOT_FOUND), shell->output = 1 : 0;
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        error = manage_execve_errors(status, shell);
    }
    if (error)
        return (shell->output);
    shell->output = 0;
    return (shell->output);
}

int my_simple_execve(char **cmd, shell_t *shell)
{
    if (cmd[0][0] == '.' && cmd[0][1] == '/' &&
    !opendir(cmd[0]) && !access(cmd[0], X_OK))
        return (start_command(cmd, cmd[0], shell));
    else if ((opendir(cmd[0]) != 0) || (cmd[0][0] == '.' &&
    cmd[0][1] == '/')) {
        my_printf("%s", cmd[0]);
        write_error(ERROR_ACCESS);
        shell->output = 1;
        return (shell->output);
    }
    return (-1);
}

int tool_exec(char **cmd, char **path)
{
    if (!access(cmd[0], X_OK)) {
        free_my_tab(path);
        return (1);
    }
    return (SUCCESS);
}

int my_execve(char **cmd, shell_t *shell)
{
    int wait = 0;
    char *tmp = EMPTY;
    int occu = get_env("PATH", shell->env);
    char **path = my_str_to_word_array(shell->env[occu], "=:");

    if (tool_exec(cmd, path))
        return (start_command(cmd, cmd[0], shell));
    while (path[wait]) {
        if ((tmp = check_execve(path, wait, cmd, tmp)) == EMPTY)
            return (shell->output);
        if (!access(tmp, X_OK)) {
            start_command(cmd, tmp, shell);
            free(tmp);
            free_my_tab(path);
            return (shell->output);
        }
        wait = increment_exe(tmp, wait);
    }
    error_command(path, cmd, shell);
    return (shell->output);
}

int get_execve(char **cmd, shell_t *shell)
{
    if (my_simple_execve(cmd, shell) == -1)
        return (my_execve(cmd, shell));
    return (shell->output);
}
