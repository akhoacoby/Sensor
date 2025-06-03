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

int main(){
  System system_manager;
  system_manager.loadData();
  //cout << system_manager << endl; TEST

  cout << "Welcome to the Air Quality application." << endl << "What do you want to do?" << endl << "1- Create an account" << endl << "2- Login" << endl;

  int choice;
  cin >> choice;
  if (choice == 1) {
     string type_str;
     int type;
     cout << "Are you a provider ? y/n" << endl;
     cin >> type_str;
     if (type_str == "y" || type_str == "yes"){
       type = 2;
     }
     else{
       type = 1; //governmental agency because admin accounts cannot be created and private users cannot go on the application
     }

      string username;
      cout << "What is your username ?" << endl;
      cin >> username;

      string password;
      cout << "And your password ?" << endl;
      cin >> password;

      string firstname;
      cout << "What is your firstname ?" << endl;
      cin >> firstname;

      string name;
      cout << "What is your lastname ?" << endl;
      cin >> name;

      string mail;
      cout << "What is your mail ?" << endl;
      cin >> mail;

      std::unique_ptr<User> to_create;
      if (type == 1){
        to_create = std::make_unique<GovernmentUser>(username, password, firstname, name, mail);
      }
      else{
        to_create = std::make_unique<ProviderUser>(username, password, firstname, name, mail);
      }

      system_manager.addUser(std::move(to_create));
      //delete to_create;
    } else if (choice == 2) {
        string username;
        cout << "What is your username ?" << endl;
        cin >> username;

        string password;
        cout << "And your password ?" << endl;
        cin >> password;

        cout << "Username: " << username << "\nPassword: " << password << endl; // TEST
        User* to_log = system_manager.getUserByUsername(username);
        // bool connexion = to_log.Verify_pw(password);
        bool connexion = true; //en attendant
        if (connexion){
          // INIT
          string sensorId, start, end, attributeId, choice_str;
          double lat, lon, rad, radius;
          vector<double> x;
          vector<double> y;

          while (connexion){
            cout << "What do you want to do ?" << endl;
            cout << "1- Analyze a specific sensor values" << endl;
            cout << "2- Calculate mean values in area" << endl;
            cout << "3- Search similar sensors" << endl;
            cout << "4- Calculate air quality improvement" << endl;
            cout << "5- Evaluate sensor reliability" << endl;
            cout << "6- Logout" << endl;

            cin >> choice;

            switch (choice) {
                case 1:{
                    cout << "Sensor Id ?" << endl;
                    cin >> sensorId;

                    cout << "Print values y/n?" << endl;
                    cin >> choice_str;
                    if (choice_str == "y"){
                      vector<Measurement> measurements = system_manager.getMeasurementsForSensor(sensorId);
                      for (const auto& m : measurements) {
                          cout << m;
                      }
                    }
                    cout << "Analysis :" << endl;
                    system_manager.analyzeSensor(sensorId);
                    break;
                }
                case 2:{
                    cout << "Calculating mean values in area..." << endl;

                    cout << "Enter latitude: ";
                    cin >> lat;

                    cout << "Enter longitude: ";
                    cin >> lon;

                    cout << "Enter radius : ";
                    cin >> rad;

                    cout << "Enter start date (format YYYY-MM-DD HH:MM:SS): ";
                    cin.ignore();
                    getline(cin, start);

                    cout << "Enter end date (format YYYY-MM-DD HH:MM:SS): ";
                    getline(cin, end);

                    cout << "Enter attribute ID (O3, NO2, SO2, PM10): ";
                    getline(cin, attributeId);

                    cout << "Result : " << system_manager.calculateMeanInArea(lat, lon, rad, start, end, attributeId) << endl;
                    break;
                }
                case 3:{

                  cout << "Enter sensor ID: " << endl;
                  cin.ignore();
                  getline(cin, sensorId);

                  cout << "Enter start date (format YYYY-MM-DD HH:MM:SS): " << endl;
                  getline(cin, start);

                  cout << "Enter end date (format YYYY-MM-DD HH:MM:SS): " << endl;
                  getline(cin, end);

                  cout << "Enter attribute ID (e.g., O3, NO2, SO2, PM10): " << endl;
                  getline(cin, attributeId);

                  vector<pair<Sensor, double>> results = system_manager.rankSimilarSensors(sensorId, start, end, attributeId);
                  cout << "Similar sensors :" << endl;
                  for (const auto& [sensor, similarity] : results) {
                      cout << sensor << " -> Similarity: " << similarity << endl;
                  }

                  break;
                }
                case 4:{ // TO DO
                    // cout << pearsonCorrelation(x,y) << endl;
                    break;}

                case 5:{

                  cout << "Enter sensor ID: " << endl;
                  cin >> sensorId;

                  cout << "Enter radius (in km): " << endl;
                  cin >> radius;

                  cout << "Enter start date (YYYY-MM-DD HH:MM:SS): " << endl;
                  cin.ignore();
                  getline(cin, start);

                  cout << "Enter end date (YYYY-MM-DD HH:MM:SS): " << endl;
                  getline(cin, end);

                  bool isReliable = system_manager.evaluateSensorReliability(sensorId, radius, start, end);

                  cout << "\nSensor " << sensorId << " is " << (isReliable ? "RELIABLE" : "UNRELIABLE") << " during the selected period." << endl;
                  break;}
                case 6:{
                  connexion = false;
                  break;
                }
                default:{
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                    break;
            }
          }
        }
      }
      else{
        cout << "The account doesnt exist. Exiting." << endl;
        return 1;
      }

    } else {
        cout << "Invalid choice. Exiting." << endl;
        return 1;
    }
  return 1;
}
