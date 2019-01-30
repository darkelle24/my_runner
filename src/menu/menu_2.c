/*
** EPITECH PROJECT, 2019
** menu.c
** File description:
** menu.c
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

menu_s *initmenu()
{
    menu_s *menuvar = malloc(sizeof(menu_s));

    menuvar->window = create_windows(1920, 1080, 32);
    menuvar->list = lecturescore();
    menuvar->menu = create_object("ressource/menu.png", create_vect(0, 0)
    , create_rect(0, 0, 1920, 1080), create_speed(0, 0));
    menuvar->font = sfFont_createFromFile("ressource/DejaVuSansMono.ttf");
    menuvar->color = create_color(255, 0, 255, 255);
    menuvar->degrade = create_degrade(create_color(10, 0, 10, 0)
    , create_sensdregrad(-1, 1, -1, 1));
    return (menuvar);
}