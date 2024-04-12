#ifndef SOLVER_H
#define SOLVER_H
#include <stdio.h>
#include <stdlib.h>

char c;
int e = 0;

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
    printf("La syntaxe de l'expression est erronee\n");
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

int valeurChiffre() {
    return c - '0';
}

int reconnaitreNombre(int value) {
    if (reconnaitreChiffre()) {
        value = value * 10 + valeurChiffre();
        lecture();
        return reconnaitreChiffre() ? reconnaitreNombre(value) : value;
    } else {
        return value;
    }
}

int reconnaitreFacteur() {
    int result = 0;
    if (reconnaitreChiffre()) {
        result = reconnaitreNombre(0);
    } else if (c == '(') {
        lecture();
        result = reconnaitreExpression();
        if (c != ')') {
            e = 1;
        }
        lecture();
    } else {
        e = 1;
    }
    return result;
}

int reconnaitreTerme() {
    int result = reconnaitreFacteur();

    if (reconnaitreOperateurMultiplicatif()) {
        char operation = c;
        lecture();
        int membre = reconnaitreTerme();
//        printf("test : %d %c %d\n",result,operation,membre);
        if(operation == '*')
            result *= membre;
        else {
            if(membre == 0){
                e=1;
                return 0;
            }
            result /= membre;
        }
    }

    return result;
}

int reconnaitreExpression() {
    int result = reconnaitreTerme();
    if (reconnaitreOperateurAdditif()) {
        char operation = c;
        lecture();
        int membre = reconnaitreExpression();
//        printf("test : %d %c %d\n",result,operation,membre);
        if(operation == '+')
            result += membre;
        else
            result -= membre;
    }
    return result;
}

#endif
