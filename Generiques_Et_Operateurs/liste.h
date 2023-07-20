#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>

#include "collection.h"

class operateur;
template <class TypeElement>
class Liste : public collection < TypeElement> {
public:
	Liste() {
		this->m_nombreDElements = 0;
		this->m_capacite = 20;
		this->m_liste = new TypeElement[20];
	}
	Liste(int p_capacite) :
		m_nombreDElements(0),
		m_capacite(p_capacite),
		m_liste(nullptr)
	{
		if (p_capacite > 0) {
			m_liste = new TypeElement[p_capacite];
		}
		else {
			throw std::invalid_argument("erreur capacite");
		}
	};

	Liste(const Liste<TypeElement>& p_listeACopier) :
		m_nombreDElements(p_listeACopier.m_nombreDElements),
		m_capacite(p_listeACopier.m_capacite),
		m_liste(nullptr)
	{
		this->m_liste = new int[this->m_capacite];
		for (int i = 0; i < p_listeACopier.m_nombreDElements; i++) {
			this->m_liste[i] = p_listeACopier.m_liste[i];
		}
	}

	Liste(Liste&& p_listeADeplacer) :
		m_nombreDElements(p_listeADeplacer.m_nombreDElements),
		m_capacite(p_listeADeplacer.m_capacite),
		m_liste(p_listeADeplacer.m_liste)
	{
		p_listeADeplacer.m_nombreDElements = 0;
		p_listeADeplacer.m_capacite = 0;
		p_listeADeplacer.m_liste = nullptr;
	}

	~Liste() {
		if (this->m_liste != nullptr) {
			delete[] this->m_liste;
			this->m_liste = nullptr;
		}
	};

	int capacite()const {
		return this->m_capacite;
	}

	int nombreDElement()const {
		return this->m_nombreDElements;
	}

	virtual void ajouterFin(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		this->m_liste[this->m_nombreDElements] = p_element;
		++ this->m_nombreDElements;
	}

	virtual void ajouterDebut(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		for (size_t i = this->m_nombreDElements; i > 0; --i) {
			this->m_liste[i] = this->m_liste[i - 1];
		}
		this->m_liste[0] = p_element;

		++this->m_nombreDElements;
	}

	virtual void supprimer(const int& p_index) {
		if (p_index > this->m_nombreDElements) {
			throw std::invalid_argument("la liste est vide a cet endroit");
		}
		for (int i = p_index; i < this->m_nombreDElements - 1; i++) {
			this->m_liste[i] = this->m_liste[i + 1];
		}
		-- this->m_nombreDElements;
	};

	virtual void supprimerFin() {
		if (this->m_nombreDElements == 0) {
			throw std::invalid_argument("la liste est vide");
		}
		--this->m_nombreDElements;
	}

	virtual TypeElement obtenir(const int& p_index) const {
		if (p_index >= this->m_nombreDElements) {
			throw std::invalid_argument("la liste n'a pas de valeur acet emplacement");
		}
		return this->m_liste[p_index];
	};

	virtual void definir(const int& p_index, const TypeElement& p_element) {
		if (p_index >= this->m_nombreDElements) {
			throw std::invalid_argument("La liste contient deja un element");
		}
		this->m_liste[p_index] = p_element;
	};

	virtual std::string toString() {
		std::stringstream affiche;
		affiche << "[";
		for (int i = 0; i < this->m_nombreDElements; i++) {
			affiche << this->obtenir(i) << " ";
		}
		affiche << "]";
		
		return affiche.str();
	};



	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste, TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste, TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class Typeelement> friend Liste<Typeelement>& operator~ (const Liste<TypeElement>& p_liste);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& stream, const Liste<TypeElement>& p_liste);
	template <class TypeElement> friend bool operator== (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend bool operator!= (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);

private:
	int m_nombreDElements;
	int m_capacite;
	TypeElement* m_liste;

	void agrandirCapaciteSiNessaire() {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
	}
};
