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

#include "Cleaner.h"
#include "Measurement.h"
#include "User.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//
//
//------------------------------------------------------------------------

class System
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void loadData();

    bool analyzeSensor(const std::string & sensorId);

    double calculateMeanInArea (double lat, double lon, double rad, const std::string & start, const std::string & end, std::string attributeId );

    double pearsonCorrelation(const vector<double>& x, const vector<double>& y);

    std::vector<pair<Sensor,int>> rankSimilarSensors(const std::string & sensorId, const std::string & start, const std::string & end, const std::string & timestamp, std::string attributeId);

    double computeDistance(double lat1, double lon1, double lat2, double lon2);

    bool evaluateSensorReliability(const std::string & sensorId);

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
    std::vector<User> list_users;
    std::vector<Measurement> list_measurements;
    std::vector<Cleaner> list_cleaners;
};

//-------------------------------- Autres définitions dépendantes de <System>

#endif // System_H

