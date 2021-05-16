/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** Network.hpp
*/

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "BaseInfo.hpp"

class Network : public BaseInfo
{
public:
    Network();
    ~Network();
    std::string calculateNetwork();
};

#endif