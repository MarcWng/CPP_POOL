/*
** EPITECH PROJECT, 2021
** add_mul.c
** File description:
** add mul
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int tmp_first = *first;

    *first = *first + *second;
    *second = *second * tmp_first;
}