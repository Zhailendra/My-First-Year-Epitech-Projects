/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** check_execve
*/

#include "shell.h"

int increment_exe(char *tmp, int wait)
{
    free(tmp);
    wait += 1;
    return (wait);
}

char *check_execve(char **path, int wait, char **cmd, char *tmp)
{
    if ((tmp = get_command_path(cmd[0], path[wait])) == EMPTY) {
        free_my_tab(path);
        return (EMPTY);
    }
    return (tmp);
}

int manage_execve_errors(int status, shell_t *shell)
{
    int sig = WTERMSIG(status);
    int count = 0;
    int fl = 0;
    int seg = 0;

    if (!WIFSIGNALED(status))
        return (SUCCESS);
    (sig == SIGFPE) ? write_error(FLOAT_EXCEP), shell->output = 11,
    count = 1, fl = 1 : 0;
    (sig == SIGSEGV) ? write_error(SEG_FAULT), shell->output = 8,
    count = 1, seg = 1 : 0;
    (sig == SIGFPE && fl == 1 && __WCOREDUMP(status)) ? write_error(CORE_DUMP),
    shell->output = 136, count = 1 : 0;
    (sig == SIGSEGV && seg == 1 && __WCOREDUMP(status)) ?
    write_error(CORE_DUMP),
    shell->output = 139, count = 1 : 0;
    (__WCOREDUMP(status) && !fl && !seg) ? write_error(ABORT_DUMP),
    shell->output = 134, count = 1 : 0;
    my_putchar('\n');
    return (count);
}
