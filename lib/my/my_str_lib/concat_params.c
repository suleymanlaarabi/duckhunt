/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int temp_len = 0;
    char *str = 0;
    int k = 0;

    for (int i = 0; i < argc; i++) {
        temp_len = my_strlen(argv[i]) + 1;
    }
    str = malloc(sizeof(char) * temp_len);
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < my_strlen(argv[i]); j++) {
            str[k] = argv[i][j];
            k++;
        }
        if (i < argc - 1)
            str[k] = '\n';
        k++;
    }
    return str;
}
