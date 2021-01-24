#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath> 
#include "wave.h"
#define PI 3.141592

using namespace std;


void wave_sinus::ecrire_little_endian(int octets, unsigned int taille, FILE *fichier){ //  écriture en binaire dans le fichier
    char faible;
    while (taille > 0){
        faible = octets & 0x000000FF;
        fwrite(&faible, 1, 1, fichier);
        octets = octets >> 8;
        taille = taille - 1;
    }
}

void wave_sinus::ecrire_entete(unsigned int temps, unsigned int frequence, int nb_canaux, FILE* fichier){

    unsigned int nb_bits = 16;
    unsigned int taille_fichier_octets = frequence * temps * nb_canaux * (nb_bits/8);
    unsigned int taille = frequence * temps;

    if(!fichier) {
        perror("Problème d'ouverture"); // perror vient de la bibliotèque standard
    }

    fwrite("RIFF", 4, 1, fichier);
    wave_sinus::ecrire_little_endian(36 + taille_fichier_octets, 4, fichier);
    fwrite("WAVE",4,1,fichier);
    fwrite("fmt ", 4, 1, fichier);
    wave_sinus::ecrire_little_endian(16, 4, fichier);
    wave_sinus::ecrire_little_endian(1, 2, fichier);
    wave_sinus::ecrire_little_endian(nb_canaux, 2, fichier);
    wave_sinus::ecrire_little_endian(frequence, 4, fichier);
    wave_sinus::ecrire_little_endian(frequence * nb_canaux * (nb_bits / 8), 4, fichier);
    wave_sinus::ecrire_little_endian(nb_canaux * (nb_bits / 8), 2, fichier);
    wave_sinus::ecrire_little_endian(nb_bits, 2, fichier);

    fwrite("data", 4, 1, fichier);
    wave_sinus::ecrire_little_endian(taille * nb_canaux * (nb_bits / 8), 4, fichier);

}

void wave_sinus::ecrire_sinus(unsigned int temps, unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier){
    unsigned int taille = frequence * temps;


    double* gauche = wave_sinus::creer_tableau_sinus(taille,f_son,frequence);
    double* droite = wave_sinus::creer_tableau_sinus(taille,f_son,frequence);

    // Normalisation
    double maxi = wave_sinus::valeur_max(fichier, gauche, droite, taille, amplitude);
    for (unsigned int i = 0; i < taille; i ++) {
    ecrire_little_endian((int)(gauche[i]/maxi*amplitude), 2, fichier) ;
    ecrire_little_endian((int)(droite[i]/maxi*amplitude), 2, fichier) ;
    }
}

double wave_sinus::valeur_max(FILE* fichier, double* gauche, double* droite, unsigned int taille, double amplitude){ // fonction pour normaliser les tableaux gauche et droite
    unsigned int i ;
    double maxi = 1e-16 ; 
    for (i = 0 ; i < taille ; i=i+1) {
    if (fabs(gauche[i]) > maxi) maxi = fabs(gauche[i]) ;
    if (fabs(droite[i]) > maxi) maxi = fabs(droite[i]) ;
    }
    return maxi;
}

double* wave_sinus::creer_tableau_sinus(unsigned int taille, unsigned int f, unsigned int frequence){ // crée le son
    double* tableau = (double*) calloc(taille, sizeof(double));
    for (unsigned int i = 0; i < taille; i++){
        tableau[i] = sin((2*PI*f*i)/frequence);
    }
    return tableau;
}