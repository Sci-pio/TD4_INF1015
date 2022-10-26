#pragma once
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Personnage.h"

using namespace std;

class Vilain: public Personnage {
public:
	Vilain();
	Vilain(string& nom, string& jeuParution, string& objectif);
	~Vilain() = default;

	void virtual changerCouleur(string& couleur)  override;
	void virtual afficher(ostream& os)  override;

private:
	string objectif_;
};
=======
>>>>>>> edbf3ff7ff04683fb9dab3008cf0cfba3acef341
