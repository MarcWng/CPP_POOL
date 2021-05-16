/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** PlasmaRifle.hpp
*/

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
    PlasmaRifle();
    ~PlasmaRifle();
    void attack() const override;
};

#endif
