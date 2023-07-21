#include <stdexcept>
#include <iostream>
#include "pile_methodes.h"



bool caracteresCorrectementImbriques(std::string p_string) {
	Pile<char> pile;
	bool ok = true;
	for (char c : p_string) {
		if (c == '(' || c == '{' || c == '[') {
			pile.empiler(c);
		}
		else if ((c == ')' && pile.sommet() == '(') ||
				(c == '}' && pile.sommet() == '{') ||
				(c == ']' && pile.sommet() == '['))
		{
			pile.depiler();
		}
		else {
			ok = false;
		}
	}
	if (ok && pile.estPileVide()) {
		ok = true;
	}
	return ok;
}