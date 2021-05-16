/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07M-marc.wang
** File description:
** WarpSystem.hpp
*/

#ifndef WARPSYSTEM_H
#define WARPSYSTEM_H

namespace WarpSystem {
    class Core;
    class QuantumReactor
    {
    private:
        bool _stability ;
    public:
        QuantumReactor();
        ~QuantumReactor();
        bool isStable();
        void setStability(bool stability);
    };
    class Core
    {
    private:
        QuantumReactor *_coreReactor;
    public:
        Core();
        Core(QuantumReactor *coreReactor);
        ~Core();
        QuantumReactor *checkReactor();
    };
}

#endif