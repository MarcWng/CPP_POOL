/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Priest.hpp
*/

#ifndef MAGE_HPP
#define MAGE_HPP

#include "Character.hpp"

class Mage : virtual public Character
{
    public:
    Mage(const std::string &name, int level);
    ~Mage();
    int CloseAttack();
    int RangeAttack();
    void RestorePower();
};

#endif