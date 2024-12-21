/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include "entity.h"
#include "animated_duck.h"
#include "utils.h"

static animated_duck_t *create_data(void)
{
    animated_duck_t *data = malloc(sizeof(animated_duck_t));

    data->current_frame = 0;
    return data;
}

static void on_update(entity_scene_t *content)
{
    animated_duck_t *data = content->entity->data;

    if (TIME(content->entity) < 0.2)
        return;
    sfClock_restart(content->entity->clock);
    if (data->current_frame >= 2) {
        data->current_frame = 0;
    } else
        data->current_frame += 1;
    sfSprite_setTextureRect(GET_SPRITE(content->entity),
        (sfIntRect){data->current_frame * 110, 0, 110, 110});
}

entity_t *create_animated_duck(scene_t *scene, sfVector2f pos)
{
    entity_t *entity = create_entity(
        SPRITE_RENDER,
        &on_update,
        create_data(),
        (void(*)) &free
    );

    if (pos.x >= 1200.0) {
        flip_sprite(GET_SPRITE(entity));
    }
    sfSprite_setTexture(
        GET_SPRITE(entity), ASSET_SERVER(scene)->animated_duck, sfTrue);
    POS(entity, pos.x, pos.y);
    return entity;
}
