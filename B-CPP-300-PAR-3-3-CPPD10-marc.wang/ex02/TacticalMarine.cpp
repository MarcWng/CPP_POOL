/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** TacticalMarine.cpp
*/

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &cpy)
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
    (void)cpy;
}

TacticalMarine::~TacticalMarine()
{
}

ISpaceMarine *TacticalMarine::clone() const
{
    return (new TacticalMarine(*this));
}

void TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}
