/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** get_pipe
*/

#include "shell.h"

int handle_redirection(char *cmd, shell_t *shell)
{
    int result = SUCCESS;
    (manage_entities(shell, &shell->entity, cmd) == FAILURE) ? result = FAILURE
    , (shell->entity.descriptor_a) ? free(shell->entity.descriptor_a) : 0,
    (shell->entity.descriptor_b) ? free(shell->entity.descriptor_b) : 0 : 0;

    if (result == SUCCESS) {
        (shell->entity.mode == 1) ? init_redirection(shell, &shell->entity)
        : 0;
        (shell->entity.mode == 2) ? init_redirection_s(shell, &shell->entity)
        : 0;
        (shell->entity.mode == 10) ? init_redirection_in(shell, &shell->entity)
        : 0;
        (shell->entity.mode == 3) ?
        init_redirection_in_s(shell, &shell->entity) : 0;
        (shell->entity.descriptor_a) ? free(shell->entity.descriptor_a) : 0;
        (shell->entity.descriptor_b) ? free(shell->entity.descriptor_b) : 0;
    }
    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int get_redirection(char *cmd)
{
    int result = 0;

    for (; *cmd; cmd++)
        (*cmd == '<' || *cmd == '>') ? result = 1 : 0;
    return (result);
}

int handle_pipe(char *cmd, shell_t *shell)
{
    int status = 0;
    int result = SUCCESS;
    char **cmd_pipe = my_str_to_word_array(cmd, "|");
    (check_cmd_pipe(cmd_pipe) == FAILURE) ? result = FAILURE,
    write_error(INSTRUCTION_ERROR), shell->output = 1 : 0;

    if (result == SUCCESS) {
        for (int tmp = 0; cmd_pipe[tmp] != NULL; (start_pipe_parsing(shell,
        my_tablen(cmd_pipe) - 1, tmp, cmd_pipe[tmp]) == FAILURE) ? result =
        FAILURE, write_error(PIPE_FAILED), shell->output = 1 : 0, tmp++);
        till_end(cmd_pipe, status);
    }
    if (result == FAILURE) {
        (cmd_pipe) ? free_my_tab(cmd_pipe) : 0;
        return (FAILURE);
    }
    (cmd_pipe) ? free_my_tab(cmd_pipe) : 0;
    shell->output = 0;
    return (SUCCESS);
}

int get_pipe(char *cmd)
{
    int result = 0;

    for (; *cmd; cmd++)
        (*cmd == '|') ? result = 1 : 0;
    return (result);
}
