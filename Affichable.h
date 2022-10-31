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

class Affichable {
public:
	void virtual afficher(ostream& os) const = 0;
	void virtual changerCouleur(ostream& os, const string& couleur) const = 0;


private:


};