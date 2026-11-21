#include "acao_ouro.h"
#include <stdlib.h>
#include <stdio.h>

struct Ouro{
    int qtdOuro;
};

Ouro* criaOuro(int qtdOuro){
    Ouro *o = malloc(sizeof(struct Ouro));
    if(o == NULL){
        perror("ERRO ALOC OURO\n");
        exit(1);
    }
    o->qtdOuro = qtdOuro;
    return o;
}

Ouro* LeOuro(){
    int qtdOuro = 0;
    scanf("%d", &qtdOuro);
    Ouro *o = criaOuro(qtdOuro);
    return o;
}

int ExecutaOuro(void *dado, Jogador *j){
    Ouro *o = (Ouro*) dado;
    adicionaOuroJogador(j,o->qtdOuro);
    return 0;
}

void ImprimeOuro(void *dado){
    Ouro *o = (Ouro*) dado;
    printf("OURO %d", o->qtdOuro);
}

void DesalocaOuro(void *dado){
    Ouro *o = (Ouro*) dado;
    free(o);
}