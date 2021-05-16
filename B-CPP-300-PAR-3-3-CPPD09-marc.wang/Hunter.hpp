/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Hunter.hpp
*/

#ifndef HUNTER_HPP
#define HUNTER_HPP

#include "Warrior.hpp" 

class Hunter : public Warrior
{
    public:
    Hunter(const std::string &name, int level);
    ~Hunter();
    int RangeAttack();
    void RestorePower();
};

#endif