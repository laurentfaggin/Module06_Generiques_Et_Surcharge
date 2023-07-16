#pragma once
#include <string>
#include "pile.h"

template<class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) 
{
	int capacite = p_pile1.m_nombreDElements + p_pile2.m_nombreDELements;
	if (capacite == 0) {
		capacite = 1;
	}
	Pile<TypeElement> nouvellePile(capacite);
	for (size_t i = 0; i < p_pile1.m_nombreDElements; ++i) {
		nouvellePile.empiler(p_pile1.M_liste.obtenir(i));
	}
	for (size_t i = 0; i < p_pile2.m_nombreDElements; ++i) {
		nouvellePile.empiler(p_pile2.M_liste.obtenir(i));
	}
	nouvellePile = p_liste1 + p_liste2;
	return nouvellePile;
}

template<class TypeElement>
Pile<TypeElement> operator+=(Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	p_pile1.m_liste += p_pile2.m_liste;
	return p_pile1;
}