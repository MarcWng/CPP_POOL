/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Paladin.cpp
*/

#include "Paladin.hpp"
#include <iostream>

Paladin::Paladin(const std::string &name, int level) : Character(name, level), Warrior(name, level), Mage(name, level), Priest(name, level)
{
    Warrior::_class = "Paladin";
    Warrior::_strength = 9;
    Warrior::_stamina = 10;
    Warrior::_intelligence = 10;
    Warrior::_spirit = 10;
    Warrior::_agility = 2;
    Warrior::weaponName = "hammer";
    std::cout << "the light falls on " << this->_name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
    return (Warrior::CloseAttack());
}

void Paladin::Heal()
{
    return (Priest::Heal());
}

int Paladin::RangeAttack()
{
    return (Mage::RangeAttack());
}

void Paladin::RestorePower()
{
    return (Warrior::RestorePower());
}

int Paladin::Intercept()
{
    return (Warrior::RangeAttack());
}