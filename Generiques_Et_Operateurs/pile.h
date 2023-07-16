#pragma once
#include <stdexcept>
#include <iostream>
#include "liste.h"

template <class TypeElement>
class Pile {
public:
	Pile();
	~Pile();
	void empiler(int p_element);
	TypeElement depiler();
	TypeElement sommet();
	bool estPileVide();
	int taille();

	Pile() {  }

	void empiler(TypeElement p_element) {
		this->m_liste.ajouter(p_element);
		++this->m_nombreDElements;
	}

	TypeElement depiler() {
		int valeur = this->m_liste.obtenir(this->m_nombreDElements - 1);
		this->m_liste.supprimer(this->m_nombreDElements - 1);
		--this->m_nombreDElements;
		return valeur;

	}

	TypeElement sommet() {
		return this->m_liste.obtenir(this->m_nombreDElements - 1);
	}

	bool estPileVide() {
		bool vide = false;
		if (this->m_nombreDElements == 0) {
			vide = true;
		}
		return vide;
		//return this->m_nombreDElements == 0;
	}

	int taille() {
		return this->m_nombreDElements;
	}
private:
	Liste<TypeElement>m_liste;
	int m_nombreDElements;
};