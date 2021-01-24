#include <string>
class morse_texte_to_texte{
  public :
    morse_texte_to_texte();
    int indice;
    int nombre_espaces(int i, int taille, std::string texte); 
    char* conversion(std::string t);
    int indice_fin_mot(int i, int taille, std::string texte);
    int indice_fin_lettre(int i, int taille, std::string texte);
    char* mot_to_texte(int indice, int taille, std::string texte);
};