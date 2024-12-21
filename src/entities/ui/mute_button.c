/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "entity.h"
#include "button.h"
#include "settings_service.h"
#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

static void mute_on_click(entity_t *entity, scene_t *scene, void *data)
{
    settings_t *settings = scene->state;

    UNUSED(data);
    if (!settings->is_mute) {
        sfMusic_pause(ASSET_SERVER(scene)->default_music);
        sfSprite_setTexture(
            SPRITE(entity), ASSET_SERVER(scene)->icon_music_off, sfTrue);
        settings->is_mute = sfTrue;
    } else {
        sfMusic_play(ASSET_SERVER(scene)->default_music);
        sfSprite_setTexture(
            SPRITE(entity), ASSET_SERVER(scene)->icon_music_on, sfTrue);
        settings->is_mute = sfFalse;
    }
    save_settings(settings);
}

entity_t *mute_button(engine_t *engine, scene_t *scene)
{
    entity_t *button = NULL;
    settings_t *settings = scene->state;

    if (settings->is_mute) {
        button = create_button(
            &mute_on_click, engine->assets_server->icon_music_off, NULL);
    } else {
        button = create_button(
            &mute_on_click, engine->assets_server->icon_music_on, NULL);
        sfMusic_play(ASSET_SERVER(scene)->default_music);
        sfMusic_setLoop(ASSET_SERVER(scene)->default_music, sfTrue);
    }
    POS(button, 25, 200);
    SCA(button, 0.6, 0.6);
    return button;
}
