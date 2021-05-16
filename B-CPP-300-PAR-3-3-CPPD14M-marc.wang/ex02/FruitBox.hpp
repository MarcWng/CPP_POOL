/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** FruitBox.hpp
*/

#ifndef FRUITBOX_HPP
#define FRUITBOX_HPP
#include "FruitNode.hpp"

class FruitBox
{
    public:
    FruitBox(int size);
    ~FruitBox();
    int nbFruits() const;
    bool putFruit(Fruit *f);
    Fruit *pickFruit();
    const FruitNode *head() const;
    int getSize() const;

    private:
    FruitNode *_head;
    const int _size;
    int _fruit_count;
};

#endif