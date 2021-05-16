/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AssaultTerminator.cpp
*/

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator()
{
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &schwarzy)
{
    std::cout << "* teleports from space *" << std::endl;
    (void)schwarzy;
}

AssaultTerminator::~AssaultTerminator()
{
}

ISpaceMarine *AssaultTerminator::clone() const
{
    return (new AssaultTerminator(*this));
}

void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *" << std::endl;
}