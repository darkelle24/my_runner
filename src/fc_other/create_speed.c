/*
** EPITECH PROJECT, 2019
** create_speed.c
** File description:
** create_speed.c
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

speed_t create_speed(float x, float y)
{
    speed_t speed;

    speed.x = x;
    speed.y = y;
    return (speed);
}