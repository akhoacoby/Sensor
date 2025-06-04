/*************************************************************************
                                Attribute
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Attribute> realization (file Attribute.cpp) ------------

#include "Attribute.h"

// CONSTRUCTORS
Attribute::Attribute(){
    unit = Unit();
    attribute_id = "";
    description = "";
}

Attribute::Attribute(const string& str){
    stringstream ss(str);
    string field;

    string unit_str;
    getline(ss, attribute_id, ';');
    getline(ss, unit_str, ';');
    getline(ss, description, ';');

    unit = stringToUnit(unit_str);
};

// DESTRUCTOR

Attribute::~Attribute() {
}

// GETTERS

string Attribute::getAttribute_id() const {
    return attribute_id;
}

string Attribute::getDescription() const {
    return description;
}

Unit Attribute::getUnit() const {
    return unit;
}

// SETTERS

void Attribute::setAttribute_id(string attribute_id) {
    this->attribute_id = attribute_id;
}

void Attribute::setDescription(string description) {
    this->description = description;
}

void Attribute::setUnit(Unit unit) {
    this->unit = unit;
}

// << OVERRIDE
ostream& operator<<(ostream& os, const Attribute a) {
    setlocale(LC_ALL, "en_US.UTF-8"); //pour l'affichage correct des unités dans le terminal
    os << "Unit : " << unitToString(a.unit) << " | Attribute : " << a.attribute_id << " | Description : " << a.description << endl;
    return os;
};
