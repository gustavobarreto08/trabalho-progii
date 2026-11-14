#include "ouro.h"
#include <stdlib.h>
#include <stdio.h>

struct Ouro{
    int qtdOuro;
};

Ouro* criaOuro(){
    Ouro *o = malloc(sizeof(struct Ouro));
    if(o == NULL){
        perror("ERRO ALOC OURO\n");
        exit(1);
    }
    return o;
}

int ExecutaOuro(Ouro *o, Jogador *j){
    adicionaOuroJogador(j,o->qtdOuro);
    return 0;
}

void ImprimeOuro(Ouro *o){
    printf("OURO");
}

void DesalocaOuro(Ouro *o){
    free(o);
}