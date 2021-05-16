/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** PowerFist.cpp
*/

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}