/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** main.cpp
*/

#include <iostream>
#include <string>
#include <iomanip>

void convert(float temp, int base)
{
    std::cout << std::fixed;

    if (base == 0) {
        temp = (temp * 9 / 5) + 32;
        std::cout << std::setw(16) << std::setprecision(3) <<
        temp << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (base == 1) {
        temp = ((temp - 32) * 5 )/ 9;
        std::cout << std::setw(16) << std::setprecision(3) <<
        temp << std::setw(16) << "Celsius" << std::endl;
    }
}

int main()
{
    std::string base_temp;
    float temp = 0;

    std::cin >> temp >> base_temp;
    if (base_temp.empty())
        return 84;
    if (!base_temp.compare("Fahrenheit")) {
        convert(temp, 1);
        return 0;
    }
    if (!base_temp.compare("Celsius")) {
        convert(temp, 0);
        return 0;
    }
}