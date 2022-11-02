#pragma once
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
#include "Affichable.h"

class VilainHeros: public Hero, public Vilain, public Personnage {
public:
	VilainHeros(string& nom, string& jeuDeParution, string& objectif, string& ennemi, vector<string> listeDesAllies, string& missionSpeciale, Hero& hero, Vilain& vilain): Personnage(nom, jeuDeParution), 


};