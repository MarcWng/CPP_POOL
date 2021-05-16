/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD13-marc.wang
** File description:
** Toy.hpp
*/

#ifndef TOY_HPP
#define TOY_HPP

#include <iostream>
#include <exception>
#include "Picture.hpp"

class Toy
{
    public:
    class Error;
    enum ToyType {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
    };
    Toy();
    Toy(const Toy &toy);
    Toy(ToyType type, std::string name, std::string filename);
    ~Toy();
    Toy &operator=(const Toy &toy);
    ToyType getType() const;
    const std::string getName() const;
    void setName(std::string name);
    bool setAscii(std::string filename);
    const std::string getAscii() const;
    virtual void speak(std::string msg);
    virtual bool speak_es(std::string msg);
    const Toy &operator<<(const std::string &pic);
    class Error : std::exception
    {
        public:
        enum ErrorType {
            UNKNOWN,
            PICTURE,
            SPEAK
        };
        Error();
        Error(ErrorType error);
        ~Error();
        const char *what() const noexcept;
        const char *where() const noexcept;
        ErrorType type;
    };
    Error getLastError() const;
    Error err;
    protected:
    const ToyType type;
    std::string name;
    Picture pic;
};

std::ostream &operator<<(std::ostream &stream, const Toy &t);

#endif