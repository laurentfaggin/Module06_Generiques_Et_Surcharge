#pragma once
#include <iostream>
#include "pile.h"

template<class TypeElement>
int compteurDeCaractere(const Pile<TypeElement>& p_pile, TypeElement p_caractere) {
	int compteur = 0;
	for (size_t i = 0; i < p_pile.taille() - 1; ++i) {
		if (p_pile.m_liste.obtenir(i) == p_caractere) {
			++compteur;
		}
	}
	return compteur;
};

template<class TypeElement>
TypeElement premierCaractereDesPaires(const TypeElement& p_caractere) {
	return p_caractere;
}

template<class TypeElement>
bool caractereOuvrantEtFermantPresent(const Pile<TypeElement>& p_pile, TypeElement p_caractere1, TypeElement p_caractere2) {
	bool estPresent = false;
}

