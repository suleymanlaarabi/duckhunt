/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#ifndef __SETTINGS_SERVICE__
    #define __SETTINGS_SERVICE__
    #include <SFML/Graphics.h>

typedef struct {
    sfBool is_mute;
} settings_t;

settings_t *load_settings(void);

void save_settings(settings_t *settings);

#endif
