/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include "scene.h"
#include <fcntl.h>
#include "default_scene.h"
#include "utils.h"
#include "inventory_service.h"

static void update_life_render(
    linked_list_t *entities,
    default_scene_t *state,
    entity_scene_t *content
)
{
    entity_t *temp = NULL;
    entity_t *entity = NULL;

    if (my_list_size(entities) > state->life) {
        temp = entities->data;
        temp->destroy_delay = 0.0;
    }
    if (my_list_size(entities) < state->life) {
        for (int i = my_list_size(entities); i < state->life; i++) {
            entity = img(SPRITE_RENDER, ASSET_SERVER(content->scene)->heart,
                VECF(1100 - (i * 100), 30), VECF(.4, 0.4));
            entity->id = 2;
            content->scene->entities = push_back(
                content->scene->entities, entity);
        }
    }
}

static void on_life_update(entity_scene_t *content)
{
    default_scene_t *state = content->scene->state;
    linked_list_t *entities = fetch_entities_by_id(content->scene, 2);

    update_life_render(entities, state, content);
    if (state->life <= 0) {
        content->scene->engine->current_scene = 0;
        content->scene->engine->refresh_scene = 1;
        content->scene->engine->refresh = (void *) &init_default_scene;
        state->life = state->player_life;
        state->score = 0;
        save_inventory(state);
    }
    clean_list(entities);
}

void life_render(scene_t *scene)
{
    default_scene_t *data = scene->state;
    entity_t *entity = NULL;
    entity_t *manager = create_entity(NO_RENDER, &on_life_update, NULL, NULL);

    for (int i = 0; i < data->life; i++) {
        entity = img(SPRITE_RENDER, ASSET_SERVER(scene)->heart,
            VECF(1100 - (i * 100), 30), VECF(.4, 0.4));
        entity->id = 2;
        PUSH(scene, entity);
    }
    PUSH(scene, manager);
}
