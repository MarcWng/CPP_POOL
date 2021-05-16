/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02A-marc.wang
** File description:
** main.c
*/

#include "double_list.h"
#include <unistd.h>
#include <stdio.h>

static void populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_back(list_head, 5.2);
    double_list_add_elem_at_back(list_head, 42.5);
    double_list_add_elem_at_back(list_head, 43.5);
    double_list_add_elem_at_back(list_head, 44.5);
    double_list_add_elem_at_front(list_head, 5555.555);
    double_list_add_elem_at_position(list_head, 123456789, 7);
}
static void test_size ( double_list_t list_head )
{
    double_list_dump(list_head);
}
static void test_del ( double_list_t * list_head )
{
    double_list_del_elem_at_position(list_head, 2);
    printf (" There are %u elements in the list \n", double_list_get_size(*list_head));
    double_list_dump(*list_head);
}
int main(void)
{
    double_list_t list_head = NULL;

    populate_list(&list_head);
    test_size(list_head);
    test_del(&list_head);
    return (0);
}
