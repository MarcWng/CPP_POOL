/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** ISquad.hpp
*/


#ifndef ISQUAD_HPP
#define ISQUAD_HPP
#include "ISpaceMarine.hpp"

class ISquad
{
    public :
    virtual ~ISquad() {}
    virtual int getCount()const = 0;
    virtual ISpaceMarine *getUnit (int) = 0;
    virtual int push(ISpaceMarine*) = 0;
};

#endif