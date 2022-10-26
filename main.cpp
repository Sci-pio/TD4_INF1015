#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"

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
vector<Vilain>& lireVilains(istream& fichier) {
	vector<Vilain> vilains;
	size_t nVilains = lireUintTailleVariable(fichier);

	for (size_t i : range(nVilains)) {
		Vilain vilain;

		vilain.nom = lireString(fichier);
		vilain.jeuParution = lireString(fichier);
		vilain.objectif = lireString(fichier);

		vilains.push_back(vilain);
	}
	return vilains;
}

vector<Hero>& lireHeros(istream& fichier) {
	vector<Hero> heros;
	size_t nHeros = lireUintTailleVariable(fichier);

	for (size_t i : range(nHeros)) {
		Hero hero;

		hero.name = lireString(fichier);
		hero.jeuParution = lireString(fichier);
		hero.ennemi = lireString(fichier);

		vector<string> allies;
		size_t nAllies = lireUintTailleVariable(fichier);
		
		for (size_t i : range(nAllies)) {
			allies.push_back(lireString(fichier));
		}
		hero.allies = allies;

		heros.push_back(hero);
	}
	return heros;
}


int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	
	//Test main
	testsPourCouvertureLectureBinaire();

	// Trait de separation
	static const string trait =
		"═════════════════════════════════════════════════════════════════════════";

	// Ouverture des fichiers binaires
	ifstream fichierHeros = ouvrirFichierBinaire("heros.bin");
	ifstream fichierVilains = ouvrirFichierBinaire("vilains.bin");

	vector<Hero> heros = lireHeros(fichierHeros);
	vector<Vilain> vilains = lireVilains(fichierVilains);

	for (Hero& hero : heros) {
		hero.afficher();
	}

	for (Vilain& vilain : vilains) {
		vilain.afficher();
	}


	//TODO: Votre code pour le main commence ici (mais vous pouvez aussi ajouter/modifier du code avant si nécessaire)

}
