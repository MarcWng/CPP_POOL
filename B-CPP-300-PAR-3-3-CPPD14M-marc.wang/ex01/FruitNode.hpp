/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** FruitNode.hpp
*/

#include "Fruit.hpp"

struct FruitNode {
    Fruit *fruit;
    FruitNode *next;
};