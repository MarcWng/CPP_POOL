/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** Wrap.hpp
*/

#ifndef WRAP_HPP
#define WRAP_HPP

#include "Objects.hpp"

class Wrap : public Object
{
    public:
    Wrap(std::string title);
    ~Wrap();
    void wrapMeThat(Object obj);
    virtual const Object *openMe() = 0;
    virtual void closeMe() = 0;
};

#endif
