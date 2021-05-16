/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD15-marc.wang
** File description:
** ex05.hpp
*/

#ifndef EX05_HPP
#define EX05_HPP

template<typename T>
class array
{
private:
public:
    array();
    array(unsigned int n);
    array(array const &cpy);
    array &operator=(array const &a2)
    array(unsigned int n);
    ~array();
};

template<typename T>
array<T>::array()
{
}

template<typename T>
array<T>::array(unsigned int n)
{
}

template<typename T>
array<T>::array(array const &cpy)
{
}

template<typename T>
array &array<T>::operator=(array const &a2)
{
}
template<typename T>
array<T>::~array()
{
}


#endif