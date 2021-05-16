/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** BaseInfo.hpp
*/

#ifndef BASEINFO_HPP
#define BASEINFO_HPP
#include "IMonitorModule.hpp"

class BaseInfo : public IMonitorModule
{
    public:
    BaseInfo();
    ~BaseInfo();
    BaseInfo(const BaseInfo &info);
    BaseInfo &operator=(const BaseInfo &info);
    void setShow(bool state);
    const std::string getInfo() const;
    bool getShow() const;
    const std::string getModuleName() const;

    protected:
    bool _show;
    std::string _info;
    std::string _moduleName;
};

#endif
