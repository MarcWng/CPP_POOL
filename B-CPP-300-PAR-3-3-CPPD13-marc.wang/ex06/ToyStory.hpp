/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** ToyStory.hpp
*/

#ifndef TOYSTORY_HPP
#define TOYSTORY_HPP

#include <iostream>
#include "Toy.hpp"

class ToyStory
{
    public:
    ToyStory();
    ~ToyStory();
    static bool tellMeAStory(std::string filename, Toy &toy1, bool (Toy::*func1)(std::string), Toy &toy2, bool (Toy::*func2)(std::string));
};

#endif