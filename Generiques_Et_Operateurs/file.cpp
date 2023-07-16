//#include "file.h"
//#include <iostream>
//
//void File::enfiler(int p_element) {
//	this->m_liste.ajouter(p_element);
//	++this->m_nombreDElements;
//	for (size_t i = this->m_nombreDElements-1; i > 0; --i) {
//		int valeurTemporaire = this->m_liste.obtenir(i - 1);
//		this->m_liste.definir(i, valeurTemporaire);
//	}
//	this->m_liste.definir(0, p_element);
//}
//
//int File::defiler() {
//	this->m_liste.supprimer(this->m_nombreDElements - 1);
//	--this->m_nombreDElements;
//}
//
//int File::tete() {
//	return this->m_liste.obtenir(this->m_nombreDElements);
//}
//
//bool File::estFileVide() {
//	return this->m_nombreDElements == 0;
//}
//
//int File::taille() {
//	return this->m_nombreDElements;
//}