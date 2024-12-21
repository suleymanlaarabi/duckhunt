/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    int len = my_list_size(*begin) - 1;
    linked_list_t *temp = get_list_index(*begin, len);
    linked_list_t *first = *begin;

    for (int i = len; i > 0; i--) {
        get_list_index(*begin, i)->next = get_list_index(*begin, i - 1);
    }
    first->next = NULL;
    *begin = temp;
}
