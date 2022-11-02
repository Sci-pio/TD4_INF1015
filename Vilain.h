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


	void afficher(ostream& os)  const override {
		Personnage::afficher(os);
		changerCouleur(os, Couleur :: rouge);
		os << "Objetif: " << objectif_ << endl;
		changerCouleur(os, Couleur :: defaut);
	};

private:
	string objectif_;
};

