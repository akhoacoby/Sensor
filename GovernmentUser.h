/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <GovernmentUser> (fichier GovernmentUser.h) ----------------
#if ! defined ( GovernmentUser_H )
#define GovernmentUser_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovernmentUser>
//      Classe qui permet de construire, cloner et afficher Les GovernmentUser (utilisateurs de l'agence gouvernementale)
//------------------------------------------------------------------------

class GovernmentUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (void) const;
    // Mode d'emploi :
    //      Affiche le nom, le prénom et le mail du GovernmentUser

    int Verify_pw(const string& mdp) override;
    // Mode d'emploi :
    //      verifie si le mot de passe donné en entrée correspond au mot de passe. renvoie 0 si ils correspondent, 1 sinon.

    string getTrans() const override;

//-------------------------------------------- Constructeurs - destructeur

    GovernmentUser (string Id, string Password, string FirstName, string LastName, string Mail);
    GovernmentUser (string Password, string FirstName, string LastName, string Mail);



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <GovernmentUser>

#endif // GovernmentUser_H
