// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: main.cpp

#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Vilain.h"
#include "VilainHeros.h"
#include "Personnage.h"
#include "Hero.h"

using namespace std;
using namespace iter;

ifstream ouvrirFichierBinaire(const string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	return fichier;
}

void testsPourCouvertureLectureBinaire()
{
	istringstream iss("\xA0\x12\xA1\x21\x43\xA2\x98\xBA\xDC\xFE");
	assert(lireUintTailleVariable(iss) == 0x12);
	assert(lireUintTailleVariable(iss) == 0x4321);
	assert(lireUintTailleVariable(iss) == 0xFEDCBA98);
}

unique_ptr<vector<Vilain>> lireVilains(istream& fichier) {
	unique_ptr<vector<Vilain>> vilains = make_unique<vector<Vilain>>();
	size_t nVilains = lireUintTailleVariable(fichier);

	for (size_t i : range(nVilains)) {
		Vilain vilain(fichier);
		vilains->push_back(vilain);
	}
	return vilains;
}

unique_ptr<vector<Hero>> lireHeros(istream& fichier) {
	unique_ptr<vector<Hero>> heros = make_unique<vector<Hero>>();
	size_t nHeros = lireUintTailleVariable(fichier);

	for (size_t i : range(nHeros)) {
		Hero hero(fichier);
		heros->push_back(hero);
	}
	return heros;
}


int main()
{
	#pragma region "Bibliothèque du cours"
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	
	//Test main
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	static const string ligneSeparation = "\n\033[95m═════════════════════════════════════════════════════════════════════════\n\033[0m";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	// 1. Creation des vecteurs de Hero, Vilain et Personnage + affichage
	unique_ptr<vector<Hero>> heros = move(lireHeros(fichierHeros));
	unique_ptr<vector<Vilain>> vilains = move(lireVilains(fichierVilains));
	vector<unique_ptr<Personnage>> personnages;

	for (Hero& hero : *heros) {
		cout << trait << endl;
		hero.afficher(cout);
		personnages.push_back(make_unique<Hero>(hero));
	}

	cout << ligneSeparation << endl;

	for (Vilain& vilain : *vilains) {
		cout << trait << endl;
		vilain.afficher(cout);
		personnages.push_back(make_unique<Vilain>(vilain));
	}
	cout << ligneSeparation << endl;

	for (unique_ptr<Personnage>& personnage : personnages) { 
		cout << trait << endl;
		personnage->afficher(cout); 
	}

	cout << ligneSeparation << endl;

	vector<Hero> heros1 = *heros;
	vector<Vilain> vilains1 = *vilains;

	VilainHeros v = VilainHeros(heros1[0], vilains1[2]);
	v.afficher(cout);

	personnages.push_back(make_unique<VilainHeros>(v));
}
