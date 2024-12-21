/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdio.h>
#include "engine.h"
#include "mylist.h"
#include "window.h"
#include "scene.h"
#include "entity.h"
#include <stdlib.h>

static void update_and_draw_entity(entity_t *entity, scene_t *scene)
{
    if (entity->update_func != NULL)
        entity->update_func(&(entity_scene_t) {entity, scene});
    if (IS_SPRITE(entity)) {
        sfRenderWindow_drawSprite(WINDOW(scene), GET_SPRITE(entity), NULL);
    } else if (IS_TEXT(entity))
        sfRenderWindow_drawText(WINDOW(scene), GET_TEXT(entity), NULL);
}

static void process_destroy_delay(entity_t *entity, scene_t *scene)
{
    if (entity->destroy_delay >= 0.0)
        entity->destroy_delay -= DELTA(scene);
    if (entity->destroy_delay < 0.0 && entity->destroy_delay > -1.0)
        entity->destroy_delay = 0.0;
}

static bool should_destroy_entity(entity_t *entity)
{
    return entity->destroy_delay == 0.0;
}

static void on_update(scene_t *scene)
{
    linked_list_t *temp = scene->entities;
    entity_t *cur = NULL;
    int index = 0;

    if (scene->background)
        sfRenderWindow_drawSprite(
            scene->engine->window, scene->background, NULL);
    while (temp != NULL) {
        cur = temp->data;
        update_and_draw_entity(cur, scene);
        process_destroy_delay(cur, scene);
        temp = temp->next;
        if (should_destroy_entity(cur)) {
            scene->entities = delete_node_index(scene->entities, index);
            clear_entity(cur);
            index--;
        }
        index++;
    }
}

static void refresh_scene(engine_t *engine)
{
    linked_list_t *temp = engine->scenes;
    int i = 0;

    while (temp != NULL) {
        if (engine->refresh_scene == i) {
            clear_scene(temp->data);
            temp->data = engine->refresh(engine);
        }
        temp = temp->next;
        i += 1;
    }
    engine->refresh_scene = -1;
}

static void update_mouse_pos(engine_t *engine)
{
    sfVector2u window_size = sfRenderWindow_getSize(engine->window);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->window);
    float scale_x = 1920.0f / window_size.x;
    float scale_y = 1080.0f / window_size.y;

    engine->mp.x = mouse_pos.x * scale_x;
    engine->mp.y = mouse_pos.y * scale_y;
}

void loop(engine_t *engine)
{
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(engine->window)) {
        engine->delta = sfTime_asSeconds(sfClock_restart(clock));
        update_mouse_pos(engine);
        handle_window_event(engine->window);
        sfRenderWindow_clear(engine->window, sfBlack);
        on_update(scene_by_id(engine, engine->current_scene));
        sfRenderWindow_display(engine->window);
        if (engine->refresh_scene != -1)
            refresh_scene(engine);
    }
    sfClock_destroy(clock);
}
