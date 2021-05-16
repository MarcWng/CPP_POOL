/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** TacticalMarine.hpp
*/

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : virtual public ISpaceMarine
{
private:
public:
    TacticalMarine();
    TacticalMarine(TacticalMarine const &cpy);
    ~TacticalMarine();
    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif