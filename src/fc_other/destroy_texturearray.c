/*
** EPITECH PROJECT, 2019
** destroy_texturearray.c
** File description:
** destroy_texturearray.c
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

void destroy_texturearray(int nb, sfTexture **texture)
{
    int count = 0;

    while (nb > count) {
        sfTexture_destroy(texture[count]);
        count++;
    }
}