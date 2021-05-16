/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** castmania.c
*/

#include "castmania.h"
#include <stdio.h>

void exec_operation(instruction_type_t instruction_type, void *data)
{
    instruction_t *instruction = (instruction_t*)data;
    addition_t *addition_struct = (addition_t*)(instruction->operation);
    division_t *division_struct = (division_t*)(instruction->operation);
    integer_op_t *integer = (integer_op_t*)division_struct->div_op;
    decimale_op_t *decimale = (decimale_op_t*)division_struct->div_op;

    if (instruction_type == ADD_OPERATION) {
        exec_add(addition_struct);
        if (instruction->output_type == VERBOSE)
            printf("%d", addition_struct->add_op.res);
    }
    if (instruction_type == DIV_OPERATION) {
        exec_div(division_struct);
        if (instruction->output_type == VERBOSE) {
            if (division_struct->div_type == INTEGER)
                printf("%d", integer->res);
            if (division_struct->div_type == DECIMALE)
                printf("%f", decimale->res);
        }
    }
}

void exec_instruction(instruction_type_t instruction_type, void *data)
{
    int *integer = (int*)(data);
    float *decimale = (float*)data;

    if (instruction_type == PRINT_INT)
        printf("%d\n", *integer);
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", *decimale);
    else
        exec_operation(instruction_type, data);
}
