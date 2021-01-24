#include <iostream>
#include "texte_morse.h"
#include "Dictionnaire.h"
#include <string>
#include <cstring>

using namespace std;

string texte_to_morse::lettre_to_morse(char ch)
{
    return dico_ttm(ch);
}

string texte_to_morse::construction(string texte)
{
    int taille = texte.length();
    int indice_fr = 0;
    string texte_m;
    while (indice_fr < taille){
        if (texte[indice_fr] == ' '){
            texte_m.append(" ");  // espace entre les mots
        }
        else {
            texte_m.append(texte_to_morse::lettre_to_morse(texte[indice_fr]));
            texte_m.append(" "); //espace entre les lettres
        }
        indice_fr ++;
    }
    return texte_m;
}