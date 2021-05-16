/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** PlasmaRifle.cpp
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}