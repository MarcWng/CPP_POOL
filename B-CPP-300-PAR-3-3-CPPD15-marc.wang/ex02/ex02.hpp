/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex02.hpp
*/

#ifndef EX02_HPP
#define EX02_HPP
#include <iostream>

template<typename T>
const T min(T const a, T const b)
{
    std::cout << "template min" << std::endl;
    if (a > b)
        return b;
    return a;
}

int min(int a, int b)
{
    int ret;

    std::cout << "non-template min" << std::endl;
    if (a > b)
        ret = b;
    if (a <= b)
        ret = a;
    return ret;
}

template<typename T>
const T templateMin(T const *array, int size)
{
    T ret = array[0];

    if (size == 1)
        return array[0];
    if (size > 1)
        ret = array[0];
    for (int i = 1; i != size; i++) {
        ret = min<T>(array[i], ret);
    }
    return ret;
}

int nonTemplateMin(int *array, int size)
{
    int ret = 0;

    if (size == 1)
        return array[0];
    if (size > 1)
        ret = array[0];
    for (int i = 1; i != size; i++) {
        ret = min(array[i], ret);
    }
    return ret;
}

#endif