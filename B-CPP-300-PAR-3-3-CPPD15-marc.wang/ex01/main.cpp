/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** main.cpp
*/

#include "ex01.hpp"
#include <iostream>

int main()
{
    toto a;
    toto b;
    const char s1[8] = "chaineZ";
    const char s2[10] = "chaineA42";

    std::cout << "for toto ret = " << ::compare(toto(), toto()) << std::endl;
    std::cout << "for toto ret = " << ::compare(1, 2) << std::endl;
    std::cout << "for toto ret = " << ::compare(s1, s2) << std::endl;
    std::cout << "for toto ret = " << ::compare(&a, &b) << std::endl;
}