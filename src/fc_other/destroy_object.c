/*
** EPITECH PROJECT, 2019
** destroy_object.c
** File description:
** destroy_object.c
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

void destroy_object(game_object *obj, int nb, sfTexture **texture)
{
    int count = 0;

    if (nb > 1) {
        while (nb > count) {
            sfTexture_destroy(texture[count]);
            count++;
        }
    }
    sfSprite_destroy(obj->Sprite);
    free(obj);
}