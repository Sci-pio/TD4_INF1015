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
	Personnage(string& nom, string& jeuParution) : nom_(nom), jeuParution_(jeuParution) {}
	~Personnage() = default;

	void virtual changerCouleur(string couleur) const{};

	void virtual afficher(ostream& os) const {

		os << nom_ << endl;
		os << jeuParution_ << endl;
	};



private:
	string nom_, jeuParution_;
};

