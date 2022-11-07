// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: Personnage.h

#pragma once
#include <sstream>
#include "Affichable.h"
#include "lectureBinaire.hpp"


using namespace std;

class Personnage : public Affichable {
public:
	Personnage(istream& fichier) :
		nom_(lireString(fichier)),
		jeuParution_(lireString(fichier))
	{}

	Personnage(const string& nom, const string& jeuParution) :
		nom_(nom),
		jeuParution_(jeuParution)
	{}

	Personnage() = default;

	virtual ~Personnage() = default;

	virtual void changerCouleur(ostream& os, const Couleur& couleur) const override {
		if (couleur == Couleur::ROUGE) { os << "\n\033[91m"; }
		else if (couleur == Couleur::BLEU) { os << "\n\033[94m"; }
		else if (couleur == Couleur::VERT) { os << "\n\033[92m"; }
		else if (couleur == Couleur::DEFAUT) { os << "\n\033[0m"; }
	};

	virtual void afficher(ostream& os) const override {
		os << "Nom: " << nom_ << endl;
		os << "Parution: " << jeuParution_ << endl;
	};

	string getNom() const { return nom_; }
	string getJeuParution() const { return jeuParution_; }

private:
	string nom_, jeuParution_;
};

