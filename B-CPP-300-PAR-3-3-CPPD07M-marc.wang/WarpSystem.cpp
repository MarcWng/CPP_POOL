/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

namespace WarpSystem {
    QuantumReactor::QuantumReactor()
    {
        this->_stability = true;
    }   

    QuantumReactor::~QuantumReactor()
    {
    }

    Core::Core()
    {
    }

    Core::Core(QuantumReactor *coreReactor)
    {
        this->_coreReactor = coreReactor;
    }

    Core::~Core()
    {
    }

    bool QuantumReactor::isStable()
    {
        return this->_stability;
    }

    void QuantumReactor::setStability(bool stability)
    {
        this->_stability = stability;
    }
    
    QuantumReactor *Core::checkReactor()
    {
        return this->_coreReactor;
    }
}