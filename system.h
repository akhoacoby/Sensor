/*************************************************************************
                           System  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined ( System_H )
#define System_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <ostream>
//#include <chrono>

#include "Cleaner.h"
#include "User.h"
#include "Time.h"
#include "Sensor.h"
#include "Csvfile.h"
#include "Measurement.h"

using namespace std;

//------------------------------------------------------------- Constantes
// Seuils pour annalyse
const double maxIrregularRatio = 0.2;
const double minVariance = 0.1;
const double maxVariance = 100.0;
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//
//
//------------------------------------------------------------------------

class System
{
//----------------------------------------------------------------- PUBLIC
friend ostream& operator<<(ostream& os, const System& s);

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void loadData();

    bool addUser(std::unique_ptr<User> user);

    bool analyzeSensor(const std::string & sensorId);

    double calculateMeanInArea (double lat, double lon, double rad, const std::string & start, const std::string & end, std::string attributeId );

    double pearsonCorrelation(const vector<double>& x, const vector<double>& y) const;

    vector<pair<Sensor, double>> rankSimilarSensors(const string& sensorId, const string& start, const string& end, string attributeId);

    double computeDistance(double lat1, double lon1, double lat2, double lon2);

    bool evaluateSensorReliability(const string& sensorId, double radius, const string& start, const string& end);

    vector<Measurement> getMeasurementsForSensor(const string& sensorId) const;

    User* getUserByUsername(const std::string& username);

//-------------------------------------------- Constructeurs - destructeur
    System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    std::vector<Sensor> list_sensors;
    std::vector<std::unique_ptr<User>> list_users;
    std::vector<Measurement> list_measurements;
    std::vector<Cleaner> list_cleaners;
};

//-------------------------------- Autres définitions dépendantes de <System>

#endif // System_H
