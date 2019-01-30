/*
** EPITECH PROJECT, 2019
** lecturescore.c
** File description:
** lecture.c
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

t_score *lecturescore()
{
    int fichier;
    t_score *list = NULL;
    t_score *backup;

    list = lecturescore_1(list);
    backup = list;
    fichier = open("score/score", O_RDONLY);
    list = lecturescore_2(list, fichier, 0, 0);
    close(fichier);
    list = backup;
    return (list);
}

t_score *lecturescore_1(t_score *list)
{
    t_score *element;
    int nb = 0;

    while (nb < 10) {
        element = malloc(sizeof(* element));
        element->next = list;
        element->rank = nb + 1;
        element->score = 0;
        list = element;
        nb++;
    }
    my_rev_list(&list);
    return (list);
}

t_score *lecturescore_2(t_score *list, int fichier, int nb, int nbr2)
{
    char buffer[28];

    while (nb < 10) {
        read(fichier, buffer, 28);
        nbr2 = 0;
        list->name = malloc(sizeof(char)*11+1);
        list->name[11] = '\0';
        while (nbr2 < 11) {
            list->name[nbr2] = buffer[nbr2];
            nbr2++;
        }
        nbr2++;
        while (nbr2 < 27) {
            list->score = (buffer[nbr2] - 48) + 10 * list->score;
            nbr2++;
        }
        list = list->next;
        nb++;
    }
    return (list);
}