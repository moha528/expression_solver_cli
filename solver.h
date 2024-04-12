#include <stdio.h>
#include <stdlib.h>

#ifndef SOLVER_H
#define SOLVER_H

char c;

int reconnaitreExpression();

int estCaractereBlanc(char c){
    return c == ' ' || c == '\n' || c == '\t';
}

void lecture() {
    do{
        c = getchar();
    } while (estCaractereBlanc(c));
}

void erreurSyntaxe() {
    printf("Erreur de syntaxe\n");
    exit(1);
}

int reconnaitreOperateurMultiplicatif(){
    return c == '*' || c == '/';
}

int reconnaitreOperateurAdditif(){
    return c == '+' || c == '-';
}

int reconnaitreChiffre(){
    return c >= '0' && c <= '9';
}

int reconnaitreNombre() {
    if (reconnaitreChiffre()) {
        lecture();
        return reconnaitreChiffre() ? reconnaitreNombre() : 1;
    } else {
        return 0;
    }
}

int reconnaitreFacteur() {
    if (reconnaitreChiffre()) {
        return reconnaitreNombre();
    } else if (c == '(') {
        lecture();
        reconnaitreExpression();
        if (c != ')') {
            erreurSyntaxe();
        }
        lecture();
        return 1;
    } else {
        erreurSyntaxe();
    }
}

int reconnaitreTerme() {
    if (!reconnaitreFacteur())
        return 0;

    if (reconnaitreOperateurMultiplicatif()) {
        lecture();
        return reconnaitreTerme();
    }

    return 1;
}

int reconnaitreExpression() {
    if(!reconnaitreTerme())
        return 0;

    if (reconnaitreOperateurAdditif()) {
        lecture();
        return reconnaitreExpression();
    }

    return 1;
}

#endif
