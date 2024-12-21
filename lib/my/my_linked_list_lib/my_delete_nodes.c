/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>


int my_delete_nodes(
    linked_list_t **begin,
    void const *data_ref,
    int (*cmp)(void *, const void *)
)
{
    linked_list_t *temp = *begin;
    int i = 0;

    while (temp != NULL) {
        if (cmp(temp->data, data_ref) == 0) {
            temp = temp->next;
            *begin = delete_node_index(*begin, i);
            i++;
            continue;
        }
        i++;
        temp = temp->next;
    }
    return 0;
}
