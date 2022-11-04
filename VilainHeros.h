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
	
	void afficher(ostream& os) const override {
		Personnage::changerCouleur(os,Couleur::vert);
		//faire afficher ses attributs

		Personnage::changerCouleur(os, Couleur::defaut);

	}

	/*VilainHeros(Hero& hero, Vilain& vilain): nom_("b")*/
};