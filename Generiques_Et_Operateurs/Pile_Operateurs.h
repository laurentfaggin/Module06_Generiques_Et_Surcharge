#pragma once
#include <string>
#include "pile.h"

template<class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) 
{
	return p_pile1.m_liste + p_pile2.m_liste;
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
Pile<TypeElement> operator~ (const Pile<TypeElement>& p_pile) {
	Liste<TypeElement> nouvelleListe(p_pile.taille());
	for (int i = 0; i < p_pile.taille() / 2; ++i) {
		TypeElement valeurDebut = p_pile.m_liste.obtenir(i);
		TypeElement valeurFin = p_pile.m_liste.obtenir(p_pile.taille()- 1 - i);
		nouvelleListe.definir(i, valeurFin);
		nouvelleListe.definir(p_pile.taille()- 1 - i, valeurDebut);
	}
	return nouvelleListe;
}

template<class TypeElement>
std::ostream& operator<<(std::ostream& stream, const Pile<TypeElement>& p_pile) {
	stream << p_pile.m_liste;
	return stream;
}

