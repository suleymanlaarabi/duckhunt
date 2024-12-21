/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "entity.h"
#include "button.h"
#include "my.h"

static void on_button_exit_click(entity_t *entity, scene_t *scene, void *data)
{
    UNUSED(data);
    UNUSED(entity);
    scene->engine->current_scene = 0;
}

entity_t *create_exit_button(engine_t *engine)
{
    entity_t *button = create_button(
        &on_button_exit_click,
        engine->assets_server->exit_button, NULL);

    SCA(button, 0.5, 0.5);
    POS(button, 25, 20);
    return button;
}
