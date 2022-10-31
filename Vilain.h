#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Personnage.h"

using namespace std;

class Vilain: virtual public Personnage {
public:
	Vilain() = default;
	Vilain(string& nom, string& jeuDeParution, string& objectif): Personnage(nom, jeuDeParution), objectif_(objectif){}
	~Vilain() = default;


	void afficher(ostream& os)  const override {
		Personnage::afficher(os);
		changerCouleur(os, "rouge");
		os << "Objetif: " << objectif_ << endl;
		changerCouleur(os, "default");
	};

private:
	string objectif_;
};

