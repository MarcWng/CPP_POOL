/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** tab_to_2dtab.c
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int tab_i = 0;
    int i = 0;

    res[0] = malloc(sizeof(int*) * length);
    if (res[0] == NULL)
        return;
    while (i != length) {
        res[0][i] = malloc(sizeof(int) * width);
        if (res[0][i] == NULL)
            return;
        for (int j = 0; j != width; j++) {
            res[0][i][j] = tab[tab_i];
            tab_i++;
        }
        i++;
    }
    res[0][i] = NULL;
}
