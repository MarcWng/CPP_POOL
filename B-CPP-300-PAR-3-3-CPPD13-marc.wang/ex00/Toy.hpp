/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Toy.hpp
*/

#ifndef TOY_HPP
#define TOY_HPP

#include <iostream>
#include "Picture.hpp"

class Toy
{
    public:
    enum ToyType {
    BASIC_TOY,
    ALIEN,
    };
    Toy();
    Toy(ToyType type, std::string name, std::string filename);
    ~Toy();
    ToyType getType() const;
    const std::string getName() const;
    void setName(std::string name);
    bool setAscii(const std::string filename);
    const std::string getAscii() const;

    private:
    const ToyType type;
    std::string name;
    Picture pic;
};

#endif