/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <PrivateUser > (fichier PrivateUser .cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include<string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "PrivateUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void PrivateUser ::Afficher(void) const
{
    cout<<"Nom : "<<lastName<<" Prénom : "<<firstName<<" Mail : "<<mail<<" Score : "<<score<<endl;
} //----- Fin de Afficher

int PrivateUser ::getScore(void) const
{
    return score;
} //----- Fin de getScore

void PrivateUser ::setScore(int nouveau)
{
    score=nouveau;
} //----- Fin de setScore

string PrivateUser::getTrans() const {
    return "Private";
}

//-------------------------------------------- Constructeurs - destructeur

PrivateUser ::PrivateUser  (string Id, string Password, string FirstName, string LastName, string Mail)
{
    id= Id;
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;

    score=0;
    typeUser = 3;

    #ifdef MAP
        cout << "Appel au constructeur de <PrivateUser >" << endl;
    #endif
} //----- Fin de PrivateUser

PrivateUser ::PrivateUser  (string Password, string FirstName, string LastName, string Mail)
{
    password=Password;
    firstName=FirstName;
    lastName=LastName;
    mail=Mail;

    score=0;
    typeUser = 3;

    #ifdef MAP
        cout << "Appel au constructeur de <PrivateUser >" << endl;
    #endif
} //----- Fin de PrivateUser


void PrivateUser::ChangerScore(int add)
{
    score=score+add;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
