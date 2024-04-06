//
// Created by Christopher Buhendwa on 4/3/24.
//
#include <iostream>

#include "myTime.h"
#include <iostream>

bool Time::Equal(Time otherTime) const
// Postcondition: Return value == true,
// if this time equals otherTime,
// otherwise == false
{
    return ((hrs == otherTime.hrs)
            && (mins == otherTime.mins)
            && (secs == otherTime.secs));
}