/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen.c
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

int my_strlen(char const *str)
{
    int nbchar;

    nbchar = 0;
    while ( *str != '\0') {
        nbchar++;
        str++;
    }
    return (nbchar);
}