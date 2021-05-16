/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** SuperMutant.hpp
*/

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
    public:
    SuperMutant();
    ~SuperMutant();
    void takeDamage(int damage);
};

#endif