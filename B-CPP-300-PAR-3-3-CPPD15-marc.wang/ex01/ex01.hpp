/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex01.hpp
*/

#ifndef EX01_HPP
#define EX01_HPP
#include <cstring>
#include <iomanip>
#include <memory>

class toto
{
    public:

    toto() = default;
    toto &operator=(const toto&) = delete;
    bool operator==(const toto&) const {return true;}
    bool operator>(const toto&) const {return false;}
    bool operator<(const toto&) const {return false;}
    private:
    toto(const toto &){};
};

template<typename T>
int compare(T const &a, T const &b)
{
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    return -1;
}

template<>
int compare<const char*>(char const * const &a, char const * const &b)
{
    int ret = strcmp(a, b);

    if (ret > 0)
        return 1;
    if (ret < 0)
        return -1;
    return 0;
}

#endif