// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: Hero.h

#pragma once
#include <fstream>
#include <vector>
#include "Personnage.h"
#include "lectureBinaire.hpp"

using namespace std;
using namespace iter;

class Hero : virtual public Personnage {
public:
	Hero(istream& fichier) : Personnage(fichier), Ennemi_(lireString(fichier))
	{
		size_t nAllies = lireUintTailleVariable(fichier);

		for (size_t i : range(nAllies)) {
			listeDesAllies_.push_back(lireString(fichier));
		}
	}

	virtual ~Hero() = default;

	virtual void afficher(ostream& os) const override
	{
		changerCouleur(os, Couleur::BLEU);
		Personnage::afficher(os);
		afficherAttributSpecifiques(os);
	};

	void afficherAttributSpecifiques(ostream& os) const
	{
		os << "Ennemi: " << Ennemi_ << endl;
		os << "Alliés: " << endl;

		for (size_t i = 0; i < listeDesAllies_.size(); i++) 
		{ 
			os << "\t" << listeDesAllies_[i] << endl; 
		}
	}

private:
	string Ennemi_;
	vector<string> listeDesAllies_;
};

