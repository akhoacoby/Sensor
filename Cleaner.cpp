/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
std::string Cleaner::getCleanerId() const { return cleanerId; }
double Cleaner::getCleanerLat() const { return latitude; }
double Cleaner::getCleanerLong() const { return longitude; }
Time Cleaner::getCleanerStartTime() const { return startTime; }
Time Cleaner::getCleanerStopTime() const { return stopTime; }

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( )
{
    cleanerId = "";
    latitude = 0;
    longitude = 0;
    startTime = Time();
    stopTime = Time();

#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner 


Cleaner::Cleaner (const string& cleaner_str)
// Algorithme :
//
{
    stringstream ss(cleaner_str);
    string token;

    getline(ss, token, ';');
    cleanerId = token;
    getline(ss, token, ';');
    latitude = stod(token);
    getline(ss, token, ';');
    longitude = stod(token);
    getline(ss, token, ';');
    startTime = Time(token);  
    getline(ss, token, ';');
    stopTime = Time(token);

#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

