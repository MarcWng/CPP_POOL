/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD17-marc.wang
** File description:
** find.hpp
*/

#ifndef FIND_HPP
#define FIND_HPP
#include <algorithm>
#include <list>
#include <vector>

template<typename T>
auto do_find(T &a, int nb)
{
    return std::find(std::begin(a), std::end(a), nb);
};

#endif