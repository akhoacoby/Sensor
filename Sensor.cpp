/**
 * @name Sensor.cpp
 * @date 2025.05.14
 */

#include "Sensor.h"
#include "measurement.h"
#include "time.h"
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

Sensor::~Sensor() {
}
pair<double, double> Sensor::get_coord_gps()
{
  return make_pair(latitude,longitude);
}

vector<Measurement> Sensor::get_measurements(vector<Measurement> list_measurement, Time debut)
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

int main() {
    Time debut("2019-01-01 12:00:00");

    Measurement m1("2019-01-01 12:00:00;Sensor0;NO2;74.5;");
    Measurement m2("2019-01-02 12:00:00;Sensor0;PM10;50.5;");
    Measurement m3("2018-12-31 23:59:59;Sensor0;O3;12.3;");

    vector<Measurement> all_measurements = {m1, m2, m3};

    Sensor s("Sensor0;44;-1;");
    auto results = s.get_measurements(all_measurements, debut);

    for (const Measurement& m : results) {
        std::cout << m << std::endl; // assuming toString() method
    }

    return 0;
}