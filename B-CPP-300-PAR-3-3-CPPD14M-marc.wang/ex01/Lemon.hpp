/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** Lemon.hpp
*/

#ifndef LEMON_HPP
#define LEMON_HPP

#include "Fruit.hpp"

class Lemon : public Fruit
{
    public:
    Lemon(int vitamins = 3);
    ~Lemon();
};

#endif