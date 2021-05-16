/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Federation.cpp
*/

#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation {
    Ships::Ships()
    {
    }
    Ships::~Ships()
    {
    }
    int Federation::Ships::getShield()
    {
        return this->_shield;
    }

    int Federation::Ships::getTorpedo()
    {
        return this->_photonTorpedo;
    }
    void Federation::Ships::setShield(int shield)
    {
        this->_shield = shield;
    }

    void Federation::Ships::setTorpedo(int torpedo)
    {
        this->_photonTorpedo = torpedo;
    }
    bool Federation::Ships::move(int warp, Destination d)
    {
        bool ret = false;

        if (warp <= this->_maxWarp &&  d != _location && this->_core->checkReactor()->isStable() == true)
            ret = true;
        this->_location = d;
        return ret;
    }

    bool Federation::Ships::move(int warp)
    {
        bool ret = false;

        if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable() == true)
            ret = true;
        this->_location = this->_home;
        return ret;
    }

    bool Federation::Ships::move(Destination d)
    {
        bool ret = false;

        if (d != _location && this->_core->checkReactor()->isStable() == true)
            ret = true;
        this->_location = d;
        return ret;
    }

    bool Federation::Ships::move()
    {
        bool ret = false;

        if (this->_core->checkReactor()->isStable() == true)
            ret = true;
        this->_location = this->_home;
        return ret;
    }

    namespace Starfleet {
        Ensign::Ensign(std::string name)
        {
            this->_name = name;
            std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
        }

        Ensign::~Ensign()
        {
        }

        Captain::Captain(std::string name)
        {
            this->_name = name;
        }

        Captain::~Captain()
        {
        }

        Ship::Ship()
        {
            this->_length = 289;
            this->_width = _width;
            this->_maxWarp = 6;
            std::cout << "The ship USS Entreprise has been finished." << std::endl;
            std::cout << "It is 289 m in length and 132 m in width." << std::endl;
            std::cout << "It can go to Warp 6!" << std::endl;
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
        {
            this->_photonTorpedo = torpedo;
            this->_shield = 100;
            this->_home = EARTH;
            this->_location = this->_home;
            this->_length = length;
            this->_width = width;
            this->_name = name;
            this->_maxWarp = maxWarp;
            std::cout << "The ship USS " << name << " has been finished." << std::endl;
            std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
            if (torpedo != 0)
                std::cout << "Weapons are set: " << this->_photonTorpedo << " torpedoes ready." << std::endl;
        }
        Ship::~Ship()
        {
        }

        std::string Federation::Starfleet::Captain::getName()
        {
            return this->_name;
        }

        int Federation::Starfleet::Captain::getAge()
        {
            return this->_age;
        }

        void Federation::Starfleet::Captain::setAge(int age)
        {
            this->_age = age;
        }

        void Federation::Starfleet::Ship::promote(Captain * captain)
        {
            this->captain = captain;
            std::cout << this->captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
        }

        void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *Core)
        {
            this->_core = Core;
            std::cout << "USS " << this->_name << ": The core is set." << std::endl;
        }

        void Federation::Starfleet::Ship::checkCore()
        {
            std::string stability;

            if (this->_core->checkReactor()->isStable() == true)
                stability.append("stable");
            else
                stability.append("unstable");
            std::cout << "USS " << this->_name << ": The core is " << stability <<  " at the time." << std::endl;
        }

        void Federation::Starfleet::Ship::fire(Borg::Ship *target)
        {
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
            else {
                this->_photonTorpedo =- 1;
                std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
                target->setShield(target->getShield() - 50);
                if (this->_photonTorpedo == 0)
                    std::cout << this->_name << ": No more torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
            }
        }

        void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
        {
            if (this->_photonTorpedo == 0)
                std::cout << this->_name << ": No enough torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
            else {
                this->_photonTorpedo =- 1;
                std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
                target->setShield(target->getShield() - (50 * torpedoes));
                if (this->_photonTorpedo == 0)
                    std::cout << this->_name << ": No more torpedoes to fire, " << this->captain->getName() << "!" << std::endl;
            }
        }
    }
////////////////////////////
    Ship::Ship()
    {
    }

    Ship::Ship(int length, int width, std::string name)
    {
        this->_home = VULCAN;
        this->_location = this->_home;
        this->_length = length;
        this->_width = width;
        this->_name = name;
        this->_maxWarp = 1;
        std::cout << "The independent ship " << name << " just finished its construction." << std::endl;
        std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
    }

    Ship::~Ship()
    {
    }

    WarpSystem::Core *Ship::getCore()
    {
        return this->_core;
    }

    void Federation::Ship::checkCore()
    {
        std::string stability;

        if (this->_core->checkReactor()->isStable() == true)
            stability.append("stable");
        else
            stability.append("unstable");
        std::cout << this->_name << ": The core is " << stability <<  " at the time." << std::endl;
    }

    void Federation::Ship::setupCore(WarpSystem::Core *Core)
    {
        this->_core = Core;
        std::cout << this->_name << ": The core is set." << std::endl;
    }

    void Federation::Ship::setShield(int shield)
    {
        this->_shield = shield;
    }

    int Federation::Ship::getShield()
    {
        return this->_shield;
    }
}
