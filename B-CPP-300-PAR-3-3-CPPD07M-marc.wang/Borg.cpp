/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Borg.cpp
*/

#include "Borg.hpp"

namespace Borg {
    Ship::Ship()
    {
        this->_home = UNICOMPLEX;
        this->_location = this->_home;
        this->_maxWarp = 9;
        this->_side = 300;
        std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n" \
                    "Your biological characteristics and technologies will be assimilated.\n" \
                    "Resistance is futile." << std::endl;
    }
    
    Ship::~Ship()
    {
    }

    void Borg::Ship::setupCore(WarpSystem::Core *Core)
    {
        this->_core = Core;
    }

    void Borg::Ship::checkCore()
    {
        std::string stability;

        if (this->_core->checkReactor()->isStable() == true)
            stability.append("Everything is in order.");
        else
            stability.append("Critical failure imminent.");
        std::cout << stability << std::endl;
    }
}