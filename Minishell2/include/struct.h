/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** struct
*/

#include <stdbool.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct prompt {
    int path;
    char os[4096];
}prompt_t;

typedef struct redirection {
    char *descriptor_a;
    int mode;
    char *descriptor_b;
}redirection_t;

typedef struct shell {
    char **env;
    int output;
    int clear;
    char *command_line;
    int prev;
    bool pipe_in;
    bool pipe_out;
    int file[2];
    int tmp_file;
    redirection_t entity;
}shell_t;

#endif
