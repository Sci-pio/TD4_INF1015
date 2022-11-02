#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Vilain.h"
#include "VilainHeros.h"
#include "Personnage.h"
#include "Hero.h"
#include "Affichable.h"

using namespace std;

class Hero : virtual public Personnage {
public:
	Hero(istream& fichier): Personnage(fichier), Ennemi_(lireString(fichier)) {;
		size_t nAllies = lireUintTailleVariable(fichier);

		for (size_t i : range(nAllies)) {
			listeDesAllies_.push_back(lireString(fichier));
		}
	}
	virtual ~Hero() = default;

	void afficher(ostream& os) const override{ 
		changerCouleur(os , Couleur :: bleu);
		Personnage::afficher(os); //afficher les attributs d'un Hero qui sont des attributs de personnage (nom, jeu de parution)
		os << "Ennemi: " << Ennemi_ << endl;
		os << "Alliés: " << endl;
		for (int i = 0; i < listeDesAllies_.size(); i++) { os << listeDesAllies_[i] << endl; }
		changerCouleur(os, Couleur :: defaut);
	};

private:
	string Ennemi_;
	vector<string> listeDesAllies_;

};

