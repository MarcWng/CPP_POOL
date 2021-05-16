/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Woody.hpp
*/

#ifndef WOODY_HPP
#define WOODY_HPP
#include "Toy.hpp"

class Woody : public Toy
{
private:
public:
    Woody(std::string name, std::string ascii = "woody.txt");
    ~Woody();
    void speak(std::string msg);
    bool speak_es(std::string msg);
};

#endif