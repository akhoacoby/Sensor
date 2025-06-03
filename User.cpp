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
#include "Admin.h"
#include "GovernmentUser.h"
#include "ProviderUser.h"
#include "PrivateUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
std::unique_ptr<User> createUserFromLine(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> tokens;

    while (std::getline(ss, item, ',')) {
        tokens.push_back(item);
    }

    if (tokens.size() != 6) return nullptr;

    int typeUser = std::stoi(tokens[0]);
    const std::string& id = tokens[1];
    const std::string& password = tokens[2];
    const std::string& firstName = tokens[3];
    const std::string& lastName = tokens[4];
    const std::string& mail = tokens[5];

    switch (typeUser) {
        case 0:
            return std::make_unique<Admin>(id, password, firstName, lastName, mail);
        case 1:
            return std::make_unique<GovernmentUser>(id, password, firstName, lastName, mail);
        case 2:
            return std::make_unique<ProviderUser>(id, password, firstName, lastName, mail);
        case 3:
            return std::make_unique<PrivateUser>(id, password, firstName, lastName, mail);
        default:
            return nullptr;
    }
}


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

