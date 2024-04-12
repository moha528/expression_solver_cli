#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

//cette variable globale va representer le symbole courant que l'on a lu
//!IMPORTANT: la valeur de c est le premier caractère non encore examiné
extern char c;

//variable globale pour la gestion d'erreur
//peut eventuelllement servir a determiner la nature de l'erreur au besoin
extern int e;

int estCaractereBlanc(char c);

//!IMPORTANT: ignore les espaces
void lecture(); // Fonction pour lire le prochain symbole

void erreurSyntaxe(); // Cette fonction affiche une erreur et termine le programme

int reconnaitreOperateurMultiplicatif(); // cette fonction verifie qu'un caractere est bien un operateur multiplicatif

int reconnaitreOperateurAdditif(); // cette fonction verifie qu'un caractere est bien un operateur additif

int reconnaitreChiffre(); // cette fonction verifie qu'un caractere est bien un operateur additif

int reconnaitreNombre(int value); // cette fonction verifie qu'une chaine est bien un nombre

int reconnaitreFacteur(); // cette fonction verifie qu'une chaine est bien un facteur

int reconnaitreTerme(); // cette fonction verifie qu'une chaine est bien un terme

int reconnaitreExpression(); // cette fonction verifie qu'une chaine est bien une expression

void flushInputBuffer() {
    int character;
    while ((character = getchar()) != '\n' && character != EOF);
}


int main() {
    while(1){
        printf("A toi : ");
        lecture();
        if(c == '.') {
            printf("Au revoir...\n");
            exit(0);
        }
        int result = reconnaitreExpression();
        if ( c == '=' && e == 0) {
            printf("la syntaxe de l'expression est correcte\n"
                   "sa valeur est : %d\n", result);
        } else {
            erreurSyntaxe();
        }
        flushInputBuffer();
    }
    return 0;
}