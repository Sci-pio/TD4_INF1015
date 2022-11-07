// Auteurs: Leonard Pouliot (2150965) et Kamil Maarite (2152653)
// Date: 06 novembre 2022
// cours: INF1015
// Nom de la classe: VilainHeros.h

#pragma once
#include <fstream>
#include "Personnage.h"
#include "lectureBinaire.hpp"
#include "Vilain.h"
#include "Hero.h"

class VilainHeros : public Hero, public Vilain {
public:
	VilainHeros(const Hero& hero, const Vilain& vilain) :
		Hero(hero),
		Vilain(vilain),
		Personnage(vilain.getNom() + "-" + hero.getNom(),
			vilain.getJeuParution() + "-" + hero.getJeuParution()),
		missionSpeciale_(getObjectif() + " dans le monde de " + hero.getJeuParution())
	{ }

	void afficher(ostream& os) const override
	{
		Personnage::changerCouleur(os, Couleur::VERT);
		Personnage::afficher(cout);
		Vilain::afficherAttributsSpecifiques(cout);
		Hero::afficherAttributSpecifiques(cout);
		cout << "Mission spéciale: " << missionSpeciale_;
		Personnage::changerCouleur(os, Couleur::DEFAUT);
	}

private:
	string missionSpeciale_;
};