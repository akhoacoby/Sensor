/*************************************************************************
                           Unit  -  description
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Unit> interface (file Unit.h) ------------
#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <stdexcept>
using namespace std;

enum class Unit {
    UG_PER_M3,  
    MG_PER_M3   
};

Unit stringToUnit(const string& unit_str);
string unitToString(Unit unit);


#endif // UNIT_H
