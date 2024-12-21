/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdbool.h>
#include "entity.h"
#include "utils.h"
#include "duck.h"
#include "default_scene.h"

static void on_update(entity_scene_t *content)
{
    entity_t *entity = content->entity;
    scene_t *scene = content->scene;
    default_scene_t *state = scene->state;
    float x_pos = 0;
    int number = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(entity->clock)) <= 0.8)
        return;
    number = random_between(1, 1);
    sfClock_restart(entity->clock);
    for (int i = 0; i < number; i++) {
        x_pos = random_between(0, 1950);
        PUSH(scene,
            create_duck(
                VECF(x_pos, random_between(1005, 1090)),
                ASSET_SERVER(scene)->duck_texture,
                state
            )
        );
    }
}

entity_t *duck_management(void)
{
    entity_t *entity = create_entity(
        NO_RENDER, &on_update, NULL, NULL);

    return entity;
}
