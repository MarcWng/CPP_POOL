/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** ToyStory.cpp
*/

#include "ToyStory.hpp"
#include <fstream>
#include <sstream>

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

bool ToyStory::tellMeAStory(std::string filename, Toy &toy1, bool(Toy::*func1)(std::string), Toy &toy2, bool(Toy::*func2)(std::string))
{
    std::ifstream myfile(filename);
    std::string line;
    char c;
    bool which = false;

    if (myfile.fail()) {
        std::cout << "Bad story" << std::endl;
        return true;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    while (myfile.get(c)) {
        if (c != '\n')
            line += c;
        else {
            if (line.compare(0, 8, "picture:", 8) == 0) {
                line.erase(0, 8);
                if (which == false) {
                    if (toy1.setAscii(line) == false) {
                        std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() << std::endl;
                        return false;
                    }
                    std::cout << toy1.getAscii() << std::endl;
                } else {
                    if (toy2.setAscii(line) == false) {
                        std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() << std::endl;
                        return false;
                    }
                    std::cout << toy2.getAscii() << std::endl;
                }
            } else if (which == false) {
                if ((toy1.*func1)(line) == false)
                    return false;
                which = true;
            } else {
                if ((toy2.*func2)(line) == false)
                    return false;
                which = false;
            }
            line.clear();
        }
    }
    return true;
}
