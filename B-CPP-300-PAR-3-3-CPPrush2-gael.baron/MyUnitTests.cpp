/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush2-gael.baron
** File description:
** MyUnitTests.cpp
*/

#include "GiftPaper.hpp"
#include "Toys.hpp"

Object *MyUnitTests(Object** obj)
{
    ((Box*)obj[1])->wrapMeThat(obj[0]);
    ((GiftPaper*)obj[2])->wrapMeThat(obj[1]);
    return obj[2];
}

Object **MyUnitTests(void)
{
    Object **obj = new Object*;

    obj[0] = new LittlePony("happy pony");
    obj[1] = new Teddy("cuddles");
    return (obj);
}
