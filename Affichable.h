#pragma once
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cassert>
#include "cppitertools/range.hpp"
#include "gsl/span"
#include <functional>
#include <string>

using namespace std;
using namespace iter;

enum class Couleur {
	rouge,
	bleu,
	vert,
	defaut
};

class Affichable {
public:
	virtual ~Affichable() = default;

	void virtual afficher(ostream& os) const = 0;
	void virtual changerCouleur(ostream& os, const Couleur& couleur) const = 0;
};