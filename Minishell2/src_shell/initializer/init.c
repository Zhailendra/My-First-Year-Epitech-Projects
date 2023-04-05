/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-shailendra.blondel
** File description:
** init
*/

#include "shell.h"

void init_redirection_s(shell_t *shell, redirection_t *entity)
{
    char tmp[BUFFER_SIZE];
    int result = SUCCESS;
    int current = 0;
    shell->pipe_out = true;
    (!my_strlen(entity->descriptor_b)) ? result = FAILURE,
    write_error(REDIRECTION_MISSING), shell->output = 1 : 0;
    ((result == SUCCESS) && (shell->tmp_file = open(entity->descriptor_b,
    O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |
    S_IWOTH)) == -1) ? result = FAILURE,
    my_printf("%s: No such file or directory.\n", entity->descriptor_b),
    shell->output = 1 : 0;
    current = read(shell->tmp_file, tmp, sizeof(tmp));
    for (; current > 0; current = read(shell->tmp_file, tmp, sizeof(tmp)));
    ((result == SUCCESS) && (get_pipe(entity->descriptor_a))) ?
    shell->pipe_out = false, shell->pipe_in = true,
    handle_pipe(entity->descriptor_a, shell) : (result == SUCCESS) ?
    handle_commands(entity->descriptor_a, shell) : 0;
    close(shell->tmp_file);
}

void init_redirection(shell_t *shell, redirection_t *entity)
{
    int result = SUCCESS;
    shell->pipe_out = true;
    (!my_strlen(entity->descriptor_b)) ? result = FAILURE,
    write_error(REDIRECTION_MISSING), shell->output = 1 : 0;
    ((result == SUCCESS) && (shell->tmp_file = open(entity->descriptor_b,
    O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
    | S_IROTH | S_IWOTH)) == -1) ? result = FAILURE,
    my_printf("%s: No such file or directory.\n", entity->descriptor_b),
    shell->output = 1 : 0;
    ((result == SUCCESS) && (get_pipe(entity->descriptor_a))) ?
    shell->pipe_out = false, shell->pipe_in = true,
    handle_pipe(entity->descriptor_a, shell) : (result == SUCCESS) ?
    handle_commands(entity->descriptor_a, shell) : 0;
    close(shell->tmp_file);
}

int init_mul_pipe(shell_t *shell, char *pipe_v)
{
    int result = SUCCESS;
    pid_t my_pid = fork();
    (my_pid == -1) ? result = FAILURE,
    write_error(PROCESS_ERROR) : 0;
    (my_pid == 0) ? dup2(shell->prev, 0), dup2(shell->file[1], 1),
    close(shell->file[0]), handle_commands(pipe_v, shell), exit(1) :
    close(shell->file[1]), close(shell->prev), shell->prev = shell->file[0];

    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int init_pipe_s(shell_t *shell, char *pipe_v)
{
    int result = SUCCESS;
    pid_t my_pid = fork();
    (my_pid == -1) ? result = FAILURE, shell->output = 1,
    write_error(PROCESS_ERROR) : 0;
    (my_pid == 0) ? ((shell->pipe_in == true) ? shell->pipe_out = true : 0),
    dup2(shell->file[0], 0), close(shell->prev), close(shell->file[1]),
    handle_commands(pipe_v, shell), exit(1) : close(shell->file[0]),
    close(shell->file[1]), close(shell->prev);

    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

int init_pipe(shell_t *shell, char *pipe_v)
{
    int result = SUCCESS;
    pid_t my_pid = fork();
    (my_pid == -1) ? result = FAILURE,
    write_error(PROCESS_ERROR) : 0;
    (my_pid == 0) ? dup2(shell->file[1], 1), close(shell->file[0]),
    handle_commands(pipe_v, shell), exit(1) : close(shell->file[1]),
    shell->prev = shell->file[0];

    if (result == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}
