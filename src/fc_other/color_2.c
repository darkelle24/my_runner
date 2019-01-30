/*
** EPITECH PROJECT, 2019
** color.c
** File description:
** color.c
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

sfColor degrade_color_basse(colordegrade *coloradd, sfColor actuelle)
{
    if (actuelle.r <= 0) {
        actuelle.r = 0;
        coloradd->sensr = 1;
    }
    if (actuelle.g <= 0) {
        actuelle.g = 0;
        coloradd->sensg = 1;
    }
    if (actuelle.b <= 0) {
        actuelle.b = 0;
        coloradd->sensb = 1;
    }
    if (actuelle.a <= 0) {
        actuelle.a = 0;
        coloradd->sensa = 1;
    }
    return (actuelle);
}

sfColor degrade_color_haute(colordegrade *coloradd, sfColor actuelle)
{
    if (actuelle.r >= 255) {
        actuelle.r = 255;
        coloradd->sensr = -1;
    }
    if (actuelle.g >= 255) {
        actuelle.g = 255;
        coloradd->sensg = -1;
    }
    if (actuelle.b >= 255) {
        actuelle.b = 255;
        coloradd->sensb = -1;
    }
    if (actuelle.a >= 255) {
        actuelle.a = 255;
        coloradd->sensa = -1;
    }
    return (actuelle);
}