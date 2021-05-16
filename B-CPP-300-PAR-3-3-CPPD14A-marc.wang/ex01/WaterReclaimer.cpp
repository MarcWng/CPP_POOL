
#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"
#include <exception>

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}

void
WaterReclaimer::start()
{
    if (_water == 0)
        throw(MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer"));
    _started = true;
}

void
WaterReclaimer::useWater(int water)
{
    if (_started == false)
        throw(UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer"));
    if (_water - water < 10)
        throw(LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer"));
    else if (water < 0)
        throw(UserError("Water use should be positif.", "WaterReclaimer"));
    _water -= water;
}

void
WaterReclaimer::generateWater()
{
    static bool which = false;
    if (_water + 10 > 100) {
        if (which == false) {
            which = true;
            throw(NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer"));
        } else {
            which = false;
            throw(std::exception());
        }
    }
    _water += 10;
}
