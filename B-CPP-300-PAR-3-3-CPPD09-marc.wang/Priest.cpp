/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Priest.cpp
*/

#include "Priest.hpp"
#include <iostream>

Priest::Priest(const std::string &name, int level) : Character(name, level), Mage(name, level)
{
    this->_class = "Priest";
    this->_race = "Orc";
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    if (this->Range == CLOSE) {
        if (this->_power < 10) {
            std::cout << this->_name << " out of power" << std::endl;
        } else {
            this->_power = this->_power - 10;
            std::cout << this->_name << " uses a spirit explosion" << std::endl;
            this->Range = RANGE;
            return (this->_spirit + 10);
        }
    }
    return 0;
}

void Priest::Heal()
{
    if (this->_power < 10)
        std::cout << this->_name << " out of power" << std::endl;
    else {
        if (this->_pv + 70 > 100)
            this->_pv = 100;
        else
            this->_pv = this->_pv + 70;
        this->_power = this->_power - 10;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    }
}