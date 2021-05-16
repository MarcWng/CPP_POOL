/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14M-marc.wang
** File description:
** main.cpp
*/

#include "Lemon.hpp"
#include "Banana.hpp"
#include <iostream>

int main ()
{
Lemon l ;
Banana b ;
std :: cout << l . getVitamins () << std :: endl ;
std :: cout << b . getVitamins () << std :: endl ;
std :: cout << l . getName () << std :: endl ;
std :: cout << b . getName () << std :: endl ;
Fruit & f = l ;
std :: cout << f . getVitamins () << std :: endl ;
std :: cout << f . getName () << std :: endl ;
return 0;
}