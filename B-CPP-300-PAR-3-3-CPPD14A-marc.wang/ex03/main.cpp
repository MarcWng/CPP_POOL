#include <stdexcept>
#include "SimplePtr.hpp"
#include "WaterReclaimer.hpp"
#include "AtmosphereRegulator.hpp"
#include <iostream>

int main ()
{
    try {
        SimplePtr regulator(new AtmosphereRegulator);
        SimplePtr reclaimer(new WaterReclaimer);
        // The code above shouldn 't be changed .
        throw std::runtime_error("An error occured here !") ;
    }
    catch (...) {
        std::cout << "ici" << std::endl;
    }
    return 0;
}
