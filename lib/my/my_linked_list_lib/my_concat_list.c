/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *temp = *begin1;

    if (list_is_empty(*begin1)) {
        *begin1 = begin2;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = begin2;
}
