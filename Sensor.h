
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
using namespace std;

class Sensor {
  friend ostream& operator<<(ostream& os, const Sensor s);

private:
    string sensorID;
    double latitude;
    double longitude;

public:

    string get_sensorID() const;
    double get_lat() const;
    double get_long() const;

    void setSensorId(string sensor_id);
    void setLatitude(double new_lat);
    void setLongitude(double new_long);

    pair<double, double> get_coord_gps();
    vector<Measurement> get_measurements(const vector<Measurement>& list_measurement, const Time& debut) const;


    //Constructor
    Sensor();
    Sensor(const string& sensor_str);

    //Destructor
    virtual ~Sensor();
};

#endif //SENSOR_H
