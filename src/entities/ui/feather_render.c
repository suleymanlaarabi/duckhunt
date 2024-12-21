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

static void display_feather(entity_scene_t *content)
{
    default_scene_t *state = scene_by_id(content->scene->engine, 1)->state;
    char *v = int_to_str(state->feather);

    sfText_setString(GET_TEXT(content->entity), v);
    free(v);
}

entity_t *feather_display(engine_t *engine, scene_t *scene)
{
    entity_t *feather = create_entity(TEXT_RENDER("0", engine),
        &display_feather, NULL, NULL);
    entity_t *img = create_entity(SPRITE_RENDER, NULL, NULL, NULL);

    APPLY_TEXTURE(GET_SPRITE(img), ASSET_SERVER(scene)->feather);
    add_entities(scene, feather, img, NULL);
    pos_sca(img, VECF(1770, 17), VECF(0.2, 0.2));
    pos_sca(feather, VECF(1510, 10), VECF(3.5, 3.5));
    return feather;
}
