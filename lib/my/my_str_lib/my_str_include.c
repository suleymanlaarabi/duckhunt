/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stddef.h>

// return struct {-1, -1} if str not include in src
start_end_info_t my_str_include(char const *src, char const *str)
{
    int str_len = 0;
    start_end_info_t info = {-1, -1};

    if (str != NULL)
        str_len = my_strlen(str);
    for (int i = 0; src[i] != '\0'; i++) {
        if (my_strncmp(&src[i], str, str_len) == 0) {
            info.start = i;
            info.end = i + str_len;
            return info;
        }
    }
    return info;
}

int my_str_include_before(
    char const *src,
    char const *str,
    char before)
{
    char before_str[1] = {before};
    start_end_info_t str_info = my_str_include(src, str);
    start_end_info_t bfr_info = my_str_include(src, before_str);

    if (str_info.start != -1) {
        if (bfr_info.start != -1 && bfr_info.start < str_info.start)
            return 0;
        return 1;
    }
    return 0;
}

// return 0 if  str not containt char if contain return 1
bool my_str_include_char(char const *src, char c)
{
    for (int i = 0; src[i] != '\0'; i++)
        if (src[i] == c)
            return 1;
    return 0;
}
