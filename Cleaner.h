/**
 * @name AirCleaner.h
 * @date 2025.05.14
 *
 */

#ifndef _AIRCLEANER_H
#define _AIRCLEANER_H
#include <string>

#include "Time.h"

class AirCleaner
{
  private:
    std::string CleanerID;
    double latitude;
    double longitude;
    Time startTime;
    Time stopTime;
}
