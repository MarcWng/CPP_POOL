/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD08-marc.wang
** File description:
** main.cpp
*/

#include "Droid.hpp"

int main ()
{
    Droid d;
    const Droid e;
    d = e;
DroidMemory mem1 ;
mem1 += 42;
DroidMemory mem2 = mem1 ;
std :: cout << mem1 << std :: endl ;
DroidMemory mem3 ;
mem3 << mem1 ;
mem3 >> mem1 ;
mem3 << mem1 ;
std :: cout << mem3 << std :: endl ;
std :: cout << mem1 << std :: endl ;
}