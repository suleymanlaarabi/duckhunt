/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

#include <stdlib.h>

char *my_strdup(char const *src)
{
    unsigned long len = 0;
    char *new_str = NULL;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    new_str = malloc(sizeof(char) * len + 1);
    my_strcpy(new_str, src);
    return new_str;
}

char *my_strndup(char const *src, int n)
{
    char *new_str = NULL;

    if (src == NULL)
        return NULL;
    new_str = malloc(sizeof(char) * n + 1);
    my_strncpy(new_str, src, n);
    return new_str;
}
