/**
 * @name Sensor.cpp
 * @date 2025.05.14
 */

#include "Sensor.h"
#include "Measurement.h"
#include "Time.h"
#include <sstream>
#include <iostream>

Sensor::Sensor() {
     sensorID = "";
     latitude = 0.0;
     longitude = 0.0;
}

Sensor::Sensor(const string& sensor_str) {

     stringstream ss(sensor_str);
     string token;

     getline(ss,token,';');
     sensorID = token;

     getline(ss,token,';');
     latitude = stod(token);
     getline(ss,token,';');
     longitude = stod(token);

}

string Sensor::get_sensorID() const {
     return sensorID;
}

double Sensor::get_lat() const {
     return latitude;
}

double Sensor::get_long() const {
     return longitude;
}

void Sensor::setSensorId(string sensor_id){
    this->sensorID = sensor_id;
}
void Sensor::setLatitude(double new_lat) {
    this->latitude = new_lat;
}
void Sensor::setLongitude(double new_long) {
    this->longitude = new_long;
}


Sensor::~Sensor() {
}
pair<double, double> Sensor::get_coord_gps()
{
  return make_pair(latitude,longitude);
}

vector<Measurement> Sensor::get_measurements(const vector<Measurement>& list_measurement, const Time& debut) const
{
    vector<Measurement> result;

    for (const Measurement& meas : list_measurement) {
        if (meas.getSensor_id() != this->sensorID) {
            continue; // only keep measurements from this sensor
        }

        Time stamp = meas.getTimeStamp();

        // Assuming Time class has a method to compare times
        if (debut <= stamp) {
            result.push_back(meas);
        }
    }

    return result;
}

ostream& operator<<(ostream& os, const Sensor s) {
    os << "Id : " << s.sensorID << " | Latitude : " << s.latitude << " | Longitude : " << s.longitude <<  endl;
    return os;
};
