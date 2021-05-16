/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** Hostname.hpp
*/

#include "BaseInfo.hpp"

class Hostname : public BaseInfo
{
    public:
    Hostname();
    ~Hostname();
    const std::string getInfo() const override;
};