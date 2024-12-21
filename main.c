/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "assets.h"
#include "engine.h"
#include "game_loop.h"
#include "my.h"
#include "scene.h"
#include "engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int handle_help(int argc, char **argv)
{
    if (argc > 1 && argv[1][0] == '-' && argv[1][01] == 'h') {
        my_putstr("USAGE: ./my_hunter\n");
        my_putstr("JUST run the binary and enjoy\n\n");
        my_putstr("INFO:\n");
        my_putstr(
            "ensure the config dir has inventory.conf and settings.conf\n");
        return 1;
    }
    return 0;
}

static int ensure_display_available(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'D' && env[i][1] == 'I' && env[i][2] == 'S') {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    assets_server_t *server = NULL;
    engine_t *engine = NULL;

    if (handle_help(argc, argv) == 1)
        return 0;
    if (!ensure_display_available(env))
        return 84;
    server = init_asset_server();
    engine = init_game_engine(server);
    srand(time(NULL));
    push_scene(engine, init_leader_board_ui_scene(engine));
    push_scene(engine, shop_scene(engine));
    push_scene(engine, init_settings_ui_scene(engine));
    push_scene(engine, init_default_scene(engine));
    push_scene(engine, init_start_ui_scene(engine));
    loop(engine);
    clear_game_engine(engine);
}
