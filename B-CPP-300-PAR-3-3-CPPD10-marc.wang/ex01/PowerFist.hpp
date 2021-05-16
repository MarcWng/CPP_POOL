/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** PowerFist.hpp
*/

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist();
    ~PowerFist();
    void attack() const override;
};


#endif