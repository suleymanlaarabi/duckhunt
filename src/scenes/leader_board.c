/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "scene.h"
#include "ui.h"
#include <SFML/System.h>

scene_t *init_leader_board_ui_scene(
    engine_t *engine
)
{
    scene_t *scene = create_scene(engine);
    entity_t *exit_button = create_exit_button(engine);

    PUSH(scene, exit_button);
    return scene;
}
