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
	void virtual afficher(ostream& os) = 0;
	void virtual changerCouleur(string& couleur) = 0;


private:


};