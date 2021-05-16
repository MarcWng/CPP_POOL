/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Warrior.hpp
*/

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.hpp"

class Warrior : virtual public Character
{
    protected:
    std::string weaponName;
    public:
        Warrior(const std::string &name, int level);
        ~Warrior();
        int CloseAttack();
        int RangeAttack();
};


#endif