/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int len_src = my_strlen(src);
    int len_dest = my_strlen(dest);

    for (int i = len_dest; i < len_dest + len_src; i++) {
        dest[i] = src[i - len_dest];
    }
    dest[len_dest + len_src] = '\0';
    return dest;
}

char *my_strcat_nobuffer(const char *str1, const char *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    char *result = malloc(len_str1 + len_str2 + 1);

    if (result == NULL)
        return NULL;
    my_strcpy(result, str1);
    my_strcpy(&result[len_str1], str2);
    result[len_str1 + len_str2] = '\0';
    return result;
}

char *my_strcat_nobuffer_sep(const char *str1, const char *str2, char sep)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    char *result = malloc(len_str1 + len_str2 + 2);

    if (result == NULL)
        return NULL;
    my_strcpy(result, str1);
    result[len_str1] = sep;
    my_strcpy(&result[len_str1 + 1], str2);
    result[len_str1 + len_str2 + 1] = '\0';
    return result;
}
