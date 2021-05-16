/*
** EPITECH PROJECT, 2021
** Toys
** File description:
** functions
*/

#include "Toys.hpp"

Teddy::Teddy(std::string const title): Object(title), Toy(title)
{
}

Teddy::~Teddy(void)
{
}

void Teddy::isTaken(void)
{
    std::cout << "gra hu" << std::endl;
}

LittlePony::LittlePony(std::string const title): Object(title), Toy(title)
{
}

LittlePony::~LittlePony(void)
{
}

void LittlePony::isTaken(void)
{
    std::cout << "yo man" << std::endl;
}
