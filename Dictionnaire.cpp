#include <iostream>
#include <map> // de la bibliotèque standard
#include "Dictionnaire.h"

using namespace std; 

map<char, string> texte_to_morse = 
{ 
    {' ', " "},
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H', "...."},
    {'I', ".."},
    {'J', ".---"},
    {'K', "-.-"},
    {'L', ".-.."},
    {'M', "--"},
    {'N', "-."},
    {'O', "---"},
    {'P', ".--."},
    {'Q', "--.-"},
    {'R', ".-."},
    {'S', "..."},
    {'T', "-"},
    {'U', "..-"},
    {'V', "...-"},
    {'W', ".--"},
    {'X', "-..-"},
    {'Y', "-.--"},
    {'Z', "--.."},
};

map<string, char> morse_to_texte = 
{
    {".-",'A'},
    {"-...",'B'},
    {"-.-.",'C'},
    {"-..",'D'},
    {".",'E'},
    {"..-.",'F'},
    {"--.",'G'},
    {"....",'H'},
    {"..",'I'}, 
    {".---",'J'},
    {"-.-",'K'}, 
    {".-..",'L'}, 
    {"--",'M'}, 
    {"-.",'N'}, 
    {"---",'O'}, 
    {".--.",'P'}, 
    {"--.-",'Q'}, 
    {".-.",'R'}, 
    {"...",'S'}, 
    {"-",'T'},
    {"..-",'U'}, 
    {"...-",'V'}, 
    {".--",'W'}, 
    {"-..-",'X'}, 
    {"-.--",'Y'}, 
    {"--..",'Z'}
};

string dico_ttm(char ch){
    // regarder si le char est dans le dico ?
    return texte_to_morse[ch];
}

char dico_mtt(string str){
    return morse_to_texte[str];
}