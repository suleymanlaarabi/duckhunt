/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "entity.h"
#include "button.h"
#include "utils.h"
#include "my.h"
#include <SFML/System.h>
#include <stdlib.h>

static void on_click_view(entity_t *entity, scene_t *scene, void *data)
{
    UNUSED(entity);
    scene->engine->current_scene = *((int *)data);
}

void view_button(
    scene_t *scene,
    int scene_id,
    sfVector2f pos,
    char const *title
)
{
    int *id = malloc(sizeof(int));
    entity_t *btn = create_button(&on_click_view,
        GET_TEXTURE(scene, btn), id);
    entity_t *btn_text = create_entity(render_el(
        create_texte(title, scene->engine),
        TEXT), NULL, NULL, NULL);
    float len = my_strlen(title);

    *id = scene_id;
    pos_sca(btn, pos, VECF(0.7, 0.7));
    sfText_setPosition(GET_TEXT(btn_text),
        (sfVector2f) {(pos.x + -10 * len) + 260, pos.y + 33});
    PUSH(scene, btn_text);
    PUSH(scene, btn);
}
