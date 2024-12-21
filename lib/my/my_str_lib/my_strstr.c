/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

static int check_suite(char *str, char const *to_find)
{
    int len = my_strlen(to_find);

    for (int i = 0; i < len && str[i] != '\0'; i++) {
        if (str[i] != to_find[i]) {
            return 0;
        }
    }
    return 1;
}

static int check_for_suite(
    char *str,
    char const *to_find,
    int i)
{
    if (str[i] == to_find[0] && check_suite(&str[i], to_find) == 1) {
        return 1;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(str);
    int find_len = my_strlen(to_find);

    if (find_len == 0) {
        return 0;
    }
    for (int i = 0; i <= len; i++) {
        if (check_for_suite(str, to_find, i) == 1) {
            return &str[i];
        }
    }
    return 0;
}
