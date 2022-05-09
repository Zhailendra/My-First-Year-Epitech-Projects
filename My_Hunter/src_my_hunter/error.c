/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** Check if there is/are error(s);
*/

#include "../include/my_hunter.h"

int error_with_window(window_t *my_window)
{
    if (!my_window -> window)
        return (my_putstr("FAILURE with window opening\n"));
    if (!my_window -> font)
        return (my_putstr("FAILURE with interface creation\n"));
}
