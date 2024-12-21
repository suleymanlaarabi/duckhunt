/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "scene.h"
#include "utils.h"
#include "ui.h"
#include "settings_service.h"
#include "button.h"
#include "my.h"
#include <SFML/System.h>
#include <stdlib.h>

static void clear_settings(void *data)
{
    free(data);
}

static void size_button(entity_t *entity, scene_t *scene, void *data)
{
    int size = *((int *)data);

    UNUSED(entity);
    if (size == 1)
        sfRenderWindow_setSize(WINDOW(scene), (sfVector2u) {1920, 1080});
    if (size == 2)
        sfRenderWindow_setSize(WINDOW(scene), (sfVector2u) {1280, 720});
    if (size == 3)
        sfRenderWindow_setSize(WINDOW(scene), (sfVector2u) {800, 600});
}

static void create_sized_button(int value, scene_t *scene)
{
    int *size = malloc(sizeof(int));
    entity_t *btn = create_button(
        &size_button, ASSET_SERVER(scene)->btn, size);
    entity_t *text = NULL;

    if (value == 1)
        text = TEXT("1920x1080");
    if (value == 2)
        text = TEXT("1280x720");
    if (value == 3)
        text = TEXT("800x600");
    pos_sca(text, VECF(400 * (value - 1) + 70, 415), VECF(1.5, 1.5));
    pos_sca(btn, VECF(400 * (value - 1), 400), VECF(0.5, 0.5));
    *size = value;
    PUSH(scene, text);
    PUSH(scene, btn);
}

static void window_size_buttons(scene_t *scene)
{
    create_sized_button(1, scene);
    create_sized_button(2, scene);
    create_sized_button(3, scene);
}

scene_t *init_settings_ui_scene(
    engine_t *engine
)
{
    scene_t *scene = create_scene(engine);
    entity_t *exit_button = create_exit_button(engine);
    entity_t *sound_button = NULL;

    scene->clear_func = &clear_settings;
    scene->state = load_settings();
    sound_button = mute_button(engine, scene);
    scene->background = sprite_texture_scale(
        "assets/ui_background.png", (sfVector2f) {1.1, 1.1});
    PUSH(scene, sound_button);
    PUSH(scene, exit_button);
    window_size_buttons(scene);
    return scene;
}
