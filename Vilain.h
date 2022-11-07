// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: Vilain.h

#pragma once
#include <fstream>
#include "Personnage.h"
#include "lectureBinaire.hpp"

using namespace std;

class Vilain: virtual public Personnage {
public:
	Vilain(istream& fichier): Personnage(fichier), objectif_(lireString(fichier)){}

	virtual ~Vilain() = default;

	virtual void afficher(ostream& os)  const override 
	{
		changerCouleur(os, Couleur::ROUGE);
		Personnage::afficher(os);
		afficherAttributsSpecifiques(os);
	};

	void afficherAttributsSpecifiques(ostream& os) const 
	{
		os << "Objetif: " << objectif_ << endl;
	}


	string getObjectif() const { return objectif_; }

private:
	string objectif_;
};

