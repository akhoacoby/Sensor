/*************************************************************************
                                Csvfile
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Csvfile> realization (file Csvfile.cpp) ------------
#include "csvfile.h"

// CONSTRUCTORS
Csvfile::Csvfile() {}

Csvfile::Csvfile(const string& filename) {
    loadFromFile(filename);
}

// DESTRUCTOR
Csvfile::~Csvfile() {}

// PUBLIC METHODS

void Csvfile::writeToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open the file " + filename);
    }

    for (const auto& attr : attributes) {
        file << attr << "\t";
    }
    file << "\n";

    for (const auto& line : values) {
        file << line << "\n";
    }
};

void Csvfile::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open the file " + filename);
    }

    string line;
    bool firstLine = true;

    attributes.clear();
    values.clear();

    while (getline(file, line)) {
        if (firstLine) {
            istringstream ss(line);
            string attr;
            while (getline(ss, attr, ',')) {
                attributes.push_back(attr);
            }
            firstLine = false;
        } else {
            values.push_back(line);
        }
    }
}

const vector<string>& Csvfile::getLines() const {
    return values;
}

const vector<string>& Csvfile::getHeader() const {
    return attributes;
}

// OVERRIDE
ostream& operator<<(ostream& os, const Csvfile f) {
    setlocale(LC_ALL, "en_US.UTF-8"); //pour l'affichage correct des unités dans le terminal
    for (const auto& attr : f.attributes) {
        os << attr << "\t";
    }
    os << "\n";

    for (const auto& line : f.values) {
        os << line << "\n";
    }

    return os;
}
