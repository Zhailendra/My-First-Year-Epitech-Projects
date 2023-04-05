/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-shailendra.blondel
** File description:
** initialize
*/

#include "shell.h"

char **get_malloc(int size, char **array)
{
    char **tmp = EMPTY;
    int count = 0;
    int lines = 0;

    if (array == EMPTY)
        return (EMPTY);
    while (array[count])
        count++;
    tmp = malloc(sizeof(char *) * (size + 1 + count));
    count = 0;
    while (array[count]) {
        tmp[count] = my_strdup(array[count]);
        free(array[count]);
        count++;
    }
    while (lines <= size) {
        tmp[count + lines] = EMPTY;
        lines++;
    }
    return (tmp);
}

char **get_pwd(char **env, int size)
{
    char *tmp = malloc(sizeof(char) * 1024);

    if (tmp == EMPTY)
        return (EMPTY);
    if (!getcwd(tmp, 1024))
        return (EMPTY);
    if (env[size])
        free(env[size]);
    else
        env = get_malloc(1, env);
    env[size] = malloc(sizeof(char) * (my_strlen(tmp) + 5));
    env[size] = my_strcpy(env[size], "PWD=");
    env[size] = my_strcat(env[size], tmp);
    free(tmp);
    return (env);
}

char **initialize_empty_env(char **env)
{
    env = malloc(sizeof(char *) * 11);

    if (env == EMPTY)
        return (EMPTY);
    env[0] = my_strdup("HOSTTYPE=x86_64-linux");
    env[1] = my_strdup("VENDOR=unknown");
    env[2] = my_strdup("OSTYPE=linux");
    env[3] = my_strdup("MACHTYPE=x86_64");
    env[4] = my_strdup("SHLVL=1");
    env[5] = my_strdup("LOGNAME=sblondel");
    env[6] = my_strdup("USER=sblondel");
    env[7] = my_strdup("GROUP=sblondel");
    env[8] = my_strdup("HOST=fedora");
    env[9] = my_strdup("PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:\
/usr/sbin:/var/lib/snapd/snap/bin:/home/sblondel/bin");
    env[10] = EMPTY;
    env = get_pwd(env, 10);

    return (env);
}

char **initialize_env(char *env[])
{
    int a = 0;
    char **my_own = EMPTY;

    if (!env)
        return (EMPTY);
    if ((my_own = malloc(sizeof(char *) * (my_tablen(env) + 1))) == EMPTY) {
        write_error(BAD_MALLOC);
        return (EMPTY);
    }
    for (; env[a]; a++)
        my_own[a] = my_strdup(env[a]);
    my_own[a] = EMPTY;
    return (my_own);
}
