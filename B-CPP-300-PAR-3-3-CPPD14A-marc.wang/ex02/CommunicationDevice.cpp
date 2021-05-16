
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
try : _api(input, output) {
} catch (std::exception const &except) {
    std::string str = "Error: ";
    str.append(except.what());
    throw CommunicationError(str);
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try {
		for (size_t i = 0; i < nbUsers; ++i)
			_api.addUser(users[i]);
		_api.startMission(missionName);
	} catch (std::logic_error const &except) {
        std::string str = "LogicError: ";
        str.append(except.what());
		throw CommunicationError(str);
	} catch (std::runtime_error const &except) {
        std::string str = "RuntimeError: ";
        str.append(except.what());
		throw CommunicationError(str);
	} catch (std::exception const &except) {
        std::string str = "Error: ";
        str.append(except.what());
		throw CommunicationError(str);
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
    _api.sendMessage(user, message);
    } catch (std::invalid_argument arg) {
        std::cerr << arg.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
    _api.receiveMessage(user, message);
    } catch (std::invalid_argument arg) {
		std::cerr << "INVALID MESSAGE" << std::endl;
    }
}
