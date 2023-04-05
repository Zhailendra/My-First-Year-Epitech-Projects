/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** my_getnbr
*/

#include "shell.h"

int my_getnbr(char const *string)
{
    int a = 0;
    int res = 0;
    int negative = 1;

    while (string[a] == 43 || string[a] == 45) {
        if (string[a] == 45)
            negative *= -1;
        a++;
    }
    while (string[a] != '\0') {
        if (string[a] > 47 && string[a] < 58) {
            res *= 10;
            res += string[a] - 48;
        } else
            return (res * negative);
        a++;
    }
    return (res * negative);
}
