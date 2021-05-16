/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit(int vitamins) : name(""), _vitamins(vitamins)
{
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
    return this->_vitamins;
}

const std::string Fruit::getName() const
{
    return this->name;
}