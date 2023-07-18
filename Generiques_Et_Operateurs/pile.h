#pragma once
#include <stdexcept>
#include <iostream>
#include "liste.h"
#include <stdexcept>

class Pile_Operateurs;
template <class TypeElement>
class Pile {
public:
	Pile():
		m_nombreDElements(this->m_liste.nombreDElement()) 
	{
	};

	Pile(int p_capacite) :
		m_nombreDElements(0),
		m_liste(p_capacite)
	{
		;
	};

	~Pile() {
		for (int i = 0; i < this->m_nombreDElements / 2; ++i) {
			TypeElement valeurTemporaire = this->m_liste.obtenir(i);
			TypeElement valeurReference = this->m_liste.obtenir(this->m_nombreDElements - 1 - i);
			this->m_liste.definir(i, valeurReference);
			this->m_liste.definir(this->m_nombreDElements - 1 - i, valeurTemporaire);
		}
	};
	
	void empiler(TypeElement p_element) {
		this->m_liste.ajouter(p_element);
		++this->m_nombreDElements;
		this->m_liste.afficher();
	};

	TypeElement depiler() {
		int valeur = this->m_liste.obtenir(this->m_nombreDElements-1);
		if (this->m_liste.nombreDElement() > 0) {
			--this->m_nombreDElements;
			this->m_liste.supprimer(this->m_nombreDElements - 1);
		}
		else {
			throw std::invalid_argument("La liste est vide");
		}
		return valeur;

	};

	TypeElement sommet() {
		return this->m_liste.obtenir(this->m_nombreDElements - 1);
	};

	bool estPileVide() {
		bool vide = false;
		if (this->m_nombreDElements == 0) {
			vide = true;
		}
		return vide;
	};

	int taille() {
		return this->m_nombreDElements;
	};

	template <class TypeElement> friend Pile<TypeElement> operator+ (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator+= (Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);

private:
	Liste<TypeElement>m_liste;
	int m_nombreDElements;
};