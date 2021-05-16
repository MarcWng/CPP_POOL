/*
** EPITECH PROJECT, 2021
** menger.c
** File description:
** menger algo
*/

#include "menger.h"
#include <stdio.h>
#include <math.h>

void print_line(int first, int second, int third)
{
    printf("%03d %03d %03d\n", first, second, third);
}

void sq_loop(int size, int nb_lvl, int x, int y)
{
    print_line(size, x + size, y + size);
    nb_lvl = nb_lvl - 1;
    if (size != 0 && nb_lvl > 0) {
        sq_loop(size / 3, nb_lvl, x, y);
        sq_loop(size / 3, nb_lvl, x, y + size);
        sq_loop(size / 3, nb_lvl, x, y + (size * 2));
        sq_loop(size / 3, nb_lvl, x + size, y);
        sq_loop(size / 3, nb_lvl, x + size, y + (size * 2));
        sq_loop(size / 3, nb_lvl, x + (size * 2), y);
        sq_loop(size / 3, nb_lvl, x + (size * 2), y + size);
        sq_loop(size / 3, nb_lvl, x + (size * 2), y + (size * 2));
    }
}
