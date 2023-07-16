#pragma once
#include <stdexcept>
#include <iostream>
#include "liste.h"

template <class TypeElement>
class File {
public:
	File() {};
	~File() {};
	
void enfiler(TypeElement p_element) {
	this->m_liste.ajouter(p_element);
	++this->m_nombreDElements;
	for (size_t i = this->m_nombreDElements - 1; i > 0; --i) {
		TypeElement valeurTemporaire = this->m_liste.obtenir(i - 1);
		this->m_liste.definir(i, valeurTemporaire);
	}
	this->m_liste.definir(0, p_element);
	this->m_liste.afficher();
}

TypeElement defiler() {
	TypeElement valeur = this->m_liste.obtenir(this->m_nombreDElements - 1);
	this->m_liste.supprimer(this->m_nombreDElements - 1);
	--this->m_nombreDElements;
	return valeur;
}

TypeElement tete() {
	return this->m_liste.obtenir(this->m_nombreDElements);
}

bool estFileVide() {
	return this->m_nombreDElements == 0;
}

int taille() {
	return this->m_nombreDElements;
}

private:
	Liste<TypeElement>m_liste;
	int m_nombreDElements;
};