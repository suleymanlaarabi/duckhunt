/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stdlib.h>


void clean_list(linked_list_t *list)
{
    linked_list_t *old;

    while (list != NULL) {
        old = list;
        list = list->next;
        free(old);
    }
}

void clean_list_custom(linked_list_t *list, int (*fn_clean)(void *))
{
    linked_list_t *old;

    while (list != NULL) {
        old = list;
        list = list->next;
        fn_clean(old->data);
        free(old);
    }
}

linked_list_t *delete_node_index(linked_list_t *list, int index)
{
    linked_list_t *current = list;
    linked_list_t *node_to_delete = NULL;
    int i = 0;

    if (index == 0) {
        current = list->next;
        free(list);
        return current;
    }
    while (current != NULL && current->next != NULL) {
        if (i == index - 1) {
            node_to_delete = current->next;
            current->next = node_to_delete->next;
            free(node_to_delete);
            return list;
        }
        current = current->next;
        i++;
    }
    return list;
}
