/*
** EPITECH PROJECT, 2022
** PSU-2
** File description:
** sokoban
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "my_get_nl.h"
#include "struct.h"

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #define SUCCESS (int) 0
    #define FAILURE (int) 84
    #define IS_OBJ (int) 2
    #define IS_WALL (int) -2
    #define IS_FREE (int) 1
    #define IS_TARGET (int) -1
    #define WIN (int) 5
    #define EMPTY NULL
    #define WRONG_ARGS  "ERROR: bad arguments\nTry '-h' for help.\n"
    #define FILE_FAILURE "ERROR: unable to open map.\n"
    #define BAD_MALLOC "ERROR: malloc failure.\n"
    #define BAD_MAP "ERROR: invalid map\n"

int manage_usage(int args, char **path);

sokoban_t *initialize_sokoban(char *map_path);

int get_map(sokoban_t *sokoban);

char **get_tab(char **tab, sokoban_t *sokoban, map_t *map_struct, int n);

struct stat check_map(sokoban_t *sokoban, struct stat my_stat);

void write_error(char *error);

void free_all(sokoban_t *sokoban, char **tab);

int display_sokoban(sokoban_t *sokoban, char **tab, int display);

void get_lign(sokoban_t * sokoban, map_t *map_struct);

void get_column(sokoban_t * sokoban, map_t *map_struct);

int check_tab(map_t *map_struct, char **tab);

void get_end(map_t *map_struct, char **tab);

int check_key(int key);

void check_movements(map_t *map_struct, char **tab, int key);

void get_movements(map_t *map_struct, char **tab);

void display_movements(map_t *map_struct, char **tab);

int check_position(int position_x, int position_y, char **tab);

int check_if_obj(int position_x, int position_y, map_t *map_struct);

int get_obj_nb(map_t *map_struct, char **tab);

void display_if_win(sokoban_t *sokoban, char **tab);

int main_sokoban(char *map_path);

void *start_sokoban(sokoban_t *sokoban, char **tab);

char **check_if_reset(sokoban_t *sokoban, char **tab, int key);

#endif
