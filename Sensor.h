<<<<<<< HEAD
/**
 * @name Sensor.h
 * @date 2025.05.14
 *
 */

#ifndef _SENSOR_H
#define _SENSOR_H

#include <string>
#include <vector>
#include <utility>

#include "Measurement.h"
#include "Time.h"

class Sensor
{
private:
    std::string sensorID;
    double latitude;
    double longitude;

public:
    std::pair<double, double> get_coord_gps();
    std::vector<Measurement> get_measurements(Time debut);
}
