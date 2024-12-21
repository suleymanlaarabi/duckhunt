/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include "scene.h"
#include <SFML/System.h>
#include <fcntl.h>
#include <stdlib.h>
#include "default_scene.h"
#include "inventory_service.h"
#include "duck_management.h"
#include "utils.h"
#include "ui.h"

static void init_state(scene_t *scene)
{
    default_scene_t *state = load_inventory();

    scene->state = state;
}

scene_t *init_default_scene(
    engine_t *engine
)
{
    scene_t *scene = create_scene(engine);
    entity_t *exit_button = create_exit_button(engine);

    scene->clear_func = &free;
    init_state(scene);
    scene->background = sprite_texture_scale(
        "assets/background.jpg", (sfVector2f) {0.5, 0.5});
    feather_display(engine, scene);
    score_display(engine, scene);
    life_render(scene);
    add_entities(scene, exit_button, duck_management(), NULL);
    return scene;
}
