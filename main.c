#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

//cette variable globale va representer le symbole courant que l'on a lu
//!IMPORTANT: la valeur de calu est le premier caractère non encore examiné
extern char c;


int estCaractereBlanc(char c);

//!IMPORTANT: ignore les espaces
void lecture(); // Fonction pour lire le prochain symbole

void erreurSyntaxe(); // Cette fonction affiche une erreur et termine le programme

int reconnaitreOperateurMultiplicatif(); // cette fonction verifie qu'un caractere est bien un operateur multiplicatif

int reconnaitreOperateurAdditif(); // cette fonction verifie qu'un caractere est bien un operateur additif

int reconnaitreChiffre(); // cette fonction verifie qu'un caractere est bien un operateur additif

int reconnaitreNombre(); // cette fonction verifie qu'une chaine est bien un nombre

int reconnaitreFacteur(); // cette fonction verifie qu'une chaine est bien un facteur

int reconnaitreTerme(); // cette fonction verifie qu'une chaine est bien un terme

int reconnaitreExpression(); // cette fonction verifie qu'une chaine est bien une expression


int main() {
    printf("Entrez une expression arithmetique : ");
    lecture();
    reconnaitreExpression();
    if ( c == '=') {
        printf("Syntaxe correcte\n");
    } else {
        erreurSyntaxe();
    }
    return 0;
}