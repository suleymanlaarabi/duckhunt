/*
** EPITECH PROJECT, 2024
** file_listing
** File description:
** some description
*/

#include "../include/mylist.h"
#include <stddef.h>

void my_sort_list(linked_list_t *list, int (*cmp)(void *, void *))
{
    linked_list_t *temp = list;
    void *temp_p = NULL;
    int sorted = 0;

    while (temp != NULL && temp->next != NULL) {
        if (cmp(temp->data, temp->next->data) > 0) {
            temp_p = temp->data;
            temp->data = temp->next->data;
            temp->next->data = temp_p;
            sorted = 1;
        }
        temp = temp->next;
    }
    if (sorted == 1) {
        my_sort_list(list, cmp);
    }
}
