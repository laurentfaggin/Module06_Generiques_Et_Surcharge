#pragma once
#include <string>
template< class TypeElement> 
class collection {
public:
	virtual void afficher() = 0;
	virtual void ajouter(TypeElement& p_element) = 0;
	virtual void ajouter(TypeElement&& p_element) = 0;
	virtual void supprimer(int p_index) = 0;
	virtual TypeElement obtenir(int p_index) = 0;
	virtual void definir(int p_index, TypeElement& p_element) = 0;

};
