/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AEnemy.hpp
*/

#ifndef AENEMY_HPP
#define AENEMY_HPP

#include <iostream>
#include "AWeapon.hpp"

class AEnemy
{
    protected:
    int _hp;
    const std::string _type;

    public:
    AEnemy(int hp, const std::string &type);
    virtual ~AEnemy();
    virtual void takeDamage(int damage);
    const std::string getType() const;
    int getHP() const;
};


#endif