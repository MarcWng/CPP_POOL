/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** add.c
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    return (a + b);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a = a * (-1);
    if (b < 0)
        b = b * (-1);
    return (a + b);
}

void exec_add(addition_t *operation)
{
    integer_op_t *integer = &operation->add_op;

    if (operation->add_type == NORMAL)
        integer->res = normal_add(integer->a, integer->b);
    if (operation->add_type == ABSOLUTE)
        integer->res = absolute_add(integer->a, integer->b);
}
