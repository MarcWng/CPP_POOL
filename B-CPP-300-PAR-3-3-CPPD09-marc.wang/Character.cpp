/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Character.cpp
*/

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name, int level) :
    _name(name), _lvl(level), Range(CLOSE), _pv(100), _power(100),
    _stamina(5), _spirit(5), _agility(5), _strength(5),
    _intelligence(5), _class("Character"), _race("Human")
{
    std::cout << name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string &Character::getName() const
{
    return this->_name;
}

int Character::getLvl() const
{
    return this->_lvl;
}

int Character::getPv() const
{
    return this->_pv;
}
int Character::getPower() const
{
    return this->_power;
}

int Character::CloseAttack()
{
    if (this->Range == CLOSE) {
        if (this->_power < 10) {
            std::cout << this->_name << " out of power" << std::endl;
            return 0;
        } else {
            this->_power = this->_power - 10;
            std::cout << this->_name << " strikes with a wooden stick" << std::endl;
            return (10 + this->_strength);
        }
    } else
        return 0;
}

void Character::Heal()
{
    if (this->_pv > 50)
        this->_pv = 100;
    else
        this->_pv = this->_pv + 50;
    std::cout << this->_name << " takes a potion" << std::endl;
}

int Character::RangeAttack()
{
    if (this->_power < 10) {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    } else {
        this->_power = this->_power - 10;
        std::cout << this->_name << " tosses a stone" << std::endl;
        return (5 + this->_strength);
    }
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    if (this->_pv < damage) {
        this->_pv = 0;
        std::cout << this->_name << " out of combat" << std::endl;
    } else {
        this->_pv = this->_pv - damage;
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;
        if (this->_pv == 0)
            std::cout << this->_name << " out of combat" << std::endl;
    }
}