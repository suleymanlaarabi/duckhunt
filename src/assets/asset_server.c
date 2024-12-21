/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "assets.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

static void load_first_part(assets_server_t *server)
{
    SET_TEXTURE(animated_duck, "assets/ducks.png");
    SET_TEXTURE(heart, "assets/ui/Icon_Heart.png");
    SET_TEXTURE(container, "assets/ui/Item3.png");
    SET_TEXTURE(container_title, "assets/ui/Item4.png");
    SET_TEXTURE(feather, "assets/duck/feather.png");
    SET_TEXTURE(icon_music_off, "assets/ui/Icon_MusicOff.png");
    SET_TEXTURE(icon_music_on, "assets/ui/Icon_MusicOn.png");
    SET_MUSIC(default_music, "assets/sound/default.mp3");
}

assets_server_t *init_asset_server(void)
{
    assets_server_t *server = malloc(sizeof(assets_server_t));

    load_first_part(server);
    SET_MUSIC(no_no_no, "assets/sound/no.wav");
    SET_MUSIC(explode_sound, "assets/sound/bird_explode.mp3");
    SET_MUSIC(shop_sound, "assets/sound/shop.wav");
    SET_FONT(font, "assets/font/asman.ttf");
    SET_TEXTURE(btn, "assets/ui/Item5.png");
    SET_TEXTURE(exit_button, "assets/ui/Icon_Exit.png");
    server->duck_texture = load_duck_asset();
    server->duck_destroy = load_duck_destroy_asset();
    server->angel_duck = load_angel_asset();
    server->angel_destroy = load_angel_destroy_asset();
    return server;
}

static void destroy_first_part(assets_server_t *server)
{
    sfMusic_destroy(server->shop_sound);
    clear_angel_asset(server);
    sfTexture_destroy(server->heart);
    sfTexture_destroy(server->container_title);
    sfTexture_destroy(server->container);
    sfTexture_destroy(server->feather);
    sfMusic_destroy(server->explode_sound);
    sfMusic_destroy(server->default_music);
    sfFont_destroy(server->font);
}

void clear_asset_server(assets_server_t *server)
{
    destroy_first_part(server);
    sfTexture_destroy(server->animated_duck);
    sfMusic_destroy(server->no_no_no);
    sfTexture_destroy(server->btn);
    sfTexture_destroy(server->exit_button);
    sfTexture_destroy(server->icon_music_on);
    sfTexture_destroy(server->icon_music_off);
    clear_duck_asset(server);
    free(server);
}
