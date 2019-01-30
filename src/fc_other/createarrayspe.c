/*
** EPITECH PROJECT, 2019
** createarrayspe.c
** File description:
** createarrayspe.c
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

char *createarrayspe(char *nb)
{
    int temp = 0;

    nb = malloc(sizeof(char) * 15 + 1);
    nb[15] = '\0';
    while (temp < 15) {
        nb[temp] = 48;
        temp++;
    }
    return (nb);
}