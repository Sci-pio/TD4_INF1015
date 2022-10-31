#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Personnage.h"


using namespace std;

class Hero : virtual public Personnage {
public:
	Hero() = default;
	Hero (string& nom, string& jeuDeParution, string& Ennemi, vector<string>& listeDesAllies): Personnage(nom, jeuDeParution), Ennemi_(Ennemi), listeDesAllies_(listeDesAllies){}
	~Hero() = default;

	void afficher(ostream& os) const override{ 
		changerCouleur(os , "bleu");
		Personnage::afficher(os); //afficher les attributs d'un Hero qui sont des attributs de personnage (nom, jeu de parution)
		os << "Ennemi: " << Ennemi_ << endl;
		os << "Alliés: " << endl;
		for (int i = 0; i < listeDesAllies_.size(); i++) { os << listeDesAllies_[i] << endl; }
		changerCouleur(os, "default");
	};

private:
	string Ennemi_;
	vector<string> listeDesAllies_;

};

