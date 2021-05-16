/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** main.cpp
*/

#include "KoalaBot.hpp"

int main ()
{
    KoalaBot kb ;
    std :: cout << std::boolalpha << kb.status () << std :: endl ;
    kb . informations () ;
    return 0;
}