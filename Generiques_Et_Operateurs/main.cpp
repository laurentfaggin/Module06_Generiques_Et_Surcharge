
#include <iostream>
#include "liste.h"
#include "operateur.h"
#include "pile.h"
#include "file.h"

void liste();
void pile();
void file();

int main()
{
    std::cout << "********************   LISTE   *********************" << std::endl;
    //liste();

    std::cout << "********************   PILE   *********************" << std::endl;
    pile();

    std::cout << "********************   FILE   *********************" << std::endl;
    file();
}

void pile() {
    Pile<int> pile;
    std::cout << "pile.empiler(1)" << std::endl;
    pile.empiler(1);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout << std::endl;

    std::cout << "pile.empiler(2)" << std::endl;
    pile.empiler(2);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout << std::endl;

    std::cout << "pile.empiler(3)" << std::endl;
    pile.empiler(3);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout <<std::endl;

    std::cout << "pile.depiler()" << std::endl;
    int valeurDepilee = pile.depiler();
    std::cout << "valeur depile = " << valeurDepilee << std::endl;
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout << std::endl;

}

void file() {
    File<int> file;

    std::cout << "pile.enfiler(1)" << std::endl;
    file.enfiler(1);
    std::cout << "Taille de la file : " << file.taille() << std::endl;
    std::cout << std::endl;

    std::cout << "pile.enfiler(2)" << std::endl;
    file.enfiler(2);
    std::cout << "Taille de la file : " << file.taille() << std::endl;
    std::cout << std::endl;

    std::cout << "pile.enfiler(3)" << std::endl;
    file.enfiler(3);
    std::cout << "Taille de la file : " << file.taille() << std::endl;
}

void liste() {

    Liste <int> liste;
    for (int i = 1; i < 6; i++) {
        liste.ajouter(i);
    }
    std::cout << "liste de depart: " << std::endl;
    liste.afficher();
    Liste<int> listeTest = liste + 6;
    listeTest + 7;
    std::cout <<"operateur + avec liste + 5 et liste + 6: "<< std::endl;
    listeTest.afficher();

    liste += 8;
    liste += 9;
    std::cout << "operateur += avec liste+=8 et liste+=9 "<< std::endl;
    liste.afficher();

    Liste<int> liste2;
    for (int i = 0; i < 5; ++i) {
        liste2.ajouter(i);
    }
    Liste<int> liste3;
    std::cout << "premiere liste: "<< std::endl;
    liste2.afficher();

    for (int i = 5; i < 10; ++i) {
        liste3.ajouter(i);
    }
    Liste<int> listeTest2 = liste2 + liste3;
    std::cout << "deuxieme liste: "<< std::endl;
    liste3.afficher();

    std::cout << "concatenation avec operateur + avec liste1 + liste2 : "<< std::endl;
    listeTest2.afficher();
   
    Liste<int> liste5;
    for (int i = 10; i <= 15; ++i) 
    {
        liste5.ajouter(i);
    }
    Liste<int> liste6;
    for (int i = 16; i <= 20; ++i)
    {
        liste6.ajouter(i);
    }
    std::cout << "liste 5: "<< std::endl;
    liste5.afficher();
    std::cout << "liste 6: "<< std::endl;
    liste6.afficher();
    liste5 += liste6;
    std::cout << "liste5 += liste6 :"<< std::endl;
    liste5.afficher();

}
void heritage() {
    Liste<int> liste;
    collection<int>& c = liste;
    c.ajouter(2);
    c.ajouter(3);
    c.ajouter(4);
    c.ajouter(5);
    c.ajouter(6);
    liste.afficher();

}