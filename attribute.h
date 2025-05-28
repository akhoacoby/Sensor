/*************************************************************************
                           Attribute  -  description
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Attribute> interface (file Attribute.h) ------------
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

// SYSTEM INCLUDES 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// PERSONNAL INCLUDES
#include "unit.h"

class Attribute {
    friend ostream& operator<<(ostream& os, const Attribute a);

    public:
        // GETTERS
        string getAttribute_id() const;
        string getDescription() const;
        Unit getUnit() const;

        // SETTERS
        void setAttribute_id(string attribute_id);
        void setDescription(string description);
        void setUnit(Unit unit);

        // CONSTRUCTORS 
        Attribute();
        Attribute(const string& attribute_str);
        // DESTRUCTOR 
        virtual ~Attribute();
        
    private:
        // PRIVATE ATTRIBUTES
		Unit unit;
		string attribute_id;
		string description;
};

#endif