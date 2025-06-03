/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <User> (fichier  User.h) ----------------
#if ! defined ( User_H )
#define User_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//     Classe parente, il ne peut pas exister d'objet de type User
//     Ses seules méthodes non virtuelles servent à récupérer les valeurs des attributs
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher () const = 0;
    virtual string getTrans () const = 0;
    virtual int Verify_pw(const string& mdp);


    int getType () const;
    void setType (int typ);

    string getId () const;
    void setId (string nId);
    string getPassword () const;
    void setPassword (string nPassword);
    string getFirstName () const;
    void setFirstName (string nFirstName);
    string  getLastName () const;
    void setLastName (string nLastName);
    string  getMail () const;
    void setMail (string nMail);


//-------------------------------------------- Constructeurs - destructeur

    virtual ~User ( );

//------------------------------------------------------------------ PRIVE

protected:

User ();
    // Mode d'emploi :
    //      Constructeur protégé car classe abstraite

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int typeUser; // 0 si administrator, 1 si government, 2 si provider, 3 si private_user
string  id;
string  password;
string  firstName;
string  lastName;
string  mail;
};

//-------------------------------- Autres définitions dépendantes de <User>
std::unique_ptr<User> createUserFromLine(const std::string& line);


#endif // User_H
