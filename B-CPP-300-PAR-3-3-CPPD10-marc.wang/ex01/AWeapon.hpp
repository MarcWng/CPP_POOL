/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AWeapong.hpp
*/

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{
    public:
    AWeapon(const std::string &name, int apcost, int damage);
    virtual ~AWeapon();
    std::string const getName() const;
    int getAPCost()const;
    int getDamage()const;
    virtual void attack() const = 0;
    protected:
    const std::string _name;
    int _apcost;
    int _damage;
};

#endif