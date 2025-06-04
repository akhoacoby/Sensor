/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <GovernmentUser > (fichier GovernmentUser .cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "GovernmentUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void GovernmentUser ::Afficher(void) const
{
    cout<<"Nom : "<<lastName<<" Prénom : "<<firstName<<" Mail : "<<mail<<endl;
} //----- Fin de Afficher

int GovernmentUser::Verify_pw(const string& mdp)
{   
    if (mdp==password){
        return 0;
    }
    else{
        return 1;
    }
}//----- Fin de Verify_pw

string GovernmentUser::getTrans() const {
    return "Government";
}


//-------------------------------------------- Constructeurs - destructeur

GovernmentUser ::GovernmentUser  (string Id, string Password, string FirstName, string LastName, string Mail)
{
    id= Id;
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;


    typeUser = 1;

    #ifdef MAP
        cout << "Appel au constructeur de <GovernmentUser >" << endl;
    #endif
} //----- Fin de GovernmentUser

GovernmentUser ::GovernmentUser  (string Password, string FirstName, string LastName, string Mail)
{

    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;


    typeUser = 1;

    #ifdef MAP
        cout << "Appel au constructeur de <GovernmentUser >" << endl;
    #endif
} //----- Fin de GovernmentUser



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
