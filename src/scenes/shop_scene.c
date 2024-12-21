/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "engine.h"
#include "scene.h"
#include "shop_scene.h"
#include "default_scene.h"
#include "ui.h"
#include "my.h"

static item_t *create_item(
    char *name,
    int price,
    sfVector2f scale,
    sfTexture *texture
)
{
    item_t *item = malloc(sizeof(item_t));

    item->scale = scale;
    item->price = price;
    item->name = name;
    item->price_multiplyer = 2;
    item->texture = texture;
    return item;
}

static shop_data_t *init_shop_data(scene_t *scene)
{
    shop_data_t *data = malloc(sizeof(shop_data_t));

    data->items = push_front(
        NULL, create_item(my_strdup("Life"),
            275, VECF(0.6, 0.6), ASSET_SERVER(scene)->heart));
    data->items = push_front(
        data->items, create_item(my_strdup("Angel Duck"),
            2100, VECF(0.2, 0.2), *ASSET_SERVER(scene)->angel_duck));
    return data;
}

static void render_items(scene_t *scene, linked_list_t *items)
{
    linked_list_t *temp = items;
    int i = 150;
    item_t *item = NULL;

    while (temp != NULL) {
        item = temp->data;
        item_card(scene, VECF(i, 10), item);
        temp = temp->next;
        i += 400;
    }
}

static int clean_item(item_t *item)
{
    free(item->name);
    free(item);
    return 0;
}

static void clean_shop_data(void *data)
{
    shop_data_t *state = data;

    if (data == NULL)
        return;
    clean_list_custom(state->items, CAST_LIST_FUNC &clean_item);
    free(data);
}

scene_t *shop_scene(engine_t *engine)
{
    scene_t *scene = create_scene(engine);
    entity_t *exit_btn = create_exit_button(engine);

    scene->state = init_shop_data(scene);
    scene->clear_func = &clean_shop_data;
    render_items(scene, ((shop_data_t *) scene->state)->items);
    feather_display(engine, scene);
    PUSH(scene, exit_btn);
    return scene;
}
