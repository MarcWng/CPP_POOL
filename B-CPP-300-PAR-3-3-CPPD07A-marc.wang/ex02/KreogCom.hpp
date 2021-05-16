/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD07A-marc.wang
** File description:
** KreogCom.hpp
*/

#ifndef KREOGCOM_HPP
#define KREOGCOM_HPP

class KreogCom
{
    public:
    KreogCom(int x, int y, int serial);
    ~KreogCom();
    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom();
    void ping();
    void locateSquad();

    private:
    const int x;
    const int y;
    const int m_serial;
};

#endif