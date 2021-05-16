/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** main.cpp
*/

#include <iostream>
#include "ex04.hpp"

int main ()
{
std :: cout << "1 == 0 ? " << equal (1 , 0) << std :: endl ;
std :: cout << "1 == 1 ? " << equal (1 , 1) << std :: endl ;
Tester <int > iT ;
std :: cout << "41 == 42 ? " << iT . equal (41 , 42) << std :: endl ;
std :: cout << "42 == 42 ? " << iT . equal (42 , 42) << std :: endl ;
return 0;
}