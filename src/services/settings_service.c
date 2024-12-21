/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <SFML/Config.h>
#include <stddef.h>
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include "settings_service.h"
#include "file_service.h"

settings_t *load_settings(void)
{
    settings_t *settings = load_struct(
        "./config/settings.conf", sizeof(settings_t));

    return settings;
}

void save_settings(settings_t *settings)
{
    save_struct(settings, "./config/settings.conf", sizeof(settings_t));
}
