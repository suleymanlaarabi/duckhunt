/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __ASSET__
    #define __ASSET__
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #define SET_TEXTURE(i, p) server->i = sfTexture_createFromFile(p, NULL)
    #define SET_MUSIC(id, path) server->id = sfMusic_createFromFile(path)
    #define SET_FONT(id, path) server->id = sfFont_createFromFile(path)

typedef struct {
    sfTexture *feather;
    sfTexture **duck_texture;
    sfTexture **duck_destroy;
    sfTexture **background_texture;
    sfTexture *btn;
    sfFont *font;
    sfTexture *exit_button;
    sfMusic *explode_sound;
    sfMusic *default_music;
    sfTexture *icon_music_off;
    sfTexture *icon_music_on;
    sfTexture *container;
    sfTexture *container_title;
    sfTexture *heart;
    sfTexture **angel_duck;
    sfTexture **angel_destroy;
    sfMusic *shop_sound;
    sfMusic *no_no_no;
    sfTexture *animated_duck;
} assets_server_t;

assets_server_t *create_asset_server(void);
void clear_duck_asset(
    assets_server_t *server
);
void clear_asset_server(assets_server_t *server);
assets_server_t *init_asset_server(void);
sfTexture **load_duck_asset(void);
sfTexture **load_duck_destroy_asset(void);
sfTexture **load_angel_asset(void);
sfTexture **load_angel_destroy_asset(void);
void clear_angel_asset(
    assets_server_t *server
);
#endif
