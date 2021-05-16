/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD06-marc.wang
** File description:
** my_cat.cpp
*/

#include <string.h>
#include <iostream>
#include <fstream>

int my_cat(char **files)
{
    int i = 0;
    char c;
    std::ifstream myfile(files[0]);

    if (myfile.is_open()) {
        while (myfile.get(c))
            std::cout << c;
        i++;
        my_cat(&files[i]);
    } else if (files[0] != NULL){
        	std::cerr << "my_cat: " << files[0] << ": " <<
            "No such file or directory" << std::endl;
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    std::string line;

    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 84;
    }
    else
        return (my_cat(&av[1]));
}
