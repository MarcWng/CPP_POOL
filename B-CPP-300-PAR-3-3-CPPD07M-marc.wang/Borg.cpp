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

    Ship::Ship(int weaponFrequency, int repair = 3)
    {
        this->_weaponFrequency = weaponFrequency;
        this->_repair = repair;
        this->_shield = 100;
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

    int Borg::Ship::getWeaponFrequency()
    {
        return this->_weaponFrequency;
    }

    void Borg::Ship::setWeaponFrequency(int frequency)
    {
        this->_weaponFrequency = frequency;
    }

    short Borg::Ship::getRepair()
    {
        return this->_repair;
    }

    void Borg::Ship::setRepair(short repair)
    {
        this->_repair = repair;
    }

    void Borg::Ship::fire(Federation::Starfleet::Ship *target)
    {
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        else {
            this->_photonTorpedo =- 1;
            std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
            target->setShield(target->getShield() - 50);
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No more torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        }
    }

    void Borg::Ship::fire(Federation::Ship *target)
    {
        if (this->_photonTorpedo == 0)
            std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        else {
            this->_photonTorpedo =- 1;
            std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
            target->setShield(target->getShield() - 50);
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No more torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
        }
    }

    void Borg::Ship::repair()
    {
        std::cout << "Begin shield re-initialisation...";
        if (this->_repair > 0) {
            this->setRepair(this->_repair - 1);
            this->setShield(100);
            std::cout << " Done. Awaiting further instructions." << std::endl;
        } else
            std::cout << " Energy cells depleted, shield weakening." << std::endl;
    }
}
