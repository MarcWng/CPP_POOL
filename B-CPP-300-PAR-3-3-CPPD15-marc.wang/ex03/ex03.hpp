/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex03.hpp
*/

#ifndef EX03_HPP
#define EX03_HPP

#include <iostream>

template<typename T>
void foreach(T *array, void (func)(const T &), int size)
{
    for (int i = 0; i < size; i++)
        (*func)(array[i]);
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif