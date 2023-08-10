#include <iostream>
#include <string>
#include "liste.h"
#include "operateur.h"
#include "file.h"
#include "file_operateurs.h"
#include "pile.h"
#include "pile_operateurs.h"
#include "pile_methodes.h"
#include "liste_methodes.h"

void liste();
void pileChar();
void file();
void pilePostfixe();
void recherche();

int main()
{
    std::cout << "**********************   RECHERCHE   *******************" << std::endl;
    //recherche();

    //std::cout << "********************   LISTE   *********************" << std::endl;
    liste(); 
     

   std::cout << "********************   PILE   *********************" << std::endl;
    //pileChar();

    std::cout << "*******************   POSTFIXE   *****************" << std::endl;
    //pilePostfixe();

    //std::cout << "********************   FILE   *********************" << std::endl;
    //file();
}
void pilePostfixe() {
    std::string infixe = "(1+2)*3-4*5";
    Pile<char>postfixe(infixe.length());
    Pile<char>postfixe2(infixeConvertiEnPostfixe(infixe));
    std::cout << "postfixe: " << postfixe2 << std::endl;
}

void pileChar() {
    Pile<int> pile;
    Pile<char>pileChar;
    pileChar.empiler('(');
    pileChar.empiler(')');
    std::string listeChar = pileChar.pileToString();
    std::string string = "()";
    bool bienImbriques = caracteresCorrectementImbriques(listeChar);
    if (bienImbriques) {
        std::cout << "les caracteres sont bien imbriques" << std::endl;
    }
    if (!bienImbriques) {
        std::cout << "Les caracteres ne sont pas imbriques correctement" << std::endl;
    }
    std::cout << "bool bien imbriques: " << bienImbriques;

    std::cout << "pile.empiler(1)" << std::endl;
    pile.empiler(1);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout << std::endl;
    std::cout << "pile: " << pile;

    std::cout << "pile.empiler(2)" << std::endl;
    pile.empiler(2);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout << std::endl;

    std::cout << "pile.empiler(3)" << std::endl;
    pile.empiler(3);
    std::cout << "Taille de la pile : " << pile.taille() << std::endl;
    std::cout <<std::endl;
    std::cout << "pile: " << pile << std::endl;;

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
    std::cout << file;
    file.enfiler(2);
    file.enfiler(3);

    File<int> fileInversee = ~file;
    std::cout << "file:" << file;
    std::cout << "Liste inversee avec ~ :" << std::endl;
    std::cout << fileInversee;

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
        liste.ajouterFin(i);
    }
    std::cout << "liste de depart: " << std::endl;
    std::cout << liste.toString() << std::endl;
    Liste<int>listeCopiee(liste);
    std::cout << "liste copiee: " << std::endl;
    std::cout << liste.toString()<<std::endl;

    Liste<int> listeTest = liste + 6;
    listeTest + 7;
    std::cout << "operateur + avec liste + 5 et liste + 6: " << std::endl;
    std::cout << listeTest.toString();

   /* ~listeTest;
    std::cout << "tilde: " << listeTest << std::endl;*/

    liste += 8;
    liste += 9;
    std::cout << "operateur += avec liste+=8 et liste+=9 " << std::endl;
    //liste.afficher();

    Liste<int> liste2;
    for (int i = 0; i < 5; ++i) {
        liste2.ajouterFin(i);
    }
    Liste<int> liste3;
    std::cout << "premiere liste: " << std::endl;
    //liste2.afficher();

    for (int i = 5; i < 10; ++i) {
        liste3.ajouterFin(i);
    }
    Liste<int> listeTest2 = liste2 + liste3;
    std::cout << "deuxieme liste: " << std::endl;
    //liste3.afficher();

    std::cout << "concatenation avec operateur + avec liste1 + liste2 : " << std::endl;
    //listeTest2.afficher();

    Liste<int> liste5;
    for (int i = 10; i <= 15; ++i)
    {
        liste5.ajouterFin(i);
    }
    Liste<int> liste6;
    for (int i = 16; i <= 20; ++i)
    {
        liste6.ajouterFin(i);
    }
    std::cout << "liste 5: " << std::endl;
    //liste5.afficher();
    std::cout << "liste 6: " << std::endl;
    //liste6.afficher();
    //liste5 += liste6;
    std::cout << "liste5 += liste6 :" << std::endl;
    //liste5.afficher();
    Liste<int> essai;
    essai.ajouterFin(11);
    essai.ajouterFin(22);
    essai.ajouterFin(33);
    essai.ajouterFin(44);
    essai.ajouterFin(55);

    std::cout << essai << std::endl;

}
void heritage() {
    Liste<int> liste;
    collection<int>& c = liste;
    c.ajouterFin(2);
    c.ajouterFin(3);
    c.ajouterFin(4);
    c.ajouterFin(5);
    c.ajouterFin(6);
    //liste.afficher();
}

void recherche() {
    Liste<int> tableauATrier;
    for (int i = 1; i <= 10; ++i) {
        tableauATrier.ajouterFin(i);
    }
    int taille = tableauATrier.nombreDElement();
    Liste<int>* resultat = tableauATrier.filtrer( taille, [](int v) { return v % 2 == 0; });
    std::cout << "liste filtree: " << std::endl;
    std::cout<<resultat->toString() << std::endl;
}