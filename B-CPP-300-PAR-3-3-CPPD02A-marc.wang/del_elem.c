/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02A-marc.wang
** File description:
** six_to_eleven.c
*/

#include "double_list.h"
#include <stdlib.h>
#include <stdlib.h>

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    struct doublelist_node *temp = NULL;

    temp = front_ptr[0];
    if (temp == NULL)
        return false;
    if (temp->next == NULL) {
        front_ptr[0] = NULL;
        return true;
    }
    front_ptr[0] = front_ptr[0]->next;
    return true;
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t prev = front_ptr[0];

    if (front_ptr[0] == NULL)
        return false;
    if (front_ptr[0]->next == NULL) {
        free(front_ptr[0]);
        return true;
    }
    if (front_ptr[0]->next->next != NULL) {
        while (prev->next->next != NULL)
            prev = prev->next;
        prev->next = NULL;
    }
    return true;
}

bool check_del_elem_pos(double_list_t *front_ptr,
                        unsigned int position)
{
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    if (position > double_list_get_size(front_ptr[0]) + 1)
        return (double_list_del_elem_at_back(front_ptr));
    return false;
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
                                    unsigned int position)
{
    double_list_t prev_elem = front_ptr[0];
    double_list_t next_elem = NULL;

    if (prev_elem == NULL && position > double_list_get_size(front_ptr[0]))
        return false;
    if (check_del_elem_pos(front_ptr, position) == true)
        return true;
    for (int i = 0; i + 1 < (int)position && prev_elem->next != NULL; i++)
        prev_elem = prev_elem->next;
    if (prev_elem->next != NULL) {
        if (prev_elem->next->next != NULL)
            next_elem = prev_elem->next->next;
        free(prev_elem->next);
    }
    prev_elem->next = next_elem;
    return true;
}