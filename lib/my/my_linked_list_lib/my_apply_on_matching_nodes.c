/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

int my_apply_on_matching_nodes(
    linked_list_t *begin,
    int (*f)(void *),
    void const *data_ref,
    int (*cmp)(void *, const void *)
)
{
    linked_list_t *temp = begin;

    while (temp != NULL) {
        if (cmp(temp->data, data_ref) == 0)
            f(temp->data);
        temp = temp->next;
    }
    return 0;
}
