/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02A-marc.wang
** File description:
** one_to_five.c
*/

#include "double_list.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void double_list_dump(double_list_t list)
{
    if (list == NULL)
        return;
    else
        printf("%f\n", list->value);
    while (list->next != NULL) {
        list = list->next;
        printf("%f\n", list->value);
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t new_elem = malloc(sizeof(double_list_t));

    if (new_elem == NULL)
        return false;
    new_elem->value = elem;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    return true;
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t new_elem = malloc(sizeof(double) +
                            sizeof(doublelist_node_t));
    double_list_t prev = front_ptr[0];

    if (new_elem == NULL)
        return false;
    new_elem->value = elem;
    new_elem->next = NULL;
    if (front_ptr[0] == NULL) {
        front_ptr[0] = new_elem;
        return true;
    }
    while (prev->next != NULL)
        prev = prev->next;
    prev->next = new_elem;
    return true;
}

bool check_add_elem_pos(double_list_t *front_ptr,
                        double elem, unsigned int position)
{
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    if (position > double_list_get_size(front_ptr[0]) + 1)
        return (double_list_add_elem_at_back(front_ptr, elem));
    return false;
}

bool double_list_add_elem_at_position(double_list_t *front_ptr,
                                    double elem, unsigned int position)
{
    double_list_t new_elem = malloc(sizeof(double) + sizeof(doublelist_node_t));
    double_list_t prev_elem = front_ptr[0];
    double_list_t next_elem = malloc(sizeof(double_list_t));
    int i = 0;

    if (front_ptr[0] == NULL)
        return false;
    new_elem->value = elem;
    new_elem->next = NULL;
    if (check_add_elem_pos(front_ptr, elem, position) == true)
        return true;
    while (i + 1 < (int)position && prev_elem->next != NULL) {
        prev_elem = prev_elem->next;
        i++;
    }
    if (prev_elem->next != NULL)
        next_elem = prev_elem->next;
    prev_elem->next = new_elem;
    new_elem->next = next_elem;
    return true;
}