#include "acao_avanca.h"
#include <stdlib.h>
#include <stdio.h>

struct Avanca{
    int qtdCasas;
};

Avanca* criaCasaAvanca(int qtdCasas){
    Avanca *a = malloc(sizeof(struct Avanca));
    if(a == NULL){
        perror("ERRO ALOC AVANCA\n");
        exit(1);
    }
    a->qtdCasas = qtdCasas;
    return a;
}

Avanca* LeCasaAvanca(){
    int qtdCasas = 0;
    scanf("%d", &qtdCasas);
    Avanca *a = criaCasaAvanca(qtdCasas);
    return a;
}

int ExecutaAvanca(void *dado, Jogador *j){
    Avanca *a = (Avanca*) dado;
    return a->qtdCasas;
}

void ImprimeAvanca(void *dado){
    Avanca *a = (Avanca*) dado;
    printf("AVANCA %d", a->qtdCasas);
}

void DesalocaAvanca(void *dado){
    Avanca *a = (Avanca*) dado;
    free(a);
}