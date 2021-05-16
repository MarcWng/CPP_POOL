/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** main.cpp
*/

#include "Priest.hpp"
#include <iostream>


int main ()
{
    Priest p("Iopy", 23);

    std::cout << "pow = " << p.getPower() << std::endl;
    p.CloseAttack();
    std::cout << "pow = " << p.getPower() << std::endl;
    p.TakeDamage(90);
    std::cout << "pow = " << p.getPower() << std::endl;
    p.Heal();
    std::cout << "pow = " << p.getPower() << std::endl;
    p.RangeAttack();
    std::cout << "pow = " << p.getPower() << std::endl;
}