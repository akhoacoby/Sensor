/*************************************************************************
                                Measurement
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Measurement> realization (file Measurement.cpp) ------------
#include "Measurement.h"

// CONSTRUCTORS
Measurement::Measurement(){
 timeStamp = Time();
 attribute_id = "";
 value = 0;
 sensor_id = "";
};

Measurement::Measurement(const string& str){
 stringstream ss(str);
 string field;

 string timeStamp_str = "";
 string value_str = "";

 getline(ss, timeStamp_str, ';');
 getline(ss, sensor_id, ';');
 getline(ss, attribute_id, ';');
 getline(ss, value_str, ';');

 value = stod(value_str);
 timeStamp = Time(timeStamp_str);

};

// DESTRUCTOR

Measurement::~Measurement() {
}


// GETTERS

string Measurement::getAttribute_id() const {
    return attribute_id;
}

string Measurement::getSensor_id() const {
    return sensor_id;
}

double Measurement::getValue() const {
    return value;
}

Time Measurement::getTimeStamp() const {
    return timeStamp;
}

// SETTERS

void Measurement::setAttribute_id(string attribute_id) {
    this->attribute_id = attribute_id;
}

void Measurement::setSensor_id(string sensor_id) {
    this->sensor_id = sensor_id;
}

void Measurement::setValue(double value) {
    this->value = value;
}

void Measurement::setTimeStamp(Time timeStamp) {
    this->timeStamp = timeStamp;
}

// << OVERLOAD
ostream& operator<<(ostream& os, const Measurement m) {
    os << "Time : " << m.timeStamp << " | Sensor : " << m.sensor_id << " | Attribute : " << m.attribute_id << " | Value : " << m.value << endl;
    return os;
};
