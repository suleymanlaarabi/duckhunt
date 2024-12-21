/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/
#include <stddef.h>
#include "../include/mylist.h"


linked_list_t *my_find_node(
    linked_list_t const *begin,
    void const *data_ref,
    int (*cmp)(void *, const void *)
)
{
    while (begin != NULL) {
        if (cmp(begin->data, data_ref) == 0)
            return begin->data;
        begin = begin->next;
    }
    return NULL;
}
