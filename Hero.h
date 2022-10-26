#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Personnage.h"

using namespace std;

class Hero : public Personnage {
public:
	void virtual changerCouleur(string couleur) const override {
	if (couleur=="rouge") { cout << "\n\033[90m"; }
	else if (couleur == "default") { cout << "\n\033[0m"; }
	}

	void virtual afficher(ostream& os) const override{ 
		changerCouleur("rouge");
		os << Ennemi_ << endl;
		// faut faire os << les trucs du vecteur

		changerCouleur("default");
	
	};

private:
	vector<string> listeDesAllies_;
	string Ennemi_;
};

