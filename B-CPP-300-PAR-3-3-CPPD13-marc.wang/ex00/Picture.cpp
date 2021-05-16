/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Picture.cpp
*/

#include "Picture.hpp"
#include <fstream>
#include <sstream>
Picture::Picture() : data("")
{
}
Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}
Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    const std::ifstream input_stream(file);

    if (input_stream.fail()) {
        this->data = "ERROR";
        return false;
    }
    std::stringstream buffer;
    buffer << input_stream.rdbuf();
    this->data = buffer.str();
    return true;
}