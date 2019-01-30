/*
** EPITECH PROJECT, 2019
** create_rect.c
** File description:
** create_rect.c
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

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rectangle;

    rectangle.top = top;
    rectangle.left = left;
    rectangle.height = height;
    rectangle.width = width;
    return (rectangle);
}