/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Federation.cpp
*/

#include "Federation.hpp"

namespace Federation {
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
        }

        Ship::Ship(int length, int width, std::string name, short maxWarp)
        {
            this->_home = EARTH;
            this->_location = this->_home;
            this->_length = length;
            this->_width = width;
            this->_name = name;
            std::cout << "The ship USS " << name << " has been finished." << std::endl;
            this->_maxWarp = maxWarp;
            std::cout << "It is " << length << " m in length and " << width << " m in width." << std::endl;
            std::cout << "It can go to Warp " << maxWarp << "!" << std::endl;
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
        bool Federation::Starfleet::Ship::move(int warp, Destination d)
        {
            bool ret = false;

            if (warp <= this->_maxWarp &&  d != _location && this->_core->checkReactor()->isStable() == true)
                ret = true;
            this->_location = d;
            return ret;
        }

        bool Federation::Starfleet::Ship::move(int warp)
        {
            bool ret = false;

            if (warp <= this->_maxWarp && this->_core->checkReactor()->isStable() == true)
                ret = true;
            this->_location = this->_home;
            return ret;
        }

        bool Federation::Starfleet::Ship::move(Destination d)
        {
            bool ret = false;

            if (d != _location && this->_core->checkReactor()->isStable() == true)
                ret = true;
            this->_location = d;
            return ret;
        }

        bool Federation::Starfleet::Ship::move()
        {
            bool ret = false;

            if (this->_core->checkReactor()->isStable() == true)
                ret = true;
            this->_location = this->_home;
            return ret;
        }
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

    void Federation::Ship::setupCore(WarpSystem::Core *Core)
    {
        this->_core = Core;
        std::cout << this->_name << ": The core is set." << std::endl;
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

    Ship::~Ship()
    {
    }
}
