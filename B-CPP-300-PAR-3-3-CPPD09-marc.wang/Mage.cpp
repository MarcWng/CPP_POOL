/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Priest.cpp
*/

#include "Mage.hpp"
#include <iostream>


Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    this->_class = "Mage";
    this->_race = "Gnome";
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << this->_name << " teleported" << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (this->Range == CLOSE) {
        if (this->_power < 10) {
            std::cout << this->_name << " out of power" << std::endl;
        } else {
            this->_power = this->_power - 10;
            std::cout << this->_name << " blinks" << std::endl;
            this->Range = RANGE;
        }
    }
    return 0;
}

int Mage::RangeAttack()
{
    if (this->_power < 25) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    } else {
        this->_power = this->_power - 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
        return (20 + this->_spirit);
    }
}

void Mage::RestorePower()
{
    if (this->_power + 50 + this->_intelligence > 100)
        this->_power = 100;
    else
        this->_power = this->_power + this->_intelligence + 50;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}