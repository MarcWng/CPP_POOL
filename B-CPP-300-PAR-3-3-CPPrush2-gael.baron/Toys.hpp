/*
** EPITECH PROJECT, 2021
** Toys
** File description:
** header
*/

#ifndef TOYS_HPP_
#define TOYS_HPP_

#include "Objects.hpp"

class Teddy : virtual public Toy
{
public:
    Teddy(std::string const title);
    ~Teddy();
    void isTaken();
};

class LittlePony : virtual public Toy
{
public:
    LittlePony(std::string const title);
    ~LittlePony();
    void isTaken();
};

Object **MyUnitTests();

#endif
