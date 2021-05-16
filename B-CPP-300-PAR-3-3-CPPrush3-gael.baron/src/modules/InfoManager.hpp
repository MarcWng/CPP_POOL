/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** InfoManager.hpp
*/

#ifndef INFOMANAGER_HPP
#define INFOMANAGER_HPP
#include <vector>
#include "BaseInfo.hpp"
#include "MonitorCore.hpp"

class InfoManager
{
    public:
    InfoManager();
    ~InfoManager();
    const std::vector<BaseInfo*> getModules() const;
    const std::string findModule(std::string name) const;
    const std::vector<MonitorCore*> getCores() const;
    void resetCores();
    void resetRAM();
    void resetNetwork();
    const std::string findCore(std::string name) const;
    float findCoreValue(std::string name) const;
    void addModule(BaseInfo *module);
    void addModule(MonitorCore *core);
    void setAllCore();
    int getCpuNb();

    private:
    std::vector<BaseInfo*> _BaseModules;
    int cpu_nb;
    std::vector<MonitorCore*> _CpuModules;
};

#endif
