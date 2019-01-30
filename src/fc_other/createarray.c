/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create.c
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

char *createarray(char *nb, int i)
{
    int temp = 0;

    nb = malloc(sizeof(char) * i + 1);
    nb[i] = '\0';
    return (nb);
}