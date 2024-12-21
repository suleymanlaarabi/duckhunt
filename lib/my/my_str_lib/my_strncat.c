/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_src = my_strlen(src);
    int len_dest = my_strlen(dest);

    for (int i = len_dest; i < nb + len_dest; i++) {
        dest[i] = src[i - len_dest];
    }
    dest[len_dest + len_src] = '\0';
    return dest;
}
