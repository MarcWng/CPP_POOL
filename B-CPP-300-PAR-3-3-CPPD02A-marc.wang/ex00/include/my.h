/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include "double_list.h"

typedef struct graph_list_s {
    double_list_t *head;
}graph_list_t;

typedef struct graph_edge_s {
    int src;
    int dest;
}graph_edge_t;

#endif
