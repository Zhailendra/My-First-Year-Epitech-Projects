/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_exit
*/

#include "shell.h"

int my_exit(char **cmd, shell_t *shell)
{
    char *exit_output = "exit: Expression Syntax.\n";

    if (cmd && cmd[0] && cmd[1]) {
        if (check_if_digit(cmd[1])) {
            write(1, "exit\n", 5);
            shell->clear = 1;
            return (my_getnbr(cmd[1]));
        } else if (my_str_isalpha(cmd[1][0])) {
            write_error(exit_output);
            return (-1);
        } else {
            write_error(exit_output);
            return (-1);
        }
    }
    write(1, "exit\n", 5);
    shell->clear = 1;
    shell->output = 0;
    return (shell->output);
}
