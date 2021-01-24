#include <iostream>
#include "Dictionnaire.h"
#include "morse_texte.h"
#include "texte_morse.h"

using namespace std;


int main(){
    string choix;
    cout << "Déchiffrer un texte morse : rentrer 0" << endl;
    cout << "Déchiffrer un texte en francais : rentrer 1" << endl;
    getline(cin, choix);
    if (choix[0] == '0'){
        string texte;
        cout << "Rentrer le texte morse : ";
        getline(cin,texte);
        morse_texte_to_texte trad;
        cout<< trad.conversion(texte) << endl;
    }
    if (choix[0] == '1'){
        string txt;
        cout << "Rentrer le texte en majuscules : ";
        getline(cin,txt);
        texte_to_morse trad;
        cout << trad.construction(txt);}
    return 0;
}