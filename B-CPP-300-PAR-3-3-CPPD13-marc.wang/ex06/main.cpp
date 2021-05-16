/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** main.cpp
*/

#include <iostream>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"
#include "ToyStory.hpp"

int main ()
{
    Buzz b ("buzzi");
    Woody w ("wood");
    ToyStory::tellMeAStory("azz.txt", b, &Toy::speak_es, w, &Toy::speak);
    ToyStory::tellMeAStory("azz.txt", b, &Toy::speak_es, w, &Toy::speak);
    ToyStory::tellMeAStory("story.txt", b, &Toy::speak_es, w, &Toy::speak);
    
}