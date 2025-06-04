/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <Admin > (fichier Admin .cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include<string>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Admin.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Admin ::Afficher(void) const
{
    cout<<"Nom : "<<lastName<<" Prénom : "<<firstName<<" Mail : "<<mail<<endl;
} //----- Fin de Afficher

int Admin::Verify_pw(string mdp)
{
    if (mdp==password){
        return 0;
    }
    else{
        return 1;
    }
}//----- Fin de Verify_pw


//-------------------------------------------- Constructeurs - destructeur

Admin ::Admin  (string Id, string Password, string FirstName, string LastName, string Mail)
{
    id= Id;
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;

    typeUser = 2;

    #ifdef MAP
        cout << "Appel au constructeur de <Admin >" << endl;
    #endif
} //----- Fin de Admin 

Admin ::Admin  (string Password, string FirstName, string LastName, string Mail)
{
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;

    typeUser = 2;

    #ifdef MAP
        cout << "Appel au constructeur de <Admin >" << endl;
    #endif
} //----- Fin de Admin 





//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
