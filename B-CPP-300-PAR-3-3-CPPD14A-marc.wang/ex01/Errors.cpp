/*
** EPITECH PROJECT, 2020
** B-CPP-300-PAR-3-3-CPPD14A-marc.wang
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) :
    _message(message), _component(component)
{
}
NasaError::~NasaError() noexcept
{
}

std::string const &NasaError::getComponent() const noexcept
{
    return this->_component;
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "CommunicationDevice")
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

const char *NasaError::what() const noexcept
{
    return this->_message.c_str();
}