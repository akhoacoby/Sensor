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
    // Chargement des sensors
    Csvfile sensorFile("sensors.csv");
    for (const string& line : sensorFile.getLines()) {
        Sensor s(line);
        list_sensors.push_back(s);
    }

    // Chargement des measurments
    Csvfile measurementFile("measurements.csv");
    for (const string& line : measurementFile.getLines()) {
        Measurement m(line);
        list_measurements.push_back(m);
    }

    // Chargement des cleaners
    Csvfile cleanerFile("cleaners.csv");
    for (const string& line : cleanerFile.getLines()) {
        Cleaner c(line);
        list_cleaners.push_back(c);
    }

   
}


bool System::analyzeSensor(const std::string & sensorId)
{
    //  Analyse de capteur
}

double System::calculateMeanInArea(double lat, double lon, double rad,const std::string & start,
const std::string & end,std::string attributeId)
{
        Time tStart(start);
    Time tEnd(end);
    double total = 0.0;
    int count = 0;

    for (const Sensor& s : list_sensors) {
        double dist = sqrt(pow(s.get_lat() - lat, 2) + pow(s.get_long() - lon, 2));
        if (dist <= rad) {
            vector<Measurement> sensorMeasurements = s.get_measurements(list_measurements, tStart);
            for (const Measurement& m : sensorMeasurements) {
                if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
                    total += m.getValue();
                    count++;
                }
            }
        }
    }

    if (count == 0) return -1;
    return total / count;

}

double pearsonCorrelation(const map<Time, double>& s1, const map<Time, double>& s2) {
    vector<double> vals1, vals2;
    
    for (const auto& [time, val1] : s1) {
        auto it = s2.find(time);
        if (it != s2.end()) {
            vals1.push_back(val1);
            vals2.push_back(it->second);
        }
    }
    if (vals1.size() < 2) return 0; // pas assez de points pour corrélation

    double mean1 = accumulate(vals1.begin(), vals1.end(), 0.0) / vals1.size();
    double mean2 = accumulate(vals2.begin(), vals2.end(), 0.0) / vals2.size();

    double num = 0, denom1 = 0, denom2 = 0;
    for (size_t i = 0; i < vals1.size(); i++) {
        num += (vals1[i] - mean1) * (vals2[i] - mean2);
        denom1 += (vals1[i] - mean1) * (vals1[i] - mean1);
        denom2 += (vals2[i] - mean2) * (vals2[i] - mean2);
    }

    if (denom1 == 0 || denom2 == 0) return 0;

    return num / sqrt(denom1 * denom2); // valeur entre -1 et 1
}

vector<pair<Sensor, double>> System::rankSimilarSensors(const string & sensorId,
                                                       const string & start,
                                                       const string & end,
                                                       const string & timestamp,
                                                       string attributeId) {
    Time tStart(start);
    Time tEnd(end);

    auto refSeries = getMeasurements(sensorId, tStart, tEnd, attributeId);

    vector<pair<Sensor, double>> rankedSensors;

    for (const Sensor& s : list_sensors) {
        if (s.getId() == sensorId) continue;

        auto otherSeries = getMeasurements(s.getId(), tStart, tEnd, attributeId);

        double corr = pearsonCorrelation(refSeries, otherSeries);
        // Plus corr proche de 1 = plus similaire

        rankedSensors.push_back({s, corr});
    }

    sort(rankedSensors.begin(), rankedSensors.end(),
         [](const pair<Sensor, double>& a, const pair<Sensor, double>& b) {
             return a.second > b.second; // tri décroissant par corrélation
         });

    return rankedSensors;
}


bool System::evaluateSensorReliability(const std::string & sensorId)
{
    // évaluation de fiabilité
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

