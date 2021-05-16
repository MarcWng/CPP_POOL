/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** AssaultTerminator.hpp
*/

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    AssaultTerminator(AssaultTerminator const &schwarzy);
    ~AssaultTerminator();
    ISpaceMarine *clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif

