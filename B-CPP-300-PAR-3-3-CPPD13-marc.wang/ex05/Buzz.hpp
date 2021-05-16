/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Buzz.hpp
*/

#ifndef BUZZ_HPP
#define BUZZ_HPP
#include "Toy.hpp"

class Buzz : public Toy
{
private:
public:
    Buzz(std::string name, std::string ascii = "buzz.txt");
    ~Buzz();
    virtual void speak(std::string msg);
    bool speak_es(std::string msg);
};

#endif