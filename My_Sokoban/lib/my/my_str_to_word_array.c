/*
** EPITECH PROJECT, 2022
** My_lib
** File description:
** my_str_to_word_array
*/

#include "my.h"

int delim_length(char *string, char *delim);

int limit(char character, char *delim);

int number_of_words(char *string, char *delim);

int my_word_length(char *string, char *delim);

int number_of_words(char *string, char *delim)
{
    int tmp = my_word_length(string + delim_length(string, delim),
    delim);
    int count = delim_length(string + tmp, delim);

    if (tmp == 0)
        return (0);
    return (1 + number_of_words(string + tmp + count, delim));

}

int my_word_length(char *string, char *delim)
{
    int length;

    if (string == NULL)
        return (0);
    for (length = 0; !limit(string[length], delim) && string[length] != '\0';
    length++);
    return (length);
}

int limit(char character, char *delim)
{
    for (int a = 0; delim[a]; a++)
        if (delim[a] == character)
            return (1);
    return (0);
}

int delim_length(char *string, char *delim)
{
    int length;

    if (string == NULL)
        return (0);
    for (length = 0; limit(string[length], delim) && string[length] != '\0';
    length++);
    return (length);
}

char **my_str_to_word_array(char *string, char *delim)
{
    int j = 0;
    int size = 0;
    char **my_tab = malloc(sizeof(char *) * (number_of_words(string, delim)
    + 1));

    if (!my_tab || !string || !delim)
        return (NULL);
    j = j + delim_length(string + j, delim);
    for (; string[j]; size++) {
        my_tab[size] = my_strndup(string + j,
        my_word_length(string + j, delim));
        j = j + my_word_length(string + j, delim);
        j = j + delim_length(string + j, delim);
    }
    my_tab[size] = NULL;
    return (my_tab);
}
