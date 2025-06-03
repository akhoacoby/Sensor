#include "System.h"

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
    // Chargement des users
    Csvfile userFile("users.csv");
    for (const string& line : userFile.getLines()) {
        unique_ptr<User> user = createUserFromLine(line);
        if (user) {
            list_users.push_back(std::move(user));
        }
    }       


}


bool System::addUser(std::unique_ptr<User> user) {
    std::ofstream file("users.csv", std::ios::app); // Open in append mode
    if (!file.is_open()) return false;

    file << user->getId() << "," << user->getPassword() << "\n";
    file.close();
    list_users.push_back(user); // Also keep it in memory
    return true;
}

vector<Measurement> System::getMeasurementsForSensor(const string& sensorId) const {
    vector<Measurement> result;
    for (const auto& m : list_measurements) {
        if (m.getSensor_id() == sensorId) {
            result.push_back(m);
        }
    }
    return result;
}

bool System::analyzeSensor(const std::string& sensorId) {
    vector<Measurement> mesures = getMeasurementsForSensor(sensorId);
    if (mesures.size() < 2) return false; // Pas assez de données pour analyse

    // 1) Consistance temporelle
    int irregularCount = 0;
    int expectedInterval = 60; // 1 mesure par minute environ

    for (size_t i = 1; i < mesures.size(); ++i) {
        int interval = mesures[i].getTimeStamp().toSeconds() - mesures[i-1].getTimeStamp().toSeconds();

        // tolérance +/- 30 secondes autour d'une minute
        if (std::abs(interval - expectedInterval) > 30) {
            irregularCount++;
        }
    }
    double irregularRatio = double(irregularCount) / (mesures.size() - 1);

    // 2) Variance des mesures
    double sum = 0.0, sumSq = 0.0;
    for (const auto& m : mesures) {
        double val = m.getValue();
        sum += val;
        sumSq += val * val;
    }
    double mean = sum / mesures.size();
    double variance = (sumSq / mesures.size()) - (mean * mean);

    if (irregularRatio > maxIrregularRatio) {
        // Capteur considéré non fiable pour irrégularité temporelle
        cout << " Sensor " << sensorId << " flagged as UNRELIABLE!!!" << endl;
        return false;
    }

    if (variance < minVariance || variance > maxVariance) {
        // Capteur considéré non fiable pour variance anormale
         cout << " Sensor " << sensorId << " flagged as UNRELIABLE!!!" << endl;
        return false;
    }

    // Capteur semble fiable
    cout << " Sensor " << sensorId << " is reliable" << endl;
    return true;
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


double System::pearsonCorrelation(const vector<double>& x, const vector<double>& y) const{
    if (x.size() != y.size() || x.empty()) return 0.0;

    double meanX = accumulate(x.begin(), x.end(), 0.0) / x.size();
    double meanY = accumulate(y.begin(), y.end(), 0.0) / y.size();

    double numerator = 0.0;
    double denomX = 0.0;
    double denomY = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        double dx = x[i] - meanX;
        double dy = y[i] - meanY;
        numerator += dx * dy;
        denomX += dx * dx;
        denomY += dy * dy;
    }

    if (denomX == 0.0 || denomY == 0.0) return 0.0;

    return numerator / sqrt(denomX * denomY);
}


vector<pair<Sensor, double>> System::rankSimilarSensors(const string& sensorId, const string& start, const string& end, string attributeId) {
    Time tStart(start);
    Time tEnd(end);
    vector<pair<Sensor, double>> rankedSensors;

    // Trouver le capteur de référence
    Sensor* refSensor = nullptr;
    for (Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) {
            refSensor = &s;
            break;
        }
    }
    if (!refSensor) return rankedSensors;

    // Récupérer les mesures de référence
    vector<Measurement> refMeasurements = refSensor->get_measurements(list_measurements, tStart);
    vector<double> refValues;

    for (const Measurement& m : refMeasurements) {
        if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
            refValues.push_back(m.getValue());
        }
    }

    // Comparer avec les autres capteurs
    for (const Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) continue;

        vector<Measurement> otherMeasurements = s.get_measurements(list_measurements, tStart);
        vector<double> otherValues;

        for (const Measurement& m : otherMeasurements) {
            if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
                otherValues.push_back(m.getValue());
            }
        }

        // Assurer une comparaison sur une base commune (même taille)
        size_t minSize = min(refValues.size(), otherValues.size());
        if (minSize < 10) continue; // trop peu de points en commun, skip

        vector<double> x(refValues.begin(), refValues.begin() + minSize);
        vector<double> y(otherValues.begin(), otherValues.begin() + minSize);

        double similarity = pearsonCorrelation(x, y);
        rankedSensors.push_back({s, similarity});
    }

    // Trier du plus similaire au moins similaire
    sort(rankedSensors.begin(), rankedSensors.end(),
        [](const pair<Sensor, double>& a, const pair<Sensor, double>& b) {
            return a.second > b.second;
        });

    return rankedSensors;
}



