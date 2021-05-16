/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Peon.hpp
*/

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
    public:
    Peon(std::string _name);
    ~Peon();
    void getPolymorphed() const;
};

#endif