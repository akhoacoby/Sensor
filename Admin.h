/*************************************************************************
                           User  -  description
                             -------------------
    début                : $14/05/2025$
    copyright            : (C) $YEAR$ par $Bachet, Lèbre, Bahda, Bui, Baginski$
    e-mail               : $EMAIL$
*************************************************************************/
//---------- Interface de la classe <Admin> (fichier Admin.h) ----------------
#if ! defined ( Admin_H )
#define Admin_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Admin>
//      Classe qui permet de construire, cloner et afficher Les Admin (administrateurs)
//------------------------------------------------------------------------ 

class Admin : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (void) const;
    // Mode d'emploi :
    //      Affiche le nom, le prénom et le mail du Admin

    int Verify_pw(const string& mdp) override;
    // Mode d'emploi :
    //      verifie si le mot de passe donné en entrée correspond au mot de passe. renvoie 0 si ils correspondent, 1 sinon.

    string getTrans() const override;
    // virtual User* clone() const ;

//-------------------------------------------- Constructeurs - destructeur

    Admin (string Id, string Password, string FirstName, string LastName, string Mail);
    Admin (string Password, string FirstName, string LastName, string Mail);
    // Mode d'emploi :
    //      Utilisé dans la méthode clone



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Admin>

#endif // Admin_H
