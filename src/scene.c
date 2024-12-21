/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "scene.h"
#include "entity.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdarg.h>
#include <stdlib.h>

scene_t *create_scene(
    engine_t *engine
)
{
    scene_t *scene = malloc(sizeof(scene_t));

    scene->engine = engine;
    scene->background = NULL;
    scene->entities = NULL;
    scene->state = NULL;
    scene->clear_func = NULL;
    return scene;
}

int clear_scene(scene_t *scene)
{
    clean_list_custom(scene->entities, CAST_LIST_FUNC &clear_entity);
    if (scene->background != NULL) {
        sfTexture_destroy((void *) sfSprite_getTexture(scene->background));
        sfSprite_destroy(scene->background);
    }
    if (scene->clear_func != NULL)
        scene->clear_func(scene->state);
    free(scene);
    return 0;
}

void add_entities(
    scene_t *scene,
    ...
)
{
    entity_t *temp = NULL;
    va_list args;

    va_start(args, scene);
    temp = va_arg(args, entity_t *);
    while (temp != NULL) {
        scene->entities = push_front(scene->entities, temp);
        temp = va_arg(args, entity_t *);
    }
}

scene_t *scene_by_id(engine_t *engine, int id)
{
    linked_list_t *temp = engine->scenes;
    int i = 0;

    while (temp != NULL) {
        if (i == id)
            return temp->data;
        temp = temp->next;
        i++;
    }
    return NULL;
}
