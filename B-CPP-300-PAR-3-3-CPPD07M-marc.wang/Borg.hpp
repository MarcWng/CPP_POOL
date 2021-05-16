/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Borg.hpp
*/

#ifndef BORG_H
#define BORG_H

#include "Federation.hpp"

namespace Borg {
    class Ship : public Federation::Starfleet::Ship
    {
    private:
        int _side;
        
    public:
        Ship();
        ~Ship();
        void setupCore(WarpSystem::Core *Core);
        void checkCore();
    };
}

#endif