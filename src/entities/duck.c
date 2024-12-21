/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include "duck.h"
#include "default_scene.h"
#include "entity.h"
#include "animation.h"
#include "utils.h"
#include "my_math.h"

static void on_duck_destroy(entity_t *duck, scene_t *scene)
{
    default_scene_t *state = scene->state;
    duck_data_t *data = duck->data;

    state->score += 1;
    state->feather += 200;
    duck->destroy_delay = 1.5;
    data->velocity = ext_vector2f(data->velocity, -0.3);
    sfMusic_play(ASSET_SERVER(scene)->explode_sound);
    set_animation(data->animation,
        (sfVector2i) {0, 9}, 0.15, ASSET_SERVER(scene)->duck_destroy);
}

static void on_update(entity_scene_t *content)
{
    entity_t *duck = content->entity;
    scene_t *scene = content->scene;
    sfVector2f position = sfSprite_getPosition(GET_SPRITE(duck));
    default_scene_t *state = scene->state;
    duck_data_t *data = duck->data;

    update_animation(data->animation, GET_SPRITE(duck));
    move_by_vec(GET_SPRITE(duck), DELTA(scene), data->velocity);
    if (position.y < -90 || position.x < -50 || position.x > 1950) {
        duck->destroy_delay = 0.0;
        state->life -= 1;
    } else if (is_clicked_by_mouse(
        duck, scene->engine) && duck->destroy_delay == -1.0) {
        on_duck_destroy(duck, scene);
    }
}

static duck_data_t *create_duck_data(
    sfVector2f pos,
    animation_t *animation,
    default_scene_t *state
)
{
    duck_data_t *data = malloc(sizeof(duck_data_t));
    double rad = 0.0;

    if (pos.x >= 910) {
        rad = RAD(random_between(200, 260));
    } else {
        rad = RAD(random_between(290, 340));
    }
    data->velocity = get_vec_from_rad(rad, state->score * 10 + 120);
    data->animation = animation;
    return data;
}

static int clear_duck_data(void *data)
{
    duck_data_t *duck = data;

    clear_animation(duck->animation);
    free(data);
    return 0;
}

entity_t *create_duck(
    sfVector2f pos,
    sfTexture **textures,
    default_scene_t *state
)
{
    sfSprite *duck = sfSprite_create();
    animation_t *animation = create_animation(
        (sfVector2i) {0, 7}, 0.1, textures);
    duck_data_t *data = create_duck_data(pos, animation, state);
    entity_t *duck_entity = create_entity(render_el(duck, SPRITE),
        &on_update, data, &clear_duck_data);

    SCA(duck_entity, 0.3, 0.3);
    sfSprite_setPosition(duck, pos);
    if (pos.x >= 910) {
        flip_sprite(duck);
    }
    return duck_entity;
}
