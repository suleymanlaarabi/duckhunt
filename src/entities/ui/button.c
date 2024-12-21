/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdbool.h>
#include "entity.h"
#include "button.h"
#include "utils.h"

static void on_btn_update(entity_scene_t *content)
{
    entity_t *entity = content->entity;
    scene_t *scene = content->scene;
    button_data_t *data = entity->data;

    if (is_clicked_by_mouse(entity, scene->engine)) {
        if (data->on_click_func != NULL) {
            data->on_click_func(entity, scene, data->data);
        }
    }
}

entity_t *create_button(
    on_click_t on_click_func,
    sfTexture *texture,
    void *custom_data
)
{
    button_data_t *data = create_button_data(on_click_func, custom_data);
    entity_t *button_entity = create_entity(SPRITE_RENDER,
        &on_btn_update, data, &clear_button_data);

    sfSprite_setTexture(GET_SPRITE(button_entity), texture, false);
    return button_entity;
}

button_data_t *create_button_data(
    on_click_t on_click_func,
    void *custom_data
)
{
    button_data_t *data = malloc(sizeof(button_data_t));

    data->on_click_func = on_click_func;
    data->data = custom_data;
    return data;
}

int clear_button_data(void *data)
{
    button_data_t *button = data;

    free(button->data);
    free(button);
    return 0;
}
