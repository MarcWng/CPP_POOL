/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Squad.hpp
*/

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : virtual public ISquad
{
    private:
    Squad *next_unit;
    ISpaceMarine *_marine;
    public:
    Squad();
    Squad(const Squad *sq);
    ~Squad();
    int getCount() const;
    ISpaceMarine *getUnit (int index);
    int push(ISpaceMarine* space_m);
};

#endif
