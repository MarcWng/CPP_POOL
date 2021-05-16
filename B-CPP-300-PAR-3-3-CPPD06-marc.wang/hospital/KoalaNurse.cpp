/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** KoalaNurse.cpp
*/

#include "KoalaNurse.hpp"
#include <fstream>

KoalaNurse::KoalaNurse(int ID)
{
    this->ID = ID;
    this->check = false;
    this->destroying = false;
}

KoalaNurse::~KoalaNurse()
{
    this->destroying = true;
    this->timeCheck();
    std::cout << "Nurse " << this->ID << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    this->timeCheck();
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::ifstream file;
    std::string drug;
    std::string koala_name;

    this->timeCheck();
    file.open(report);
    if (!file.is_open()) {
        this->timeCheck();
        return drug;
    }
    if (report.find(".report", report.length() - 7, 7) == report.length() - 7) {
        koala_name = report.substr(0, report.length() - 7);
        std::cout << "Nurse" << this->ID << ": Kreog! Mr." << " needs a ";
        std::getline(file, drug);
        std::cout << drug << std::endl;
    }
    file.close();
    return drug;
}

void KoalaNurse::timeCheck()
{
    if (this->check == false && this->destroying == false) {
        std::cout << "Nurse " << this->ID << ": Time to get to work!" << std::endl;
        this->check = true;
    }
    else if (this->check == true && this->destroying == true) {
        std::cout << "Nurse "<< this->ID <<": Time to go home to my eucalyptus forest!" << std::endl;
        this->check = false;
    }
}

int KoalaNurse::getID()
{
    return (this->ID);
}