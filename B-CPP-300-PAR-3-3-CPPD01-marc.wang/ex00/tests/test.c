/*
** EPITECH PROJECT, 2021
** unit_test
** File description:
** test z.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

void print_z();

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(print_z, simple_z, .init = redirect_all_std)
{
    print_z();
    cr_assert_stdout_eq_str("z\n");
}
