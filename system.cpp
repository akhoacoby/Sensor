#include "System.h"
#include "csvfile.h"
#include "sensors.h"

//----------------------------------------------------- Constructeur
System::System()
{
    
}

//----------------------------------------------------- Destructeur
System::~System()
{

}

//----------------------------------------------------- Méthodes

void System::loadData() {
     // Charger sensors
    try {
        Csvfile sensorsCsv("sensors.csv");
        const std::vector<std::string>& linesSensors = sensorsCsv.getLines();

        for (size_t i = 0; i < linesSensors.size(); ++i) {
            std::string line = linesSensors[i];
            std::istringstream ss(line);
            std::string token;

            std::string sensorId;
            double latitude = 0.0;
            double longitude = 0.0;

            if (!getline(ss, token, ',')) continue;
            sensorId = token;

            if (!getline(ss, token, ',')) continue;
            latitude = std::stod(token);

            if (!getline(ss, token, ',')) continue;
            longitude = std::stod(token);

            Sensor sensor;
            sensor.setSensorId(sensorId);  
            sensor.setLatitude(latitude);  
            sensor.setLongitude(longitude);

            list_sensors.push_back(sensor);
        }
    }
    catch (std::exception& e) {
        std::cerr << "Erreur lors du chargement des capteurs : " << e.what() << std::endl;
    }

    // Charger mesures
    try {
        Csvfile measuresCsv("measurements.csv");
        const std::vector<std::string>& linesMeasures = measuresCsv.getLines();

        for (size_t i = 0; i < linesMeasures.size(); ++i) {
            std::string line = linesMeasures[i];
            std::istringstream ss(line);
            std::string token;

            std::string sensorId;
            std::string attributeId;
            double value = 0.0;
            std::string timestamp;

            if (!getline(ss, token, ',')) continue;
            sensorId = token;

            if (!getline(ss, token, ',')) continue;
            attributeId = token;

            if (!getline(ss, token, ',')) continue;
            value = std::stod(token);

            if (!getline(ss, token, ',')) continue;
            timestamp = token;

            Measurement m;
            m.setSensor_id(sensorId);     
            m.setAttribute_id(attributeId);
            m.setValue(value);             
            m.setTimeStamp(Time(timestamp));

            list_measurements.push_back(m);
        }
    }
    catch (std::exception& e) {
        std::cerr << "Erreur lors du chargement des mesures : " << e.what() << std::endl;
    }

    std::cout << "Chargement des données terminé." << std::endl;
}


bool System::analyzeSensor(const std::string & sensorId)
{
    //  Analyse de capteur
}

double System::calculateMeanInArea(double lat, double lon, double rad,const std::string & start, const std::string & end,std::string attributeId)
{
    // calcul de moyenne
}

std::vector<pair<Sensor, int>> System::rankSimilarSensors(const std::string & sensorId,const std::string & start,
const std::string & end,const std::string & timestamp, std::string attributeId)
{
    //  classement des capteurs
    return;
}

bool System::evaluateSensorReliability(const std::string & sensorId)
{
    // évaluation de fiabilité
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

