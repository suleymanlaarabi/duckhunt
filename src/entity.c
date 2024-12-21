/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "entity.h"

entity_t *create_entity(
    render_element_t element,
    update_funct_t func,
    void *data,
    clear_data_t func_clear
)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->id = 0;
    entity->element = element;
    entity->update_func = func;
    entity->clock = sfClock_create();
    entity->data = data;
    entity->clear_data = func_clear;
    entity->destroy_delay = -1;
    return entity;
}

render_element_t render_el(
    void *element, element_type_t type
)
{
    render_element_t el;

    el.element.sprite = element;
    el.type = type;
    return el;
}

int clear_entity(entity_t *entity)
{
    clear_entity_data(entity);
    free(entity);
    return 0;
}

int clear_entity_data(entity_t *entity)
{
    if (entity->clear_data != NULL)
        entity->clear_data(entity->data);
    if (IS_SPRITE(entity)) {
        sfSprite_destroy(GET_SPRITE(entity));
    } else if (IS_TEXT(entity))
        sfText_destroy(GET_TEXT(entity));
    sfClock_destroy(entity->clock);
    return 0;
}
