/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD02M-marc.wang
** File description:
** ptr_tricks.c
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int res = 0;

    if (ptr1 > ptr2) {
        while (ptr2 != ptr1) {
            ptr2++;
            res++;
        }
    }
    if (ptr1 < ptr2) {
        while (ptr2 != ptr1) {
            ptr1++;
            res++;
        }
    }
    return res;
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t res;

    return ((void*)member_ptr - ((void*)(&res.member) - (void*)(&res)));
}