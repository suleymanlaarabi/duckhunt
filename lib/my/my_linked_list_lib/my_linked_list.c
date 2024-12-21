/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "../include/mylist.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

linked_list_t *push_back(linked_list_t *list, void *el)
{
    linked_list_t *list_el = malloc(sizeof(linked_list_t));
    linked_list_t *old = list;

    list_el->data = el;
    list_el->next = NULL;
    if (list_is_empty(list))
        return list_el;
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = list_el;
    return old;
}

linked_list_t *push_front(linked_list_t *list, void *el)
{
    linked_list_t *list_el = malloc(sizeof(linked_list_t));

    list_el->data = el;
    list_el->next = list;
    return list_el;
}

linked_list_t *push_front_all(linked_list_t *list, int count, ...)
{
    va_list args;
    linked_list_t *new_elem;
    void *el;

    va_start(args, count);
    for (int i = 0; i < count; i++) {
        el = va_arg(args, void *);
        new_elem = malloc(sizeof(linked_list_t));
        if (!new_elem)
            return NULL;
        new_elem->data = el;
        new_elem->next = list;
        list = new_elem;
    }
    va_end(args);
    return list;
}

short list_is_empty(linked_list_t const *list)
{
    if (list == NULL)
        return 1;
    return 0;
}

linked_list_t *get_list_index(linked_list_t *begin, int index)
{
    int current_index = 0;

    if (list_is_empty(begin))
        return NULL;
    while (begin != NULL) {
        if (current_index == index)
            return begin;
        begin = begin->next;
        current_index++;
    }
    return NULL;
}
