/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Hunter.cpp
*/

#include "Hunter.hpp"
#include <iostream>

Hunter::Hunter(const std::string &name, int level) : Character(name, level), Warrior(name, level)
{
    Warrior::_class = "Hunter";
    Warrior::_strength = 9;
    Warrior::_stamina = 9;
    Warrior::_intelligence = 5;
    Warrior::_spirit = 6;
    Warrior::_agility = 25;
    Warrior::weaponName = "sword";
    std::cout << this->_name << " is born from a tree" << std::endl;
}

Hunter::~Hunter()
{
}

int Hunter::RangeAttack()
{
    if (this->_power < 25)
            std::cout << this->_name << " out of power" << std::endl;
    else {
        this->_power = this->_power - 25;
        std::cout << this->_name << " uses his bow" << std::endl;
        return (20 + this->_agility);
    }
    return 0;
}

void Hunter::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " meditates" << std::endl;
}
