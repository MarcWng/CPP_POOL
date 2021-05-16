/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** GiftPaper.hpp
*/

#ifndef GIFTPAPER_HPP
#define GIFTPAPER_HPP

#include "Box.hpp"

class GiftPaper : public Wrap
{
    private:
    Object *gift_box;
    public:
    GiftPaper();
    ~GiftPaper();
    void wrapMeThat(Object *gift_box);
    const Object *openMe();
    void closeMe(){};
};

#endif