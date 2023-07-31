#pragma once
#include <iostream>
#include <string>


//template<class TypeElement>
//bool executerPredicat(bool (*p_predicat)(TypeElement), TypeElement p_element) {
//	return p_predicat(p_element);
//}

template<class TypeElement>
void filtrer_rec(bool(*p_predicat)(TypeElement), const TypeElement* p_tableauAFiltrer, int p_tailleTableauAFiltrer, TypeElement* p_tableauFiltre, int& p_tailleTableauFiltre) {
	filtrer_rec(p_predicat, p_tableauAFiltrer, p_tailleTableauAFiltrer - 1, p_tableauFiltre, p_tailleTableauFiltre);
	if (p_predicat(p_tableauAFiltrer[p_tailleTableauAFiltrer - 1])) {
		p_tableauFiltre[p_tailleTableauFiltre] = p_tableauAFiltrer[p_tailleTableauAFiltrer - 1];
		++p_tailleTableauFiltre;
	}
	return p_tableauFiltre;
}

template<class TypeElement>
Liste<TypeElement>* filtrer(const TypeElement* p_tableauAFiltrer, int p_tailleTableauAFiltrer, bool(p_predicat)(TypeElement)) {
	TypeElement* p_tableauFiltre = new TypeElement[p_tailleTableauAFiltrer];
	int p_tailleTableauFiltre = 0;
	filtrer_rec(p_predicat, p_tableauAFiltrer, p_tailleTableauAFiltrer, p_tableauFiltre, p_tailleTableauFiltre);
	return p_tableauFiltre;
}