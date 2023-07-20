#pragma once
#include <iostream>
#include <string>
#include "pile.h"



template<class TypeElement>
bool caracteresCorrectementImbriques(const Pile<TypeElement>& p_pile) {
	Pile<char> pile;
	std::string liste = p_pile.listeToString();
	bool ok = true;
	for (char c : p_string) {
		if (c == '(' || c == '{' || c == "[") {
			pile.empiler();
		}
		if (c == ')' && pile.sommet() == '(' ||
			c == '}' && pile.sommet() == '{' ||
			c == ']' && pile.sommet() == '[') 
		{
			pile.depiler();
		}
		else {
			ok = false;
		}
	}
	return ok && pile.estPileVide();
}