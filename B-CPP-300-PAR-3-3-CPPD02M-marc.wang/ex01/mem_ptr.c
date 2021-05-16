/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** mem_ptr.c
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int i = 0;
    int j = 0;

    res[0] = malloc(strlen(str1) + strlen(str2) + 1);
    while (str1[i] != '\0') {
        res[0][i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        res[0][i] = str2[j];
        j++;
        i++;
    }
    res[0][i] = '\0';
}

void add_str_struct(str_op_t *str_op)
{
    int i = 0;
    int j = 0;

    str_op->res = malloc(strlen(str_op->str1) + strlen(str_op->str2) + 1);
    while (str_op->str1[i] != '\0') {
        str_op->res[i] = str_op->str1[i];
        i++;
    }
    while (str_op->str2[j] != '\0') {
        str_op->res[i] = str_op->str2[j];
        j++;
        i++;
    }
    str_op->res[i] = '\0';
}
