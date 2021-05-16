/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD10-marc.wang
** File description:
**  Sorcerer.hpp
*/

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Peon.hpp"

class Sorcerer
{
    private:
        std::string _title;
        const std::string _name;
    public:
        Sorcerer(const std::string &name, std::string title);
        ~Sorcerer();
        std::string getName() const;
        std::string getTitle() const;
        void polymorph(const Victim &victim) const;
        void polymorph(const Peon &Peon) const;
};
std::ostream &operator<<(std::ostream &stream, const Sorcerer &s);

#endif
