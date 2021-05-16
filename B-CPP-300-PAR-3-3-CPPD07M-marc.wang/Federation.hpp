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

namespace Federation {
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

        class Ship
        {
        protected:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *captain;
            Destination _location ;
            Destination _home ;
        public:
            Ship();
            Ship(int length, int width, std::string name, short maxWarp);
            ~Ship();
            void setupCore(WarpSystem::Core *Core);
            void checkCore();
            void promote(Captain * captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        };
    }
    class Ship : public Starfleet::Ship
    {
        public:
        Ship(int length, int width, std::string name);
        ~Ship();
        void setupCore(WarpSystem::Core *Core);
        void checkCore();
    };
}

#endif