// Fonction  pour calculer la distance
double System::computeDistance(double lat1, double lon1, double lat2, double lon2) {
    double dx = lat1 - lat2;
    double dy = lon1 - lon2;
    return sqrt(dx * dx + dy * dy) * 111;
}

bool System::evaluateSensorReliability(const string& sensorId, double radius, const string& start, const string& end) {
    Time tStart(start);
    Time tEnd(end);

    // 1) Trouver le capteur cible
    Sensor* targetSensor = nullptr;
    for (Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) {
            targetSensor = &s;
            break;
        }
    }
    if (!targetSensor) return false; // Capteur inconnu

    double lat = targetSensor->get_lat();
    double lon = targetSensor->get_long();

    // 2) Trouver les capteurs voisins dans un rayon donné
    vector<Sensor> neighbors;
    for (const Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) continue;
        double d = computeDistance(lat, lon, s.get_lat(), s.get_long());
        if (d <= radius) {
            neighbors.push_back(s);
        }
    }

    if (neighbors.empty()) return true; // Pas de comparaison possible → considérer comme fiable

    // 3) Extraire les mesures du capteur cible
    vector<Measurement> targetMeasurements = targetSensor->get_measurements(list_measurements, tStart);
    map<string, vector<double>> targetValues; // attributeId → valeurs

    for (const Measurement& m : targetMeasurements) {
        if (m.getTimeStamp() <= tEnd) {
            targetValues[m.getAttribute_id()].push_back(m.getValue());
        }
    }

    // 4) Comparer avec les moyennes des voisins
    for (const auto& [attribute, tVals] : targetValues) {
        if (tVals.empty()) continue;

        // Moyennes des voisins
        vector<double> neighborAverages;
        for (const Sensor& neighbor : neighbors) {
            vector<Measurement> neighborMeas = neighbor.get_measurements(list_measurements, tStart);
            vector<double> values;

            for (const Measurement& m : neighborMeas) {
                if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attribute) {
                    values.push_back(m.getValue());
                }
            }

            if (!values.empty()) {
                double sum = accumulate(values.begin(), values.end(), 0.0);
                neighborAverages.push_back(sum / values.size());
            }
        }

        if (neighborAverages.empty()) continue;

        // Moyenne et écart-type des voisins
        double mean = accumulate(neighborAverages.begin(), neighborAverages.end(), 0.0) / neighborAverages.size();
        double variance = 0.0;
        for (double val : neighborAverages) {
            variance += (val - mean) * (val - mean);
        }
        variance /= neighborAverages.size();
        double stdDev = sqrt(variance);

        // Moyenne des valeurs du capteur cible
        double targetMean = accumulate(tVals.begin(), tVals.end(), 0.0) / tVals.size();

        // Si l'écart dépasse 2 fois l'écart-type alors suspect
        if (fabs(targetMean - mean) > 2 * stdDev) {
            return false;
        }
    }

    return true;
}

User* System::getUserByUsername(const std::string& username) {
    for (const auto& userPtr : list_users) {
        if (userPtr->getId() == username) {
            return userPtr.get(); // return raw pointer, no ownership transfer
        }
    }
    return nullptr; // not found
}


ostream& operator<<(std::ostream& os, const System& system) {
    os << "System data summary:\n";
    os << "  Sensors: " << system.list_sensors.size() << "\n";
    os << "  Users: " << system.list_users.size() << "\n";
    os << "  Measurements: " << system.list_measurements.size() << "\n";
    os << "  Cleaners: " << system.list_cleaners.size() << "\n";
    return os;
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
