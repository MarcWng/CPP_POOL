/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type) : _hp(hp), _type(type) 
{

}

AEnemy::~AEnemy()
{
}

const std::string AEnemy::getType() const
{
    return this->_type;
}

int AEnemy::getHP() const
{
    return this->_hp;
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp = this->_hp - damage;
}