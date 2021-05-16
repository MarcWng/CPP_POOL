/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** MonitorCore.hpp
*/

#ifndef MONITORCORE_HPP
#define MONITORCORE_HPP
#include <vector>
#include "IMonitorModule.hpp"

class MonitorCore : public IMonitorModule
{
    public:
    enum cpu_info {
        NAME,
        USER,
        NICE,
        SYSTEM,
        IDLE,
        IOWAIT,
        IRQ,
        SOFTIRQ
    };
    MonitorCore(std::string name);
    MonitorCore(const MonitorCore &core);
    MonitorCore &operator=(const MonitorCore &core);
    void setShow(bool state);
    ~MonitorCore();
    void setInfo(std::string info);
    const std::string getInfo() const;
    const std::string getModuleName() const;
    float getUsage() const;
    void setUsage(float usage);
    void calculateUsage(std::string str);

    private:
    std::string _info;
    std::string _name;
    float _usage;
    bool _show;
};

#endif