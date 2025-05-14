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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//
//
//------------------------------------------------------------------------

class System : public System
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

    bool analyzeSensor(char sensorId);

    double calculateMeanInArea (double lat, double lon, double rad, char start, char end, char attributeId );

    double rankSimilarSensors(char sensorId, char start, char end, char timestamp, char attributeId);

    void evaluateSensorReliability(char sensorId);

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
    vector<Sensor> list_sensors;
    vector<User> list_users;
    vector<Measurement> list_measurements;
    vector<Cleaner> list_cleaners;
};

//-------------------------------- Autres définitions dépendantes de <System>

#endif // System_H

