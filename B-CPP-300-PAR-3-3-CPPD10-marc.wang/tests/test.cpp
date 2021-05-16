/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** test.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex00/Sorcerer.hpp"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Sorcerer, constructor, .init = redirect_all_std)
{
    {
        Sorcerer b ("rob", "titre");
    }
    cr_expect_stdout_eq_str("rob, titre, is born!\nrob, titre, is dead. Consequences will never be the same!\n");
}
