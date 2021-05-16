/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** main.cpp
*/

#include "find.hpp"
#include <iostream>

int main()
{
    std::vector<int> tab;

    tab.push_back(1);
    tab.push_back(2);
    tab.push_back(3);
    tab.push_back(54);
    tab.push_back(4);
    tab.push_back(5);
    auto it = do_find(tab, 54);
    std::cout << *it << std::endl;
}