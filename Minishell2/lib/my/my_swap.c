/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_swap
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;
    c = *b;
    *b = *a;
    *a = c;
}
