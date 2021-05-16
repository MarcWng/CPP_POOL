/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main menger
*/

#include <stdlib.h>
#include <stdio.h>
#include "menger.h"
#include <math.h>

int error_handle(char *size, char *nb_lvl)
{
    int size_err = atoi(size);
    int nb_lvl_err = atoi(nb_lvl);

    if (size_err % 3 != 0 || size_err == 0) {
        fprintf(stderr, "Size must be multiple of 3\n");
        return 1;
    }
    if (nb_lvl_err <= 0) {
        fprintf(stderr, "Level must be higher than 0\n");
        return 1;
    }
    if (pow(3, nb_lvl_err) > size_err) {
        fprintf(stderr, "Size too small compared to interation\n");
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int size = 0;
    int nb_lvl = 0;

    if (ac != 3) {
        fprintf(stderr, "Must have 2 arguments.\n");
        return 1;
    }
    if (error_handle(av[1], av[2]) == 1)
        return 1;
    size = atoi(av[1]);
    nb_lvl = atoi(av[2]);
    sq_loop(size / 3, nb_lvl, 0, 0);
    return 0;
}
