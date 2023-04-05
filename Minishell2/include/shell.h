/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell2-shailendra.blondel
** File description:
** shell
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <wait.h>
#include <errno.h>
#include <stdbool.h>
#include <dirent.h>
#include "struct.h"
#include "my_get_nl.h"

#ifndef SHELL_H_
    #define SHELL_H_

    #define SUCCESS (0)
    #define FAILURE (84)
    #define EMPTY NULL
    #define FALSE false
    #define SHELL (100)
    #define BUFFER_SIZE (4096)
    #define BAD_MALLOC "ERROR: bad malloc.\n"
    #define PROMPT "[user@OS]$ "
    #define ERROR "ERROR: too many arguments\n"
    #define HELP "USAGE:\n\t./mysh [NO ARGUMENTS].\n"
    #define COMMAND_NOT_FOUND ": Command not found.\n"
    #define ENV_FILE_ERROR ":No such file or directory\n"
    #define CD_DIRECTORY_ERROR ": No such file or directory.\n"
    #define CD_ERROR_ACCESS ": Not a directory.\n"
    #define CD_ARGS_ERROR "cd: Too many arguments.\n"
    #define SETENV_ARGS_ERROR "setenv: Too many arguments.\n"
    #define SETENV_ARGS_ERROR_S "setenv: Variable name must " \
    "begin with a letter.\n"
    #define UNSETENV_ERROR "unsetenv: Too few arguments.\n"
    #define ERROR_ACCESS ": Permission denied.\n"
    #define PROCESS_ERROR "ERROR: Failed to spawn status process!\n"
    #define FLOAT_EXCEP "Floating exception"
    #define SEG_FAULT "Segmentation fault"
    #define CORE_DUMP " (core dumped)"
    #define ABORT_DUMP "Abort (core dumped)"
    #define INSTRUCTION_ERROR "Invalid null command.\n"
    #define PIPE_FAILED "Pipe failed.\n"
    #define REDIRECTION_AMBIGUOUS "Ambiguous output redirect.\n"
    #define REDIRECTION_MISSING "Missing name for redirect.\n"
    #define OPENING_REDIRECTION_ERROR "Error while opening %s.\n"

int my_shell(char **env);

void free_my_tab(char **tab);

void free_my_tab_int(int **tab);

void signal_handler(int sigl);

void write_prompt(char **env);

void *auto_alloc(char *any);

void print_error(char *cd);

int check_str_begin(char *new, char *old);

void place_prompt(char *env, char *user);

int my_tablen(char **tab);

unsigned char check_if_digit(char const *string);

int my_getnbr(char const *string);

int my_str_isupper(char c);

int my_str_isalpha_setenv(char c);

char **initialize_empty_env(char **env);

char **initialize_env(char *env[]);

int start_parsing(char ***my_env, char **commands, shell_t shell);

int parse_commands_path(char *cmd, shell_t *shell);

int get_pipe(char *cmd);

int handle_pipe(char *cmd, shell_t *shell);

int handle_redirection(char *cmd, shell_t *shell);

int get_redirection(char *cmd);

int manage_entities(shell_t *shell, redirection_t *entity, char *cmd);

char *parse_placement(char *cmd);

char *parse_placement_s(int *mode, char *cmd);

int check_cmd_pipe(char **cmd_pipe);

int around_pipe(char *pipe);

int start_pipe_parsing(shell_t *shell, int size, int occu, char *pipe);

int init_pipe(shell_t *shell, char *pipe_v);

int init_pipe_s(shell_t *shell, char *pipe_v);

int init_mul_pipe(shell_t *shell, char *pipe_v);

void init_redirection(shell_t *shell, redirection_t *entity);

void init_redirection_s(shell_t *shell, redirection_t *entity);

void init_redirection_in(shell_t *shell, redirection_t *entity);

void init_redirection_in_s(shell_t *shell, redirection_t *entity);

void launch(shell_t *shell, redirection_t *entity);

char *parse_text(redirection_t *entity, char *prev);

void launch_double_rdl(shell_t *shell, redirection_t *entity, char *prev);

char *get_place_for_text(char *tmp);

char *get_more_place_for_text(char *tmp, char *prev);

int handle_commands(char *cmd, shell_t *shell);

int parse_commands(char **commands, shell_t *shell);

int get_builtins(char **commands);

int my_cd(char **cd, shell_t *shell);

void initial_dir(shell_t *shell);

int manage_path(char *prev_path, char tmp[BUFFER_SIZE], shell_t *shell);

char **place_new_path(char *create_path, char *prev_path, shell_t *shell);

int get_place(char *pos);

void go_to_home(char **cd, shell_t *shell);

char *get_old(char *path, char **env);

int check_cd_error(char *cd, shell_t *shell);

char *put_path(char *dir, char *path);

int major_deplacement(char **env, char *cd, shell_t *shell);

int my_env(char **prompt, shell_t *shell);

int my_setenv(char **setting, shell_t *shell);

int my_unsetenv(char **unsetting, shell_t *shell);

int get_execve(char **cmd, shell_t *shell);

int my_exit(char **cmd, shell_t *shell);

char *get_command_path(char *cmd, char *current);

int manage_execve_errors(int status, shell_t *shell);

void write_error(char *error);

int check_brackets(char **tab);

int check_alphanum(char *string);

char *env_position(char *path, char **env);

int recup_env(char *setting, shell_t *shell);

int get_env(char *set, char **env);

int replace_env(shell_t *shell);

char *get_my_env(char *setting, shell_t *shell);

char *get_my_path(char *tmp, char *path);

char *change_dir(char *cd);

void error_command(char **path, char **cmd, shell_t *shell);

char *check_execve(char **path, int wait, char **cmd, char *tmp);

int increment_exe(char *tmp, int wait);

void till_end(char **cmd_pipe, int status);

#endif
