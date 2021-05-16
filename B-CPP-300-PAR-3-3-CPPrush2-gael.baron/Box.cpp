/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** Box.cpp
*/

#include "Box.hpp"
#include <iostream>

Box::Box() : Wrap("Box"), gift(nullptr), is_open(false)
{
}

Box::~Box()
{
}

void Box::wrapMeThat(Object *gift)
{
    if (this->is_open == false)
        return;
    else {
        std::cout << "tuuuut tuuut tuut" << std::endl;
        this->gift = gift;
    }
}

const Object *Box::openMe()
{
    if (this->is_open != true)
        this->is_open = true;
    std::cout << "whistles while working" << std::endl;
    return (this->gift);
}

void Box::closeMe()
{
    this->is_open = false;
}

bool Box::isOpen()
{
    return (this->is_open);
}
