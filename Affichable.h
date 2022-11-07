// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: Affichable.h

#pragma once
#include <iostream>
#include <fstream>

using namespace std;

enum class Couleur {
	ROUGE,
	BLEU,
	VERT,
	DEFAUT
};

class Affichable {
public:
	void virtual afficher(ostream& os) const = 0;
	void virtual changerCouleur(ostream& os, const Couleur& couleur) const = 0;

	virtual ~Affichable() = default;
};