/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name) :
    _name(name), _ap(40), _weapon(NULL)
{
}

Character::~Character()
{
}

void Character::recoverAP()
{
    if (this->_ap + 10 > 40)
        this->_ap = 40;
    else
        this->_ap = this->_ap + 10;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (this->_weapon == NULL)
        return;
    else {
        std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        enemy->takeDamage(this->_weapon->getDamage());
        this->_ap = this->_ap - this->_weapon->getAPCost();
        if (enemy->getHP() == 0)
            delete enemy;
    }
}

int Character::getAp() const
{
    return this->_ap;
}

const std::string Character::getName() const
{
    return this->_name;
}

AWeapon *Character::getWeapon() const
{
    return this->_weapon;
}

std::ostream &operator<<(std::ostream &stream, const Character &c)
{
    if (c.getWeapon() == NULL)
        stream << c.getName() << " has " << c.getAp() << " AP and is unarmed" << std::endl;
    else
        stream << c.getName() << " has " << c.getAp() << " AP and wields a " << c.getWeapon()->getName() << std::endl;
    return stream;
}