#pragma once
#include <string>
#include "pile.h"

template<class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) 
{
	return p_pile1.m_liste + p_pile2.m_liste;
	/*int capacite = p_pile1.m_nombreDElements + p_pile2.m_nombreDELements;
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
	return nouvellePile;*/
}

template<class TypeElement>
Pile<TypeElement> operator+=(Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	p_pile1.m_liste += p_pile2.m_liste;
	return p_pile1;
}

template<class TypeElement>
Pile<TypeElement> operator== (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	return p_pile1.m_liste == p_pile2.m_liste;
}

template<class TypeElement>
Pile<TypeElement> operator!= (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	return p_pile1.m_liste != p_pile2.m_liste;
}

template<class  TypeElement>
Pile<TypeElement> operator~ (Pile<TypeElement>& p_pile1) {
	for (int i = 0; i < this->m_nombreDElements / 2; ++i) {
		TypeElement valeurTemporaire = this->m_liste.obtenir(i);
		TypeElement valeurReference = this->m_liste.obtenir(this->m_nombreDElements - 1 - i);
		this->m_liste.definir(i, valeurReference);
		this->m_liste.definir(this->m_nombreDElements - 1 - i, valeurTemporaire);
	}
}

template<class TypeElement>
std::ostream& operator<<(std::ostream& stream, const Pile<TypeElement>& p_pile) {
	stream << this->m_liste;
}

