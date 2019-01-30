/*
** EPITECH PROJECT, 2019
** my_rev_listspe.c
** File description:
** my_rev_listspe.c
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

multi_object **my_rev_listspe_1(int end, int mid, multi_object **array)
{
    int count = 0;
    multi_object *tmp;

    while (count < mid) {
        tmp = array[count];
        array[count] = array[end];
        array[end] = tmp;
        end--;
        count++;
    }
    return (array);
}

void my_rev_listspe(multi_object **begin, int i)
{
    multi_object **array;
    int count = 0;
    multi_object **save = begin;

    begin = save;
    array = malloc(sizeof(t_score *)*i+1);
    array[0] = *begin;
    while (count < i) {
        array[count+1] = array[count]->next;
        count++;
    }
    array = my_rev_listspe_1(i - 1, i / 2, array);
    count = 0;
    *begin = array[0];
    while (count < i) {
        array[count]->next = array[count+1];
        count++;
    }
    free(array);
}