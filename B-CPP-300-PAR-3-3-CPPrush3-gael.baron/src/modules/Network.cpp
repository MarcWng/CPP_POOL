/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** Network.cpp
*/

#include "Network.hpp"
#include <fstream>
#include <vector>
#include <algorithm>

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
std::string remove_spaces(std::string line)
{
    std::string::iterator new_end = std::unique(line.begin(), line.end(),
    [=](char str1, char str2) { return (str1 == str2) && (str1 == ' '); });
    line.erase(new_end, line.end());
    return line.substr(7);
}

std::string Network::calculateNetwork()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    std::vector<size_t> list;
    std::string ret = "Transmitted packets :";
    int i = 0;

    while (std::getline(file, line)) {
        if (line.substr(i, line.find(' ', i + 1) - i).compare("wlp2s0:") == 0)
            break;
    }
    i = line.find(' ', i);
    line = remove_spaces(line);
    while (i != std::string::npos) {
        list.push_back(stoi(line.substr(i, line.find(' ', i + 1) - i)));
        i = line.find(' ', i + 1);
    }
    ret.append(std::to_string(list[9]));
    ret.append("\nReceived packets :");
    ret.append(std::to_string(list[1]));
    return ret;
}

Network::Network() : BaseInfo()
{
    this->_info = calculateNetwork();
    this->_moduleName = "Network";
    
}

Network::~Network()
{
}