/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    linked_list_t *list = NULL;

    for (int i = 0; i < ac; i++) {
        list = push_front(list, av[i]);
    }
    return list;
}
