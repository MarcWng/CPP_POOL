/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** SuperMutant.cpp
*/

#include "SuperMutant.hpp"


SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    if (damage - 3 < 0)
        return;
    else
        this->_hp = this->_hp - (damage - 3);
    if (this->_hp < 0)
        std::cout << "Aaargh..." << std::endl;
}