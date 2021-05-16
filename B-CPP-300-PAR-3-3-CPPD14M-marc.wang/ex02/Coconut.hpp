/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** Coconut.hpp
*/

#ifndef COCONUT_HPP
#define COCONUT_HPP

#include "Fruit.hpp"

class Coconut : public Fruit
{
    public:
    Coconut(int vitamins = 15);
    ~Coconut();
};
#endif