/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) :
    _name(name), _apcost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string const AWeapon::getName() const
{
    return this->_name;
}

int AWeapon::getAPCost() const
{
    return this->_apcost;
}

int AWeapon::getDamage() const
{
    return this->_damage;
}