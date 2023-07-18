#pragma once
#include <string>
#include "file.h"

template<class TypeElement>
File<TypeElement> operator+ (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste + p_file2.m_liste;
};

template<class TypeElement>
File<TypeElement> operator+= (const File<TypeElement>& p_file1, File<TypeElement>& p_file2) {
	p_file2.m_liste += p_file1.m_liste;
	return p_file2;
}

template<class TypeElement>
File<TypeElement> operator== (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste == p_file2.m_liste;
}

template<class TypeElement>
File<TypeElement> operator!= (const File<TypeElement>& p_file1, const File<TypeElement>& p_file2) {
	return p_file1.m_liste != p_file2.m_liste;
}