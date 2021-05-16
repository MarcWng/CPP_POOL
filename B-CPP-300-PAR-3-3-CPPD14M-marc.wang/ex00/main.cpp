/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** main.cpp
*/

#include "Lemon.hpp"
#include "Banana.hpp"
#include <iostream>
#include "FruitBox.hpp"

int main ()
{
    Lemon l;
    Banana b;
    FruitBox box(2);

    if (box.putFruit(&l) == false)
        std::cout << "fail\n";
    if (box.putFruit(&b) == false)
        std::cout << "fail\n";
    if (box.putFruit(&b) == false)
        std::cout << "this should print cuz it fail\n";
    if (box.pickFruit() == &l)
        std::cout << "pick lemon success\n";
    if (box.pickFruit() == &b)
        std::cout << "pick banana success\n";
    if (box.pickFruit() == &b)
        std::cout << "this shouldnt print\n";
    return 0;
}