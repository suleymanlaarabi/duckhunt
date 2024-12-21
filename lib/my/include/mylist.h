/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __MY_LIST__
    #define __MY_LIST__
    #define CAST_LIST_FUNC (int (*)(void *))

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

void clean_list(linked_list_t *list);
short list_is_empty(linked_list_t const *list);
int my_list_size(linked_list_t const *begin);
linked_list_t *get_list_index(linked_list_t *begin, int index);
linked_list_t *push_back(linked_list_t *list, void *el);
linked_list_t *push_front(linked_list_t *list, void *el);
linked_list_t *my_params_to_list(int ac, char *const *av);
int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *));
int my_apply_on_matching_nodes(
    linked_list_t *begin,
    int (*f)(void *),
    void const *data_ref,
    int (*cmp)(void *, const void *));
linked_list_t *my_find_node(
    linked_list_t const *begin,
    void const *data_ref,
    int (*cmp)(void *, const void *));
void my_rev_list(linked_list_t **begin);
linked_list_t *set_list_index(
    linked_list_t *list,
    linked_list_t *el,
    int index);
int my_delete_nodes(
    linked_list_t **begin,
    void const *data_ref,
    int (*cmp)(void *, const void *));
linked_list_t *delete_node_index(linked_list_t *list, int index);
void clean_list_custom(linked_list_t *list, int (*fn_clean)(void *));
void my_sort_list(linked_list_t *list, int (*cmp)(void *, void *));
linked_list_t *push_front_all(linked_list_t *list, int count, ...);
linked_list_t *remove_node(linked_list_t *list, void *target);

#endif
