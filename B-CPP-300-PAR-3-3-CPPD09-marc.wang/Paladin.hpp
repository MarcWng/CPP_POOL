/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Paladin.hpp
*/

#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin : virtual public Warrior, virtual public Priest
{
    public:
    Paladin(const std::string &name, int level);
    ~Paladin();
    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();
    int Intercept();
};

#endif