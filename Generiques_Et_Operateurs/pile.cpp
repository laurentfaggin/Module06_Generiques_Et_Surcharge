//#include "pile.h"
//#include <iostream>
//
//Pile::Pile() {  }
//
//void Pile::empiler(int p_element) {
//	this->m_liste.ajouter(p_element);
//	++this->m_nombreDElements;
//}
//
//int Pile::depiler() {
//	int valeur = this->m_liste.obtenir(this->m_nombreDElements-1);
//	this->m_liste.supprimer(this->m_nombreDElements - 1);
//	--this->m_nombreDElements;
//	return valeur;
//
//}
//
//int Pile::sommet() {
//	return this->m_liste.obtenir(this->m_nombreDElements - 1);
//}
//
//bool Pile::estPileVide() {
//	bool vide = false;
//	if (this->m_nombreDElements == 0) {
//		vide = true;
//	}
//	return vide;
//	//return this->m_nombreDElements == 0;
//}
//
//int Pile::taille() {
//	return this->m_nombreDElements;
//}