#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Vilain.h"
#include "Affichable.h"

using namespace std;

class Personnage: public Affichable {
public:
	Personnage(istream& fichier): nom_(lireString(fichier)), jeuParution_(lireString(fichier)) {}

	virtual ~Personnage() = default;

	void changerCouleur(ostream& os, const Couleur& couleur) const override{
		if (couleur == Couleur :: rouge) { os << "\n\033[91m"; }
		else if (couleur == Couleur::bleu) { os << "\n\033[94m"; }
		else if (couleur == Couleur::defaut) { os << "\n\033[0m"; }
	};

	void  afficher(ostream& os) const override {
		os << "Nom: " << nom_ << endl;
		os << "Jeu de parution: " << jeuParution_;
	};


private:
	string nom_, jeuParution_;
};

