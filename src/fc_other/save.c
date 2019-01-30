/*
** EPITECH PROJECT, 2019
** save.c
** File description:
** save.c
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

void save(t_score *list)
{
    int fichier = open("score/score", O_WRONLY);
    int lenght;

    while (list != NULL) {
        lenght = my_strlen(list->name);
        write(fichier, list->name, lenght);
        while (lenght != 11) {
            write(fichier, " ", 1);
            lenght++;
        }
        write(fichier, ";", 1);
        write(fichier, longtocharspe(list->score), 15);
        write(fichier, "\n", 1);
        list = list->next;
    }
    close(fichier);
}