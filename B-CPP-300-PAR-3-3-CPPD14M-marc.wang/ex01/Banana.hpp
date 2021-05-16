/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** Banana.hpp
*/

#ifndef BANANA_HPP
#define BANANA_HPP

#include "Fruit.hpp"

class Banana : public Fruit
{
    public:
    Banana(int vitamins = 5);
    ~Banana();
};


#endif