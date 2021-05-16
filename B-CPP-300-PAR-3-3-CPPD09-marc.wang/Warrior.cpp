/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Warrior.cpp
*/

#include "Warrior.hpp"
#include <iostream>

Warrior::Warrior(const std::string &name, int level) : Character(name, level)
{
    this->_pv = 100;
    this->_power = 100;
    this->_stamina = 12;
    this->_strength = 12;
    this->_agility = 7;
    this->_intelligence = 6;
    this->_class = "Warrior";
    this->_race = "Dwarf";
    this->weaponName = "hammer";
    std::cout << "I'm " << this->_name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (this->Range == CLOSE) {
        if (this->_power < 30) {
            std::cout << this->_name << " out of power" << std::endl;
            return 0;
        } else {
            this->_power = this->_power - 30;
            std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
            return (20 + this->_strength);
        }
    } else
        return 0;
}

int Warrior::RangeAttack()
{
    if (this->Range == RANGE) {
        if (this->_power < 10)
            std::cout << this->_name << " out of power" << std::endl;
        else {
            this->_power = this->_power - 10;
            std::cout << this->_name << " intercepts" << std::endl;
            this->Range = CLOSE;
        }
    }
    return 0;
}