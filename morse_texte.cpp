#include <iostream>
#include "morse_texte.h"
#include "Dictionnaire.h"
#include <string>
#include <cstring>


using namespace std;

morse_texte_to_texte::morse_texte_to_texte() : indice(0) {};

int morse_texte_to_texte::nombre_espaces(int i, int taille, string texte){
    int compte = 0;
    int ind = i; 
    while ((ind < taille) && (texte[ind] == ' ')){ 
    compte ++;
    ind ++;
    }
    return compte;
}

int morse_texte_to_texte::indice_fin_mot(int i, int taille, string texte){ 
    int k = i; 
    while ((k < taille) && (morse_texte_to_texte::nombre_espaces(k, taille, texte) < 2)){
        k++;
    }
    return k-1;
}

int morse_texte_to_texte::indice_fin_lettre(int i, int taille, string texte){
    int k = i; 
    while ((k < taille) && (!(texte[k] == ' '))){
        k++;
    }
    return k-1;
}

char* morse_texte_to_texte::mot_to_texte(int i, int taille, string texte){ // la fonction modifie aussi "indice" :  à la fin indice = fin du mot + 1 ATTENTION MODIF GLOBALE ?
    int l = i;
    int fin = morse_texte_to_texte::indice_fin_mot(i, taille, texte);
    int indice_mot = 0;
    char* mot = new char[fin - i + 1];
    while (l <= fin){
        int fin_lettre = morse_texte_to_texte::indice_fin_lettre(l, taille, texte);
        mot[indice_mot] = dico_mtt(texte.substr(l, fin_lettre - l + 1));
        l = fin_lettre + morse_texte_to_texte::nombre_espaces(fin_lettre + 1, taille, texte) + 1; // sauter les espaces
        indice_mot ++;
    }
    //slicing pour avoir seulement le mot
    char* mot_final = new char[indice_mot];
    for (int r = 0; r < indice_mot; r ++){
        mot_final[r] = mot[r];
    }
    indice = fin + 1;
    return mot_final;
    }

char* morse_texte_to_texte::conversion(string t){
    char* texte_fr = new char [100];
    int indice_fr = 0;
    int taille = t.length();
    while (indice < taille){ 
        if ((t[indice] == ' ') && (morse_texte_to_texte::nombre_espaces(indice, taille, t) > 1)) { 
            texte_fr[indice_fr] = ' ';
            indice_fr ++;
            indice += morse_texte_to_texte::nombre_espaces(indice, taille, t);
        }
        else if(t[indice] == ' '){
            indice ++;
        }
        else{
            char* mot = morse_texte_to_texte::mot_to_texte(indice, taille, t);
            int longueur = strlen(mot);
            for (int r = 0; r < longueur; r++){
                texte_fr[r + indice_fr] = mot[r];
            }
            indice_fr += longueur;
        }
    }
    char* resultat = new char [indice_fr + 1]; // pas indice_fr - 1 car indice_fr = taille du mot
    for (int s = 0; s < indice_fr; s ++){
        resultat[s] = texte_fr[s];
    }
    indice = 0; // indice remis à 0 : on est à prêts à traduire un nouveau texte.
    return resultat;
}