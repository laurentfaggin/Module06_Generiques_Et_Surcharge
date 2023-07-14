#pragma once
#include <stdexcept>
#include <iostream>
#include "liste.h"

class File : public Liste<int> {
	void empiler(int p_element);
	int depiler();
	int sommet();
	bool estPileVide();
	int taille();
	~File();
};