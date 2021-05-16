/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** RadScorpion.hpp
*/

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "AEnemy.hpp"

class RadScorpion : public AEnemy
{
    public:
    RadScorpion();
    ~RadScorpion();
    void takeDamage(int damage);
};

#endif