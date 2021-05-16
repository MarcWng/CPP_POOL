/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaDoctor.cpp
*/

#include "KoalaDoctor.hpp"
#include <iostream>
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
    this->work = false;
    this->destroy = false;
}

KoalaDoctor::~KoalaDoctor()
{
    this->timeCheck();
}

void KoalaDoctor::timeCheck()
{
    if (this->destroy == false && this->work == false) { 
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
        this->work = true;
    }
    if (this->destroy == true && this->work == true) {
        this->work = false;
        std::cout << "Dr."<< this->name <<": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::ofstream myfile;
    std::string filename(koala->getName());
    int rand = 0;

    timeCheck();
    std::cout << "Dr."<< this->name << ": So what's goerking you Mr." << koala->getName() << "?" << std::endl;
    filename.append(".report");
    koala->poke();
    myfile.open(filename);
    rand = random() % 5;
    switch (rand) {
    case 1:
        myfile << "Mars";
        break;
    case 2 :
        myfile << "Kinder";
        break;
    case 3 :
        myfile << "Crunch";
        break;
    case 4 :
        myfile << "Maroilles";
        break;
    default:
        myfile << "Eucalyptus leaf";
        break;
    }
    myfile.close();
}

std::string KoalaDoctor::getName()
{
    return(this->name);
}