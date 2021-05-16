/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** Box.hpp
*/

#ifndef BOX_HPP
#define BOX_HPP

#include "Wrap.hpp"

class Box : public Wrap
{
    private:
    Object *gift;
    bool is_open;
    public:
    Box();
    ~Box();
    const Object *openMe() override;
    void wrapMeThat(Object *gift);
    void closeMe() override;
    bool isOpen();
};


#endif
