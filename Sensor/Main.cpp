#include <iostream>
#include <string>
#include <vector>
#include "Measurement.h"
#include "Csvfile.h"
#include "Admin.h"
#include "Cleaner.h"
#include "GovernmentUser.h"
#include "PrivateUser.h"
#include "ProviderUser.h"
#include "Sensor.h"
#include "System.h"
#include "Time.h"
#include "Unit.h"
#include "User.h"

using namespace std;

int main() {
    System system_manager;
    //system_manager.loadData();

    cout << "Welcome to the Air Quality application." << endl
         << "What do you want to do?" << endl
         << "1- Create an account" << endl
         << "2- Login" << endl;

    int choice;
    cin >> choice;
    cin.ignore(); // Ignore le '\n' après le choix

    if (choice == 1) {
        string isProvider, role;

        cout << "Are you a provider? (y/n)" << endl;
        getline(cin, isProvider);

        if (isProvider == "y" || isProvider == "yes") {
            role = "ProviderUser";
        } else {
            role = "GovernmentUser";
        }

        string username, password, firstname, name, mail;

        cout << "What is your username?" << endl;
        getline(cin, username);

        cout << "And your password?" << endl;
        getline(cin, password);

        cout << "What is your firstname?" << endl;
        getline(cin, firstname);

        cout << "What is your lastname?" << endl;
        getline(cin, name);

        cout << "What is your mail?" << endl;
        getline(cin, mail);

        if (system_manager.createAccount(username, password, role, firstname, name, mail)) {
            cout << "Account created successfully!" << endl;
        } else {
            cout << "Error: Account with this username already exists." << endl;
        }

    } else if (choice == 2) {
        string username, password;

        cout << "What is your username?" << endl;
        getline(cin, username);

        cout << "And your password?" << endl;
        getline(cin, password);

        if (system_manager.verifyLogin(username, password)) {
            cout << "You logged in successfuly" << endl;

            bool connexion = true;
            while (connexion) {
                cout << "\nWhat do you want to do?" << endl
                     << "1- Analyze a specific sensor values" << endl
                     << "2- Calculate mean values in area" << endl
                     << "3- Search similar sensors" << endl
                     << "4- Calculate air quality improvement" << endl
                     << "5- Evaluate sensor reliability" << endl
                     << "6- Logout" << endl
                     << "7- User Manual" << endl;

                cin >> choice;
                cin.ignore(); // Ignore le '\n' après le choix

                switch (choice) {
                    case 1: {
                        string sensorId, choice_str;
                        cout << "Sensor Id?" << endl;
                        getline(cin, sensorId);

                        cout << "Print values? (y/n)" << endl;
                        getline(cin, choice_str);

                        if (choice_str == "y" || choice_str == "Y") {
                            auto measurements = system_manager.getMeasurementsForSensor(sensorId);
                            for (const auto& m : measurements) {
                                cout << m << endl;
                            }
                        }

                        cout << "Analysis:" << endl;
                        system_manager.analyzeSensor(sensorId);
                        break;
                    }
                    case 2: {
                        double lat, lon, rad;
                        string start, end, attributeId;

                        cout << "Enter latitude: ";
                        cin >> lat;

                        cout << "Enter longitude: ";
                        cin >> lon;

                        cout << "Enter radius: ";
                        cin >> rad;
                        cin.ignore();

                        cout << "Enter start date (format YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, start);

                        cout << "Enter end date (format YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, end);

                        cout << "Enter attribute ID (O3, NO2, SO2, PM10): ";
                        getline(cin, attributeId);

                        double meanVal = system_manager.calculateMeanInArea(lat, lon, rad, start, end, attributeId);
                        cout << "Result: " << meanVal << endl;
                        break;
                    }
                    case 3: {
                        string sensorId, start, end, attributeId;

                        cout << "Enter sensor ID: ";
                        getline(cin, sensorId);

                        cout << "Enter start date (format YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, start);

                        cout << "Enter end date (format YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, end);

                        cout << "Enter attribute ID (e.g., O3, NO2, SO2, PM10): ";
                        getline(cin, attributeId);

                        auto results = system_manager.rankSimilarSensors(sensorId, start, end, attributeId);
                        cout << "Similar sensors:" << endl;
                        for (const auto& [sensor, similarity] : results) {
                            cout << sensor << " -> Similarity: " << similarity << endl;
                        }
                        break;
                    }
                    case 4: {
                        cout << "Feature not yet implemented." << endl;
                        break;
                    }
                    case 5: {
                        string sensorId, start, end;
                        double radius;

                        cout << "Enter sensor ID: ";
                        getline(cin, sensorId);

                        cout << "Enter radius (in km): ";
                        cin >> radius;
                        cin.ignore();

                        cout << "Enter start date (YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, start);

                        cout << "Enter end date (YYYY-MM-DD HH:MM:SS): ";
                        getline(cin, end);

                        bool isReliable = system_manager.evaluateSensorReliability(sensorId, radius, start, end);
                        cout << "Sensor " << sensorId << " is " << (isReliable ? "RELIABLE" : "UNRELIABLE") << " during the selected period." << endl;
                        break;
                    }
                    case 6: {
                        connexion = false;
                        cout << "Logged out." << endl;
                        break;
                    }
                    case 7: {
                        cout << "Opening User Manual..." << endl;
#ifdef _WIN32
                        system("start manual.html");
#else
                        system("xdg-open manual.html");
#endif
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                        break;
                    }
                }
            }
        } else {
            cout << "Invalid username or password." << endl;
            return 1;
        }

    } else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    return 0;
}
