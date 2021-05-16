/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** KoalaBot.hpp
*/

#ifndef PARTS_HPP
#define PARTS_HPP

#include <string>
#include <iostream>

class Arms
{
private:
    std::string _name;
    std::string _serial;
    bool _functionnal;
public:
    bool isFunctional();
    std::string serial();
    void informations();

    Arms(std::string serial = "A-01", bool functional = true);
    ~Arms();
};

class Legs
{
private:
    std::string _name;
    std::string _serial;
    bool _functionnal;
public:
    bool isFunctional();
    std::string serial();
    void informations();
    Legs(std::string serial = "L-01", bool functional = true);
    ~Legs();
};

class Head
{
private:
    std::string _name;
    std::string _serial;
    bool _functionnal;
public:
    bool isFunctional();
    std::string serial();
    void informations();
    Head(std::string serial = "H-01", bool functional = true);
    ~Head();
};
#endif