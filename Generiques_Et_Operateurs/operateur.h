#pragma once
#include <string>
#include "liste.h"


template< class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_liste, TypeElement p_element)
{
    Liste<TypeElement> liste(p_liste);
    liste.ajouter(p_element);
    return liste;
}

template< class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_liste, TypeElement p_element)
{
    p_liste.ajouter(p_element);
    return p_liste;
}

template< class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2)
{
    int capacite = p_liste1.m_nombreDElements + p_liste2.m_nombreDElements;
    if (capacite == 0) {
        capacite = 1;
    }
    Liste<TypeElement> nouvelleListe(capacite);
    for (size_t i = 0; i < p_liste1.m_nombreDElements; ++i)
    {
        nouvelleListe.ajouter(p_liste1.m_liste[i]);
    }
    for (size_t i = 0; i < p_liste2.m_nombreDElements; ++i)
    {
        nouvelleListe.ajouter(p_liste2.m_liste[i]);
    }
    return nouvelleListe;
}

template< class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2)
{
    for (size_t i = 0; i < p_liste2.m_nombreDElements; ++i)
    {
        p_liste1.ajouter(p_liste2.m_liste[i]);
    }
    return p_liste1;
}