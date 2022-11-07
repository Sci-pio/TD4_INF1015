#pragma once
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Personnage.h"
#include "lectureBinaire.hpp"


using namespace std;
using namespace iter;

class Hero : virtual public Personnage {
public:
	Hero(istream& fichier) : Personnage(fichier), Ennemi_(lireString(fichier)) {
		;
		size_t nAllies = lireUintTailleVariable(fichier);

		for (size_t i : range(nAllies)) {
			listeDesAllies_.push_back(lireString(fichier));
		}
	}
	virtual ~Hero() = default;

	void virtual afficher(ostream& os) const override {
		changerCouleur(os, Couleur::bleu);
		Personnage::afficher(os); //afficher les attributs d'un Hero qui sont des attributs de personnage (nom, jeu de parution)
		os << "Ennemi: " << Ennemi_ << endl;
		os << "Alli�s: " << endl;
		for (int i = 0; i < listeDesAllies_.size(); i++) { os << "\t" << listeDesAllies_[i] << endl; }
		changerCouleur(os, Couleur::defaut);
	};
	virtual string getEnnemi() { return Ennemi_; }

	void afficherAttributSpecifiques(ostream& os) const {
		os << "Ennemi: " << Ennemi_ << endl;
		os << "Alli�s: " << endl;
		for (int i = 0; i < listeDesAllies_.size(); i++) { os << "\t" << listeDesAllies_[i] << endl; }
	}
	

private:
	string Ennemi_;
	vector<string> listeDesAllies_;

};

