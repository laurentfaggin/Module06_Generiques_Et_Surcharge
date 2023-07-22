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

Pile<char>infixeConvertiEnPostfixe(std::string p_stringInfixe) {
	Pile<char>pilePostfixe;
	Pile<char>pileStach;

	for (char c : p_stringInfixe) {
		int priorite = evaluationPriorite(c);
		if(c == '(' || priorite == 0) {
			pilePostfixe.empiler(c);
		}
		if (c == ')' && !pilePostfixe.estPileVide()) {
			while (c != '(' || !pileStach.estPileVide()) {
				pilePostfixe.empiler(pileStach.sommet());
				pileStach.depiler();
			}
		}
		if (priorite > 0 && !pilePostfixe.estPileVide()) {
			pileStach.empiler(c);
		}
		if (priorite > 0 && priorite < evaluationPriorite(pileStach.sommet())) {
			pilePostfixe.empiler(pileStach.sommet());
			pileStach.depiler();
			pileStach.empiler(c);
		}
		if (priorite > 0 && priorite > evaluationPriorite(pileStach.sommet())) {
			pileStach.empiler(c);
		}
	}
	while (!pileStach.estPileVide()) {
		pilePostfixe.empiler(pileStach.sommet());
		pileStach.depiler();
	}
	return pilePostfixe;
}

int evaluationPriorite(char p_char) {
	int priorite = 0;
	if (p_char == '-') {
		priorite = 1;
	}
	else if (p_char == '+') {
		priorite = 2;
	}
	else if (p_char == '/') {
		priorite = 3;
	}
	else if (p_char == '*') {
		priorite = 4;
	}
	else{
		priorite = 0;
	}
	return priorite;
}