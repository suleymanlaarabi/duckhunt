/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "scene.h"
#include "default_scene.h"
#include "entity.h"
#include "utils.h"
#include "my.h"
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

static void display_score(entity_scene_t *content)
{
    default_scene_t *state = scene_by_id(content->scene->engine, 1)->state;
    char *v = int_to_str(state->score);

    sfText_setString(GET_TEXT(content->entity), v);
    free(v);
}

entity_t *score_display(engine_t *engine, scene_t *scene)
{
    entity_t *score = create_entity(TEXT_RENDER("0", engine),
        &display_score, NULL, NULL);

    add_entities(scene, score, NULL);
    pos_sca(score, VECF(200, 10), VECF(3.5, 3.5));
    return score;
}
