/*
** EPITECH PROJECT, 2019
** longtochar.c
** File description:
** longtochar.c
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

char *longtocharspe(long long nblist)
{
    int i = 0;
    long long temp = nblist;
    char *nb;

    while (temp != 0) {
        temp = temp / 10;
        i++;
    }
    nb = createarrayspe(nb);
    temp = 0;
    while (temp < i) {
        nb[14 - temp] = nblist % 10 + 48;
        nblist = nblist / 10;
        temp++;
    }
    return (nb);
}