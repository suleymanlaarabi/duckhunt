/*
** EPITECH PROJECT, 2024
** day06
** File description:
** my_strncpy
*/

#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            break;
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
