/*
** EPITECH PROJECT, 2019
** calcul.c
** File description:
** calcul.c
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

int calcultemp(int timeanim, float jump, float g, int nbimage)
{
    int timeacalculer = 0;

    timeanim = 16666;
    while (jump > 0) {
        jump -= g;
        timeacalculer += timeanim;
    }
    timeacalculer = timeacalculer / nbimage;
    return (timeacalculer);
}