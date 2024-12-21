/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

int my_apply_on_nodes(linked_list_t *begin, int(*f)(void *))
{
    linked_list_t *temp = begin;

    while (temp != NULL) {
        (*f)(temp->data);
        temp = temp->next;
    }
    return 0;
}
