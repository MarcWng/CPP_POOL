/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Borg.hpp
*/

#ifndef BORG_H
#define BORG_H

#include "Federation.hpp"

namespace WarpSystem {
    class Core;
}

namespace Borg {
    class Ship;
    class Ship : public Federation::Ships
    {
    public:
        Ship();
        Ship(int weaponFrequency, int repair);
        ~Ship();
        void setupCore(WarpSystem::Core *Core);
        void checkCore();
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    private:
        int _side;
        int _shield;
        int _weaponFrequency;
        short _repair;
    };
}

#endif