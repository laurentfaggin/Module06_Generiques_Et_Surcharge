#pragma once
#include "collection.h"
#include <stdexcept>
#include <iostream>

class operateur;
template <class TypeElement>
class Liste : public collection < TypeElement> {
public:
	Liste(){
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

	Liste(const Liste<TypeElement>& p_listeACopier):
		m_liste(p_listeACopier.m_liste),
		m_capacite(p_listeACopier.m_capacite),
		m_nombreDElements(p_listeACopier.m_nombreDElements)
	{
		this->m_liste = new int[this->m_capacite];
		for (int i = 0; i < this->m_nombreDElements; i++) {
			this->m_liste[i] = p_listeACopier.m_liste[i];
		}		
	}

	Liste(Liste&& p_listeADeplacer) :
		m_liste(p_listeADeplacer.m_liste),
		m_capacite(p_listeADeplacer.m_capacite),
		m_nombreDElements(p_listeADeplacer.m_nombreDElements)
	{
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

	virtual void ajouter(const TypeElement& p_nombreAAjouter) {
		if (this->m_nombreDElements == this->m_capacite) {
			int* nouvelleListe = new int[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
		this->m_liste[this->m_nombreDElements] = p_nombreAAjouter;
		++ this->m_nombreDElements;	
	};

	virtual void ajouter(TypeElement&& p_nombreAAjouter) {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
		this->m_liste[this->m_nombreDElements] = p_nombreAAjouter;
		++ this->m_nombreDElements;
	};

	virtual void ajouterFin(const TypeElement& p_element) {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
		this->m_liste[this->m_nombreDElements] = p_element;
		++ this->m_nombreDElements;
	}

	virtual void ajouterDebut(const TypeElement& p_element) {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (size_t i = this->m_nombreDElements; i > 0; --i) {
				nouvelleListe[i] = this->m_liste[i - 1];
			}
			nouvelleListe[0] = p_element;
		}
		else {
			for (size_t i = this->m_nombreDElements; i > 0; --i) {
				this->m_liste[i] = this->m_liste[i - 1];
			}
			this->m_liste[0] = p_element;
		}
	}

	virtual void supprimer(int p_index) {
		if (p_index > this->m_nombreDElements) {
			throw std::invalid_argument("la liste est vide a cet endroit");
		}
		for (int i = p_index; i < this->m_nombreDElements; i++) {
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

	virtual TypeElement obtenir(const int p_index) const {
		if (p_index > this->m_nombreDElements) {
			throw std::invalid_argument("la liste n'a pas de valeur acet emplacement");
		}
		return this->m_liste[p_index];
	};

	virtual void definir(int p_index, TypeElement p_element) {
		if (p_index > this->m_nombreDElements) {
			throw std::invalid_argument("La liste contient deja un element");
		}
		this->m_liste[p_index] = p_element;
	};

	virtual void afficher() {
		std::string affiche = "Liste des elements : \n";
		for (int i = 0; i < this->m_nombreDElements; i++) {
			affiche += std::to_string(this->m_liste[i]) + "\n";
		}
		std::cout << affiche;
	};

	

	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste,TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste1,const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste, TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste1,const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& stream, const Liste<TypeElement>& p_liste);
	template <class TypeElement> friend Liste<TypeElement>& operator== (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend Liste<TypeElement>& operator!= (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);

private:
	int m_nombreDElements;
	TypeElement* m_liste;
	int m_capacite;
};
