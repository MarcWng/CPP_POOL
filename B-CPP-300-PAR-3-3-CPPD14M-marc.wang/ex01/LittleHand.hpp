/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** LittleHand.hpp
*/

#ifndef LITTLEHAND_HPP
#define LITTLEHAND_HPP

#include "FruitBox.hpp"

class LittleHand
{
private:
public:
    LittleHand();
    ~LittleHand();
    void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);
};

#endif