/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int User::getType() const
{
    return(typeUser);
} //----- Fin de getType

void User::setType(int typ)
{
    typeUser=typ;
} //----- Fin de setType

string User::getId() const
{
    return(id);
} //----- Fin de getId

void User::setId(string nId)
{
    id=nId;
} //----- Fin de setId

string User::getPassword() const
{
    return(password);
} //----- Fin de getPassword

void User::setPassword(string nPassword)
{
    password=nPassword;
} //----- Fin de setPassword

string User::getFirstName() const
{
    return(firstName);
} //----- Fin de getFirstName
void User::setFirstName(string nFirstName)
{
    firstName=nFirstName;
} //----- Fin de setFirstName

string User::getLastName() const
{
    return(lastName);
} //----- Fin de getLastName
void User::setLastName(string nLastName)
{
    lastName=nLastName;
} //----- Fin de setLastName

string User::getMail() const
{
    return(mail);
} //----- Fin de getMail
void User::setMail(string nMail)
{
    mail=nMail;
} //----- Fin de setMail

//-------------------------------------------- Constructeurs - destructeur
User::User ()
{   
    #ifdef MAP
        cout << "Appel au constructeur de <User>" << endl;
    #endif
} //----- Fin de User


User::~User ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <User>" << endl;
    #endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

