/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD09-marc.wang
** File description:
** Priest.hpp
*/

#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "Mage.hpp"

class Priest : virtual public Mage
{
public:
    Priest(const std::string &name, int level);
    ~Priest();
    int CloseAttack();
    void Heal();
};


#endif