#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Personnage.h"
#include "Vilain.h"
#include "Hero.h"

class VilainHeros: public Hero, public Vilain {
private:
	string missionSpeciale_;

public:
	
	VilainHeros(Hero& hero, Vilain& vilain) : Personnage(hero.getNom() + "-" + vilain.getNom(), hero.getJeuParution() + "-" + vilain.getJeuParution()), Hero(hero), Vilain(vilain), missionSpeciale_(vilain.getObjectif() + " dans le monde de " + hero.getJeuParution()) { }

	void afficher(ostream& os) const override {
		Personnage::changerCouleur(os,Couleur::vert);
		Personnage::afficher(cout);
		Hero::afficherAttributSpecifiques(cout);
		Vilain::afficherAttributsSpecifiques(cout);
		cout << "Mission speciale: " << missionSpeciale_; // erreur
		Personnage::changerCouleur(os, Couleur::defaut);

	}

	/*VilainHeros(Hero& hero, Vilain& vilain): nom_("b")*/
};