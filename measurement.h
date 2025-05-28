/*************************************************************************
                           Measurement  -  description
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Measurement> interface (file Measurement.h) ------------
#ifndef MEASUREMENT_H
#define MEASUREMENT_H

// SYSTEM INCLUDES 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// PERSONNAL INCLUDES
#include "attribute.h"
#include "time.h"

class Measurement {
    friend ostream& operator<<(ostream& os, const Measurement m);
    
    public:
        // GETTERS
        string getAttribute_id() const;
        string getSensor_id() const;
        double getValue() const;
        Time getTimeStamp() const;

        // SETTERS
        void setAttribute_id(string attribute_id);
        void setSensor_id(string sensor_id);
        void setValue(double value);
        void setTimeStamp(Time timeStamp);

        // CONSTRUCTORS 
        Measurement();
        Measurement(const string& measurement_str);
        // DESTRUCTOR 
        virtual ~Measurement();

    private:
        // PRIVATE ATTRIBUTES
		Time timeStamp;
		string attribute_id;
		double value;
        string sensor_id;
};

#endif