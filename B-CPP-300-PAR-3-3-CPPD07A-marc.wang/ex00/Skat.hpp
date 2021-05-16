/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Skat.hpp
*/

#ifndef SKAT_H
#define SKAT_H

#include <string>
#include <iostream>

class Skat
{
    public:
    // Skat(const std::string &name = "bob");
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
    int &stimPaks();
    private:
    std::string _name;
    int _stimPaks;
};

#endif