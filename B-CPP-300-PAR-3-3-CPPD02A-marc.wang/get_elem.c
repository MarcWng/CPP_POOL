/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02A-marc.wang
** File description:
** get_elem.c
*/

#include "double_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    int size = 1;

    if (list == NULL) {
        return 0;
    }
    if (list->next == NULL) {
        return 1;
    }
    while (list->next != NULL) {
        size++;
        list = list->next;
    }
    return (size);
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

double double_list_get_elem_at_position(double_list_t list,
                                        unsigned int position)
{
    int i = 0;

    if (list == NULL)
        return 0;
    if (position == 0)
        return (double_list_get_elem_at_front(list));
    while (list->next != NULL && i != (int)position) {
        list = list->next;
        i++;
        }
    return list->value;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
                                                        double value)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL) {
        if (list->value == value)
            return (list);
        list = list->next;
        }
    return NULL;
}
