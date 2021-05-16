/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** main.cpp
*/

#include "ex02.hpp"
using namespace std;

int main()
{
    int tab [2] = {3 , 0};
    int minimum = templateMin(tab, 2);

    cout << "templateMin(tab, 2) = " << minimum << endl ;
    minimum = nonTemplateMin ( tab , 2) ;
    cout << "nonTemplateMin(tab, 2) = " << minimum << endl ;
}