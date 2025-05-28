/*************************************************************************
                           Csvfile  -  description
                             -------------------
    beginning            : 2025
    copyright            : (C) 2025 by BACHET, LEBRE, BAHDA, BUI and BAGINSKI
    e-mail               : elise.bachet@insa-lyon.fr, nathan.lebre@insa-lyon.fr, malak.bahda@insa-lyon.fr, anh-khoa.bui@insa-lyon.fr, bartosz.baginski@insa-lyon.fr
*************************************************************************/

//---------- Class <Csvfile> interface (file Csvfile.h) ------------
#ifndef CSVFILE_H
#define CSVFILE_H

// SYSTEM INCLUDES 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

class Csvfile{
    friend ostream& operator<<(ostream& os, const Csvfile f);

    public:
        // CONSTRUCTORS 
        Csvfile();
        Csvfile(const string& filename);
        // DESTRUCTOR 
        virtual ~Csvfile();

        //PUBLIC METHODS
        void loadFromFile(const string& filename);
        const vector<string>& getLines() const;
        const vector<string>& getHeader() const;

    private:
        vector <string> attributes;
        vector <string> values;
};

#endif