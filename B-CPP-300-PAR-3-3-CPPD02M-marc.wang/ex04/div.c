/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** div.c
*/

#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return 0;
    return (a / b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return 0;
    return ((float) a / b);
}

void exec_div(division_t *operation)
{
    integer_op_t *integer = (integer_op_t*)operation->div_op;
    decimale_op_t *decimale = (decimale_op_t*)operation->div_op;

    if (operation->div_type == INTEGER)
        integer->res = integer_div(integer->a, integer->b);
    if (operation->div_type == DECIMALE)
        decimale->res = decimale_div(decimale->a, decimale->b);
}
