/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "button.h"
#include "entity.h"
#include "utils.h"
#include "shop_scene.h"
#include "default_scene.h"
#include "inventory_service.h"
#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <stdlib.h>

void apply_angel_duck(assets_server_t *server)
{
    sfTexture **temp = NULL;
    sfTexture **temp2 = NULL;

    temp = server->duck_texture;
    temp2 = server->duck_destroy;
    server->duck_texture = server->angel_duck;
    server->duck_destroy = server->angel_destroy;
    server->angel_duck = temp;
    server->angel_destroy = temp2;
}

static void handle_buy(item_t *item, default_scene_t *state, scene_t *scene)
{
    if (my_strcmp(item->name, "Life") == 0) {
        state->player_life += 1;
        state->life += 1;
    }
    if (my_strcmp(item->name, "Angel Duck") == 0) {
        apply_angel_duck(ASSET_SERVER(scene));
        state->angel_duck = sfTrue;
    }
}

static void buy(
    entity_t *entity,
    scene_t *scene,
    void *data
)
{
    item_t *item = *((void **)data);
    default_scene_t *state = scene_by_id(scene->engine, 1)->state;

    UNUSED(entity);
    if (state->feather >= item->price) {
        handle_buy(item, state, scene);
        sfMusic_play(ASSET_SERVER(scene)->shop_sound);
        state->feather -= item->price;
        save_inventory(state);
    } else {
        sfMusic_play(ASSET_SERVER(scene)->no_no_no);
    }
}

void item_card(
    scene_t *scene,
    sfVector2f p,
    item_t *item
)
{
    entity_t *title = TEXT(item->name);
    void **data = malloc(sizeof(void *));
    entity_t *btn = create_button(&buy, ASSET_SERVER(scene)->btn, data);
    entity_t *buy_txt = TEXT("Buy");
    char *to_free = int_to_str(item->price);
    entity_t *price = TEXT(to_free);

    free(to_free);
    *data = item;
    pos_sca(price, VECF(p.x + 70, p.y + 145), VECF(1.5, 1.5));
    pos_sca(btn, VECF(p.x - 40, p.y + 250), VECF(0.5, 0.5));
    pos_sca(title, VECF(p.x + 145 - (my_strlen(item->name) * 9), p.y + 207),
        VECF(1.2, 1.2));
    pos_sca(buy_txt, VECF(p.x + 105, p.y + 265), VECF(1.5, 1.5));
    add_entities(scene, img(SPRITE_RENDER, item->texture,
        VECF(p.x + 70, p.y + 15), item->scale),
        IMG(feather, p.x + 165, p.y + 145, 0.1), price, title,
        IMG(container_title, p.x - 5, p.y + 200, 0.2), buy_txt, btn,
        IMG(container, p.x, p.y, 0.3), 0);
}
