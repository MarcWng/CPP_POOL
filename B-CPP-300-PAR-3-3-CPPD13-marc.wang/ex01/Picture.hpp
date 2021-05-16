/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Picture.hpp
*/

#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iostream>

class Picture
{
    public:
    Picture();
    Picture(const Picture &pic);
    Picture(const std::string &file);
    ~Picture();
    Picture &operator=(const Picture &pic);
    bool getPictureFromFile(const std::string &file);
    std::string data;
};

#endif