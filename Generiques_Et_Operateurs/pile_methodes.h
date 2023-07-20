#pragma once
#include <iostream>
#include <string>



template<class TypeElement>
Pile<TypeElement> caracteresCorrectementImbriques(const Pile<TypeElement>& p_pile) {
	Pile<char> pile;
	std::string liste = p_pile.pileToString();
	bool ok = true;
	for (char c : liste) {
		if (c == '(' || c == '{' || c == "[") {
			pile.empiler();
		}
		if ((c == ')' && pile.sommet() == '(') ||
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