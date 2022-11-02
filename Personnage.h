#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cassert>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <functional>
#include <string>
#include "Affichable.h"

using namespace std;

class Personnage:public Affichable {
public:
	Personnage() = default;
	Personnage(istream& fichier): nom_(lireString(fichier)), jeuParution_(lireString(fichier)) {}
	//Personnage(string& nom, string& jeuParution) : nom_(nom), jeuParution_(jeuParution) {}
	~Personnage() = default;

	void virtual changerCouleur(ostream& os, const string& couleur) const override{
		if (couleur == "rouge") { os << "\n\033[91m"; }
		else if (couleur == "bleu") { os << "\n\033[94m"; }
		else { os << "\n\033[0m"; }
	};

	void virtual afficher(ostream& os) const {
		os << "Nom: " << nom_ << endl;
		os << "Jeu de parution: " << jeuParution_ << endl;
	};



private:
	string nom_, jeuParution_;
};

