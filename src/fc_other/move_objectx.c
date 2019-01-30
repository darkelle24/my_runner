/*
** EPITECH PROJECT, 2019
** move_object.c
** File description:
** move_object.c
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

game_object *move_objectx(game_object *obj, int startx, int endx, int spe)
{
    obj->Position.x += obj->speed.x;
    if (obj->speed.x > 0) {
        if (obj->Position.x >= endx)
            obj->Position.x = -obj->Rect.width;
    } else if (obj->speed.x < 0) {
        if (obj->Position.x <= startx) {
            obj->Position.x = endx;
            if (spe == 1) {
                obj->Position.x += + ((rand() % 10) * 75);
            }
        }
    }
    sfSprite_setPosition(obj->Sprite, obj->Position);
    return (obj);
}