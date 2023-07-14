#pragma once
#include <stdexcept>
#include <iostream>
#include "liste.h"

class Pile : Liste<int> {
	void enfiler(int p_element);
	int defiler();
	int tete();
	bool estFileVide();
	int taille();
	~Pile();
};