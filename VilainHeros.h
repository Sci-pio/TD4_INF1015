#pragma once
#include "lectureBinaire.hpp"
#include <fstream>
#include <sstream>
#include <cassert>
#include <vector>
#include "cppitertools/range.hpp"
#include "bibliotheque_cours.hpp"
#include "Personnage.h"
#include "Hero.h"

class VilainHeros: public Hero, public Vilain, public Personnage {
private:
	string missionSpeciale_;

public:
	
	VilainHeros(Hero& hero, Vilain& vilain) : Hero(hero), Vilain(vilain), missionSpeciale_(vilain.getObjectif()+" - "+hero.getJeuParution()) { }

	void afficher(ostream& os) const override {
		Personnage::changerCouleur(os,Couleur::vert);
		
		Personnage::afficher(cout);
		//cout << "Mission speciale: " << Vilain::getObjectif() << "dans le monde de " << Hero::getJeuParution() << endl; // erreur

		Personnage::changerCouleur(os, Couleur::defaut);

	}

	/*VilainHeros(Hero& hero, Vilain& vilain): nom_("b")*/
};