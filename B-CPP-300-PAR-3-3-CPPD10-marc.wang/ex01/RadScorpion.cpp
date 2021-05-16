/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** RadScorpion.cpp
*/

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int damage)
{
    this->_hp = this->_hp - (damage - 3);
    if (this->_hp < 0)
        std::cout << "* SPROTCH *" << std::endl;
}