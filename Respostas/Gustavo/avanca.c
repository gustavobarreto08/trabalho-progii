#include "avanca.h"
#include <stdlib.h>
#include <stdio.h>

struct Avanca{
    int qtdCasas;
};

Avanca* criaCasaVolta(){
    Avanca *a = malloc(sizeof(struct Avanca));
    if(a == NULL){
        perror("ERRO ALOC VOLTA\n");
        exit(1);
    }
    return a;
}

int ExecutaAvanca(Avanca *a, Jogador *j){
    return a->qtdCasas;
}

void ImprimeAvanca(Avanca *a){
    printf("AVANCA %d", a->qtdCasas);
}

void DesalocaAvanca(Avanca *a){
    free(a);
}