/*************************************************************************
                                Unit
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Unit> realization (file Unit.cpp) ------------
#include "unit.h"

Unit stringToUnit(const string& unit_str){
    if (unit_str == "µg/m3" || unit_str == "ug/m3"){
        return Unit::UG_PER_M3;
    }
    if (unit_str == "mg/m3"){
        return Unit::MG_PER_M3;
    }
    throw invalid_argument("Unit string unknown: " + unit_str);
}

string unitToString(Unit unit) {
    switch (unit) {
        case Unit::UG_PER_M3: 
            return "µg/m³";
        case Unit::MG_PER_M3: 
            return "mg/m³";
        default: 
            return "none";
    }
}