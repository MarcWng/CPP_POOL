/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** Federation.hpp
*/

#ifndef FEDERATION_H
#define FEDERATION_H

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
    class Ship;
};

namespace Federation {
    class Ships {
        protected:
        Destination _location ;
        Destination _home ;
        int _shield;
        int _photonTorpedo;
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        public :
        int getTorpedo();
        int getShield();
        void setTorpedo(int torpedo);
        void setShield(int shield);
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    };
    class Ship : public Ships
    {
        public:
        Ship();
        Ship(int length, int width, std::string name);
        ~Ship();
        WarpSystem::Core *getCore();
        void checkCore();
        void setupCore(WarpSystem::Core *Core);
        void setShield(int shield);
    };
    namespace Starfleet{
        class Ensign
        {
        private:
            std::string _name;
        public:
            Ensign(std::string name);
            ~Ensign();
        };

        class Captain
        {
        private:
            std::string _name;
            int _age;
        public:
            Captain(std::string name);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int age);
        };
        class Ship : public Ships
        {
        private:
            Starfleet::Captain *captain;
        public:
            Ship();
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            ~Ship();
            void setupCore(WarpSystem::Core *Core);
            void checkCore();
            void promote(Captain *captain);
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        };
    }
}

#endif