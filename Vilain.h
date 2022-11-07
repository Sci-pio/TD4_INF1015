#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Personnage.h"

using namespace std;
using namespace iter;

class Vilain: virtual public Personnage {
public:
	Vilain(istream& fichier): Personnage(fichier), objectif_(lireString(fichier)){}
	virtual ~Vilain() = default;


	void virtual afficher(ostream& os)  const override {
		changerCouleur(os, Couleur::rouge);
		Personnage::afficher(os);
		os << "Objetif: " << objectif_ << endl;
		changerCouleur(os, Couleur :: defaut);
	};

	void afficherAttributsSpecifiques(ostream& os) const {
		os << "Objetif: " << objectif_ << endl;
	}

	string getObjectif() { return objectif_; }

private:
	string objectif_;
};

