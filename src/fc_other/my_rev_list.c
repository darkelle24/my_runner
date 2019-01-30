/*
** EPITECH PROJECT, 2019
** my_rev_list.c
** File description:
** my_rev_list.c
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

void my_rev_list(t_score **begin)
{
    int i;
    t_score **array;
    int count = 0;

    i = 10;
    array = malloc(sizeof(t_score *)*i+1);
    array[0] = *begin;
    while (count < i) {
        array[count+1] = array[count]->next;
        count++;
    }
    array = my_rev_list_1(i - 1, i / 2, array);
    count = 0;
    *begin = array[0];
    while (count < i) {
        array[count]->next = array[count+1];
        count++;
    }
    free(array);
}

t_score **my_rev_list_1(int end, int mid, t_score **array)
{
    int count = 0;
    t_score *tmp;

    while (count < mid) {
        tmp = array[count];
        array[count] = array[end];
        array[end] = tmp;
        end--;
        count++;
    }
    return (array);
}