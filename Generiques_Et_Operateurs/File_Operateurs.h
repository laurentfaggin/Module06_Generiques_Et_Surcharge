#pragma once
#include <string>
#include "file.h"
#include "liste.h"

template<class TypeElement>
File<TypeElement> operator+ (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste + p_file2.m_liste;
};

template<class TypeElement>
File<TypeElement> operator+= (File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	for (size_t i = 0; i < p_file2.m_nombreDElements; ++i) {
		p_file1.enfiler(p_file2.m_liste.obtenir(i));
	}
	return p_file1;
}


template<class TypeElement>
bool operator== (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste == p_file2.m_liste;
}

template<class TypeElement>
bool operator!= (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste != p_file2.m_liste;
}
//File<TypeElement> operator~(const File<TypeElement>& p_file);

template<class TypeElement>
File<TypeElement> operator~ (const File<TypeElement>& p_file) {
	File<TypeElement>nouvelleFile(p_file.m_liste.nombreDElement());
	for (size_t i = 0; i < p_file.m_liste.nombreDElement() / 2; ++i) {
		nouvelleFile.enfiler(p_file.m_liste.obtenir(i));
	}
	return nouvelleFile;
};

//std::ostream& operator<<(std::ostream& stream, const File<TypeElement>& p_file);

template<class TypeElement>
std::ostream& operator<<(std::ostream& stream, const File<TypeElement>& p_file) {
	stream << p_file.m_liste;
	return stream;
}