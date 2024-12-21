/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int len = 0;

    if (list_is_empty(begin))
        return len;
    while (begin != NULL) {
        len++;
        begin = begin->next;
    }
    return len;
}
