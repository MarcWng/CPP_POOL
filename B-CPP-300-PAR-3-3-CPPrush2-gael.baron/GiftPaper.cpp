/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** GiftPaper.cpp
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper() : Wrap("GiftPaper"), gift_box(nullptr)
{
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(Object *gift_box)
{
    if (this->gift_box == nullptr)
        this->gift_box = gift_box;
}

const Object *GiftPaper::openMe()
{
    return (this->gift_box);
}