/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include "scene.h"
#include "default_scene.h"
#include "utils.h"
#include "button.h"
#include "entity.h"
#include <SFML/System.h>
#include "animated_duck.h"

scene_t *init_start_ui_scene(
    engine_t *engine
)
{
    scene_t *scene = create_scene(engine);
    entity_t *text = TEXT("reset");

    pos_sca(text, VECF(900, 1005), VECF(1.5, 1.5));
    view_button(scene, 1, VECF(700, 400), "Play");
    view_button(scene, 2, VECF(950, 540), "Settings");
    view_button(scene, 3, VECF(700, 680), "Shop");
    view_button(scene, 4, VECF(450, 540), "Leaderboard");
    feather_display(engine, scene);
    scene->background = sprite_texture_scale(
        "assets/ui_background.png", (sfVector2f) {1.1, 1.1});
    add_entities(scene,
        text, create_animated_duck(scene, VECF(500, 390)),
        create_animated_duck(scene, VECF(1400, 390)),
    0);
    return scene;
}
