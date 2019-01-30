/*
** EPITECH PROJECT, 2019
** color.c
** File description:
** color.
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

sfColor degrade_color(colordegrade *coloradd, sfColor actuelle, sfText *text)
{
    actuelle.r += coloradd->degrade.r * coloradd->sensr;
    actuelle.b += coloradd->degrade.b * coloradd->sensb;
    actuelle.g += coloradd->degrade.g * coloradd->sensg;
    actuelle.a += coloradd->degrade.a * coloradd->sensa;
    degrade_color_basse(coloradd, actuelle);
    degrade_color_haute(coloradd, actuelle);
    sfText_setColor(text, actuelle);
    return (actuelle);
}

sfColor create_color(int r, int b, int g, int a)
{
    sfColor color;

    color.r = r;
    color.b = b;
    color.g = g;
    color.a = a;
    return (color);
}

colordegrade create_degrade(sfColor color, colordegradsens_t sens)
{
    colordegrade colordeg;

    colordeg.degrade = color;
    colordeg.sensr = sens.sensr;
    colordeg.sensb = sens.sensb;
    colordeg.sensg = sens.sensg;
    colordeg.sensa = sens.sensa;
    return (colordeg);
}

colordegradsens_t create_sensdregrad(int sensr, int sensb, int sensg, int sensa)
{
    colordegradsens_t colordsens;

    colordsens.sensr = sensr;
    colordsens.sensb = sensb;
    colordsens.sensg = sensg;
    colordsens.sensa = sensa;
    return (colordsens);
}