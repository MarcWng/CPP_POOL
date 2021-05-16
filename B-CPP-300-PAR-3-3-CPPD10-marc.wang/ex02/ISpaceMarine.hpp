/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** ISpaceMarine.hpp
*/

#ifndef ISPACEMARINE_HPP
#define ISPACEMARINE_HPP

class ISpaceMarine
{
    public:
    virtual ~ISpaceMarine() {}
    virtual ISpaceMarine *clone() const = 0;
    virtual void battleCry() const = 0;
    virtual void rangedAttack() const = 0;
    virtual void meleeAttack() const = 0;
};


#endif