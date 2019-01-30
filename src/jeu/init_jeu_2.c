/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** init.c
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

all *init4_1(all *everything)
{
    everything->scoreimage = create_object
    ("ressource/score.png", create_vect(40, 54)
    , create_rect(0, 0, 186, 55), create_speed(0, 0));
    everything->pillar = create_object
    ("ressource/pillar.png", create_vect(2025, 670)
    , create_rect(0, 0, 75, 150), create_speed
    (everything->veg->speed.x * 8, 0));
    everything->monster = create_object
    ("ressource/montre.png", create_vect(2250, 704)
    , create_rect(0, 0, 65, 42), create_speed
    (everything->veg->speed.x * 8 - 3, 0));
    return (everything);
}

all *init4(all *everything)
{
    everything = init4_1(everything);
    everything->spike = create_object
    ("ressource/spike2.png", create_vect(750, 745)
    , create_rect(0, 0, 75, 80), create_speed(everything->veg->speed.x * 8, 0));
    everything->pauseback = create_object
    ("ressource/background pause.png", create_vect(0, 0)
    , create_rect(0, 0, 1920, 1002), create_speed(0, 0));
    everything->pass = 0;
    everything->pillar_m = NULL;
    everything->longeur_parcourue = 0;
    everything->exit = 0;
    return (everything);
}