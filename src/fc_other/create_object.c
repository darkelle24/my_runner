/*
** EPITECH PROJECT, 2019
** create_object.c
** File description:
** create_object.c
*/

#include <SFML/Graphics.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio.h>
#include "../../include/my.h"

game_object *create_object(const char *path_to_spritesheet,
sfVector2f pos, sfIntRect rect, speed_t speed)
{
    game_object *object = malloc(sizeof(game_object));

    object->Sprite = sfSprite_create();
    if (path_to_spritesheet != NULL) {
        object->Texture = sfTexture_createFromFile(path_to_spritesheet, &rect);
        if (!object->Texture)
            return NULL;
        sfSprite_setTexture(object->Sprite, object->Texture, sfTrue);
    }
    object->Position = pos;
    sfSprite_setPosition(object->Sprite, pos);
    object->speed = speed;
    object->Rect = rect;
    return (object);
}