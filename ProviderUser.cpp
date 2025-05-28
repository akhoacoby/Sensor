/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <ProviderUser > (fichier ProviderUser .cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<string>

//------------------------------------------------------ Include personnel
#include "ProviderUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ProviderUser ::Afficher(void) const
{
    cout<<"Nom : "<<lastName<<" Prénom : "<<firstName<<" Mail : "<<mail<<endl;
} //----- Fin de Afficher

int ProviderUser::Verify_pw(string mdp)
{
    if (mdp==password){
        return 0;
    }
    else{
        return 1;
    }
}//----- Fin de Verify_pw

//-------------------------------------------- Constructeurs - destructeur

ProviderUser ::ProviderUser  (string Id, string Password, string FirstName, string LastName, string Mail)
{
    id= Id;
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;
    typeUser = 2;

    #ifdef MAP
        cout << "Appel au constructeur de <ProviderUser >" << endl;
    #endif
} //----- Fin de ProviderUser 

ProviderUser ::ProviderUser  (string Password, string FirstName, string LastName, string Mail)
{
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;
    typeUser = 2;

    #ifdef MAP
        cout << "Appel au constructeur de <ProviderUser >" << endl;
    #endif
} //----- Fin de ProviderUser 





//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
