/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPrush3-gael.baron
** File description:
** InfoManager.cpp
*/

#include "InfoManager.hpp"
#include <algorithm>
#include <unistd.h>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "RAM.hpp"

#define module(i) this->_CpuModules[this->_CpuModules.size() - 1 - i]

InfoManager::InfoManager() : _BaseModules(0), cpu_nb(sysconf(_SC_NPROCESSORS_ONLN) + 1), _CpuModules(0)
{
}

InfoManager::~InfoManager()
{
}

const std::vector<BaseInfo*> InfoManager::getModules() const
{
    return this->_BaseModules;
}

std::string const InfoManager::findModule(std::string name) const
{
    for (std::size_t i = 0; i < this->_BaseModules.size() &&
    this->_BaseModules[this->_BaseModules.size() - 1 - i] != NULL; ++i) {
        if (this->_BaseModules[this->_BaseModules.size() - 1 - i]->getModuleName().compare(name) == 0)
            return this->_BaseModules[this->_BaseModules.size() - 1 - i]->getInfo();
    }
    throw (std::invalid_argument("Bad module name"));
}

void InfoManager::addModule(BaseInfo *module)
{
    this->_BaseModules.push_back(module);
}

void InfoManager::addModule(MonitorCore *core)
{
    this->_CpuModules.push_back(core);
}

void InfoManager::resetCores()
{
    this->_CpuModules.clear();
}

void InfoManager::resetRAM()
{
    std::vector<MonitorCore *>::iterator it;

    for (std::size_t i = 0; i < this->_CpuModules.size() && module(i) != NULL; ++i) {
        if (module(i)->getModuleName().compare("RAM") == 0) {
            it = this->_CpuModules.end() - 1 - i;
            this->_CpuModules.erase(it);
        }
    }
}

void InfoManager::resetNetwork()
{
    std::vector<MonitorCore *>::iterator it;

    for (std::size_t i = 0; i < this->_CpuModules.size() && module(i) != NULL; ++i) {
        if (module(i)->getModuleName().compare("Network") == 0) {
            it = this->_CpuModules.end() - 1 - i;
            this->_CpuModules.erase(it);
        }
    }
}

void InfoManager::setAllCore()
{
    std::ifstream file("/proc/stat");
    std::string coreLine;
    int total_usage = 0;

    this->_CpuModules.reserve(this->cpu_nb);
    for (long int i = 0; i != this->cpu_nb; i++){
        getline(file, coreLine);
        addModule(new MonitorCore(coreLine));
    }
    for (std::size_t i = 0; i < this->_CpuModules.size() && module(i) != NULL; ++i) {
        std::string res = module(i)->getModuleName();
        res.append(" ");
        res.append(boost::lexical_cast<std::string>(module(i)->getUsage()));
        res.append("%");
        module(i)->setInfo(res);
    }
}

int InfoManager::getCpuNb()
{
    return (this->cpu_nb);
}

const std::vector<MonitorCore*> InfoManager::getCores() const
{
    return this->_CpuModules;
}

float InfoManager::findCoreValue(std::string name) const
{
    for (std::size_t i = 0; i < this->_CpuModules.size() && module(i) != NULL; ++i) {
        if (module(i)->getModuleName().compare(name) == 0)
            return module(i)->getUsage();
    }
    throw (std::invalid_argument("Bad CPU name"));
}

const std::string InfoManager::findCore(std::string name) const
{
    for (std::size_t i = 0; i < this->_CpuModules.size() && module(i) != NULL; ++i) {
        if (module(i)->getModuleName().compare(name) == 0)
            return module(i)->getInfo();
    }
    throw (std::invalid_argument("Bad CPU name"));
}
