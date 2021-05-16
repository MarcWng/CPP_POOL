/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
** Victim.hpp
*/

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
    protected:
    const std::string _name;
    public:
    Victim(const std::string &name);
    ~Victim();
    virtual void getPolymorphed() const;
    const std::string getName() const;
};

std::ostream &operator<<(std::ostream &stream, const Victim &v);


#endif