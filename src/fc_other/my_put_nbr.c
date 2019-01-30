/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr.c
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

int my_put_nbr(long long nb)
{
    int mb;

    if (nb < 0) {
        nb = nb * -1;
        write(1, "-" , 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    mb = nb % 10 + 48;
    write(1, &mb , 1);
    return (0);
}