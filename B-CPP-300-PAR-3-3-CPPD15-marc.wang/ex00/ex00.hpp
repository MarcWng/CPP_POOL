/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex00.hpp
*/

#ifndef EX00_HPP
#define EX00_HPP

template<typename T>

void swap(T &a, T &b)
{
    T cpy = b;

    b = a;
    a = cpy;
}

template<typename T>
T min(T a, T b)
{
    if (a >= b)
        return b;
    else
        return a;
}

template<typename T>
T max(T a, T b)
{
    if (a <= b)
        return b;
    else
        return a;
}

template<typename T>
T add(T a, T b)
{
    return a + b;
}

#endif