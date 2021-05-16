/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** Fruit.hpp
*/

#ifndef FRUIT_HPP
#define FRUIT_HPP
#include <iostream>

class Fruit
{
    protected:
    std::string name;
    const int _vitamins;

    public:
    explicit Fruit(int vitamins);
    ~Fruit();
    int getVitamins() const;
    const std::string getName() const;
};

#endif