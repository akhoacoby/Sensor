/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <PrivateUser> (fichier PrivateUser.h) ----------------
#if ! defined ( PrivateUser_H )
#define PrivateUser_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PrivateUser>
//      Classe qui permet de construire, cloner et afficher Les PrivateUser (utilisateurs particuliers)
//------------------------------------------------------------------------

class PrivateUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (void) const;
    // Mode d'emploi :
    //      Affiche le nom, le prénom et le mail du PrivateUser

    virtual int getScore(void) const;
    virtual void setScore(int nouveau);
    void ChangerScore(int add);
    string getTrans() const override;

//-------------------------------------------- Constructeurs - destructeur

    PrivateUser (string Id, string Password, string FirstName, string LastName, string Mail);
    PrivateUser (string Password, string FirstName, string LastName, string Mail);
    // Mode d'emploi :
    //      Utilisé dans la méthode clone


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int score;
Cleaner* liste_airCleaner;
};

//-------------------------------- Autres définitions dépendantes de <PrivateUser>

#endif // PrivateUser_H
