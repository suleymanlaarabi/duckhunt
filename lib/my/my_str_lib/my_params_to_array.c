/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *params =
        malloc(sizeof(struct info_param) * (ac + 1));

    for (int i = 0; i < ac; i++) {
        params[i].length = my_strlen(av[i]);
        params[i].word_array = my_str_to_word_array(av[i]);
        params[i].str = av[i];
        params[i].copy = my_strdup(av[i]);
    }
    params[ac].str = NULL;
    return params;
}
